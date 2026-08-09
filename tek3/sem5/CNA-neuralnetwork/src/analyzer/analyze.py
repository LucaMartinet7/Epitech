import sys
from .network import NetworkManager
from .data_parser import DatasetParser
from .trainer import Trainer
from .predict import Predictor

class NeuralNetworkAnalyzer:
    """
    Main class for running the neural network analyzer.
    """
    def __init__(self, args):
        """
        Initializes the analyzer with command-line arguments.

        Args:
            args (list): List of command-line arguments.
        """
        self.args = args
        self.mode = None
        self.save_path = None
        self.load_path = None
        self.dataset_path = None
        self.fen_path = None

    def execute(self):
        """
        Executes the analyzer based on the specified mode.
        """
        self._parse_flags()
        network = self._load_network()
        if self.mode == 'train':
            self._train_mode(network)
        elif self.mode == 'predict':
            self._predict_mode(network)

    def _parse_flags(self):
        """
        Parses command-line flags to determine the mode and file paths.
        """
        if '--help' in self.args:
            self._helper(0)
        if '--train' in self.args:
            self.mode = 'train'
            self._parse_train_args()
        elif '--predict' in self.args:
            self.mode = 'predict'
            self._parse_predict_args()
        else:
            print("Error: must specify --train or --predict", file=sys.stderr)
            self._helper(84)

    def _load_network(self):
        """
        Loads the neural network from the specified load file.

        Returns:
            object: Loaded neural network.
        """
        if not self.load_path:
            print(f"Error: LOADFILE must be specified for {self.mode}.", file=sys.stderr)
            self._helper(84)
        return NetworkManager.load_network(self.load_path)

    def _train_mode(self, network):
        """
        Handles the training mode of the analyzer.

        Args:
            network (object): Neural network to be trained.
        """
        inputs, outputs = self._load_dataset()
        self._train(network, inputs, outputs)
        self._save(network)
        sys.exit(0)

    def _predict_mode(self, network):
        """
        Handles the prediction mode of the analyzer.

        Args:
            network (object): Neural network to be used for prediction.
        """
        predictor = Predictor(network)
        predictor.predict_file(self.fen_path)
        sys.exit(0)

    def _parse_train_args(self):
        """
        Parses arguments specific to the training mode.
        """
        self.load_path, self.dataset_path = self._get_args_after('--train', 2)
        self.save_path = self._get_optional_arg('--save')

    def _parse_predict_args(self):
        """
        Parses arguments specific to the prediction mode.
        """
        self.load_path, self.fen_path = self._get_args_after('--predict', 2)

    def _get_args_after(self, flag, count):
        """
        Retrieves arguments following a specific flag.

        Args:
            flag (str): The flag to search for.
            count (int): Number of arguments to retrieve after the flag.

        Returns:
            list: List of arguments following the flag.
        """
        try:
            idx = self.args.index(flag)
            return self.args[idx + 1: idx + 1 + count]
        except (ValueError, IndexError):
            print(f"Error: insufficient arguments for {flag[2:]}", file=sys.stderr)
            self._helper(84)

    def _get_optional_arg(self, flag):
        """
        Retrieves an optional argument following a specific flag.

        Args:
            flag (str): The flag to search for.

        Returns:
            str: The argument following the flag, or None if not found.
        """
        if flag in self.args:
            try:
                idx = self.args.index(flag)
                return self.args[idx + 1]
            except (ValueError, IndexError):
                print(f"Error: no {flag[2:].upper()} specified", file=sys.stderr)
                self._helper(84)
        return None

    def _load_dataset(self):
        """
        Loads the dataset file into features and labels.

        Returns:
            tuple: Arrays of features and labels.
        """
        parser = DatasetParser(self.dataset_path)
        return parser.parse()

    def _train(self, network, inputs, outputs):
        """
        Trains the neural network with the given data.

        Args:
            network (object): Neural network to be trained.
            inputs (np.ndarray): Feature data.
            outputs (np.ndarray): Labels.
        """
        trainer = Trainer(network)
        trainer.train(inputs, outputs, epochs=network.epochs, batch_size=64)

    def _save(self, network):
        """
        Saves the trained neural network to a file.

        Args:
            network (object): Trained neural network.
        """
        save_path = self.save_path if self.save_path else self.load_path
        network.save_network(save_path)
        print(f"Network saved to {save_path}")

    def _helper(self, code=84):
        """
        Prints the usage information and exits the program.

        Args:
            code (int): Exit code.
        """
        stream = sys.stderr if code == 84 else sys.stdout
        print("""USAGE
./my_torch_analyzer [--predict | --train [--save SAVEFILE]] LOADFILE FILE

DESCRIPTION
    --train Launch the neural network in training mode. Each chessboard in FILE must
contain inputs to send to the neural network in FEN notation and the expected output
separated by space. If specified, the newly trained neural network will be saved in
SAVEFILE. Otherwise, it will be saved in the original LOADFILE.
    --predict Launch the neural network in prediction mode. Each chessboard in FILE
must contain inputs to send to the neural network in FEN notation, and optionally an
expected output.
    --save Save neural network into SAVEFILE. Only works in train mode.

    LOADFILE File containing an artificial neural network
    FILE File containing chessboards""", file=stream)
        sys.exit(code)