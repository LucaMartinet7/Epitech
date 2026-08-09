import sys
from .parser import Parser
from .network import NetworkManager

class Generator:
    def __init__(self, argv):
        """
        Initializes the Generator with command line arguments.

        Args:
            argv (List[str]): List of command line arguments.
        """
        self.argv = argv

    def run(self):
        """
        Runs the generator process by validating and processing arguments.
        """
        if '--help' in self.argv:
            self.print_usage(0)
        self.validate_arguments()
        self.process_arguments()

    def validate_arguments(self):
        """
        Validates the command line arguments.

        Raises:
            SystemExit: If the arguments are invalid, exits the program with code 84.
        """
        if len(self.argv) < 3 or (len(self.argv) - 1) % 2 != 0:
            self.print_usage(84)

    def print_usage(self, code):
        """
        Prints the usage information and exits the program.

        Args:
            code (int): Exit code. If 84, prints to stderr; otherwise, prints to stdout.
        """
        stream = sys.stderr if code == 84 else sys.stdout
        print("""USAGE
    ./my_torch_generator config_file_1 nb_1 [config_file_2 nb_2...]

DESCRIPTION
    config_file_i Configuration file containing description of a neural network we want to generate.
    nb_i Number of neural networks to generate based on the configuration file.
              """, file=stream)
        sys.exit(code)

    def process_arguments(self):
        """
        Processes the command line arguments and generates networks accordingly.
        """
        args = self.argv[1:]
        for i in range(0, len(args), 2):
            config_file = args[i]
            nb = self.parse_number(args[i + 1])
            self.generate_networks(config_file, nb)
        sys.exit(0)

    def parse_number(self, number_str):
        """
        Parses a string to an integer and validates it.

        Args:
            number_str (str): The string to parse.

        Returns:
            int: The parsed integer.

        Raises:
            SystemExit: If the number is invalid, exits the program with code 84.
        """
        try:
            nb = int(number_str)
            if nb <= 0:
                raise ValueError("Number must be greater than 0")
            return nb
        except ValueError as e:
            self.handle_error(f"Error: {e}")

    def handle_error(self, message):
        """
        Handles errors by printing a message and exiting the program.

        Args:
            message (str): The error message to print.
        """
        print(message, file=sys.stderr)
        self.print_usage(84)

    def generate_networks(self, config_file, nb):
        """
        Generates the specified number of networks based on the configuration file.

        Args:
            config_file (str): The path to the configuration file.
            nb (int): The number of networks to generate.
        """
        parser = Parser(config_file)
        parser.parse()
        config = parser.get_config()
        manager = NetworkManager(config)

        for j in range(1, nb + 1):
            network = manager.init_network()
            filename = self.generate_filename(config_file, j)
            manager.save_network(filename, network, config)

    def generate_filename(self, config_file, index):
        """
        Generates a filename for the network based on the configuration file and index.

        Args:
            config_file (str): The path to the configuration file.
            index (int): The index of the network.

        Returns:
            str: The generated filename.
        """
        base_name = config_file.split('/')[-1].rsplit('.', 1)[0]
        return f"{base_name}_{index}.nn"