import json
import math
import sys
import numpy as np

class NetworkManager:
    def __init__(self, layer_sizes, learning_rate=0.001, beta1=0.9, beta2=0.999, epsilon=1e-8, l2_lambda=1e-4):
        """
        Initializes the neural network with given parameters.

        Args:
            layer_sizes (list): List of integers representing the number of neurons in each layer.
            learning_rate (float): Learning rate for the optimizer.
            beta1 (float): Exponential decay rate for the first moment estimates in Adam optimizer.
            beta2 (float): Exponential decay rate for the second moment estimates in Adam optimizer.
            epsilon (float): Small constant to prevent division by zero in Adam optimizer.
            l2_lambda (float): L2 regularization parameter.
        """
        self.layer_sizes = layer_sizes
        self.learning_rate = learning_rate
        self.beta1 = beta1
        self.beta2 = beta2
        self.epsilon = epsilon
        self.l2_lambda = l2_lambda
        self.weights, self.biases = self.initialize_weights()
        self.m_w, self.v_w = self.initialize_adam_params(self.weights)
        self.m_b, self.v_b = self.initialize_adam_params(self.biases)
        self.t = 0
        self.num_classes = self.layer_sizes[-1]


    def initialize_weights(self):
        """
        Initializes weights and biases for each layer using He initialization.

        Returns:
            tuple: A tuple containing two lists - weights and biases.
        """
        np.random.seed(42)
        weights, biases = [], []
        for in_neu, out_neu in zip(self.layer_sizes[:-1], self.layer_sizes[1:]):
            std = math.sqrt(2.0 / in_neu)
            weights.append(np.random.normal(0, std, (in_neu, out_neu)).astype(np.float32))
            biases.append(np.zeros(out_neu, dtype=np.float32))
        return weights, biases

    @staticmethod
    def initialize_adam_params(params):
        """
        Initializes Adam optimizer parameters.

        Args:
            params (list): List of parameters (weights or biases).

        Returns:
            tuple: A tuple containing two lists - first moment vectors and second moment vectors.
        """
        return [np.zeros_like(p) for p in params], [np.zeros_like(p) for p in params]

    @staticmethod
    def load_network(filename):
        """
        Loads a neural network from a JSON file.

        Args:
            filename (str): Path to the JSON file.

        Returns:
            NetworkManager: An instance of NetworkManager with loaded parameters.
        """
        data = NetworkManager.load_json_file(filename)
        NetworkManager.validate_network_data(data)
        network = NetworkManager.create_network_from_data(data)
        NetworkManager.load_weights_and_biases(network, data['layers'])
        return network

    @staticmethod
    def load_json_file(filename):
        """
        Loads JSON data from a file.

        Args:
            filename (str): Path to the JSON file.

        Returns:
            dict: Parsed JSON data.
        """
        try:
            with open(filename, 'r') as f:
                return json.load(f)
        except Exception as e:
            print(f"Error: cannot open or parse network file: {e}", file=sys.stderr)
            sys.exit(84)

    @staticmethod
    def validate_network_data(data):
        """
        Validates the structure of the loaded network data.

        Args:
            data (dict): Loaded network data.

        Raises:
            SystemExit: If the data is invalid.
        """
        required_keys = {'input_neurons', 'output_neurons', 'hidden_neurons_list', 'learning_rate', 'epochs', 'layers'}
        if not required_keys.issubset(data.keys()):
            print("Error: invalid network file format", file=sys.stderr)
            sys.exit(84)

    @staticmethod
    def create_network_from_data(data):
        """
        Creates a NetworkManager instance from loaded data.

        Args:
            data (dict): Loaded network data.

        Returns:
            NetworkManager: An instance of NetworkManager.
        """
        layer_sizes = [int(data['input_neurons'])] + [int(x) for x in data['hidden_neurons_list']] + [int(data['output_neurons'])]
        network = NetworkManager(layer_sizes, float(data['learning_rate']))
        network.epochs = int(data['epochs'])
        return network

    @staticmethod
    def load_weights_and_biases(network, layers):
        """
        Loads weights and biases into the network.

        Args:
            network (NetworkManager): An instance of NetworkManager.
            layers (list): List of layers containing weights and biases.

        Raises:
            SystemExit: If there is a shape mismatch.
        """
        if len(layers) != len(network.weights):
            print("Error: layer count mismatch in network file.", file=sys.stderr)
            sys.exit(84)

        for i, layer in enumerate(layers):
            W, b = map(np.array, (layer['weights'], layer['biases']))
            if W.shape != network.weights[i].shape or b.shape != network.biases[i].shape:
                print(f"Error: Layer {i} shape mismatch.", file=sys.stderr)
                sys.exit(84)
            network.weights[i], network.biases[i] = W.astype(np.float32), b.astype(np.float32)

    def save_network(self, filename):
        """
        Saves the network to a JSON file.

        Args:
            filename (str): Path to the JSON file.
        """
        data = {
            "input_neurons": self.layer_sizes[0],
            "output_neurons": self.layer_sizes[-1],
            "hidden_neurons_list": self.layer_sizes[1:-1],
            "learning_rate": self.learning_rate,
            "epochs": getattr(self, 'epochs', 10),
            "layers": [{"weights": W.tolist(), "biases": b.tolist()} for W, b in zip(self.weights, self.biases)]
        }

        try:
            with open(filename, 'w') as f:
                json.dump(data, f, indent=4)
        except Exception as e:
            print(f"Error: cannot save network file: {e}", file=sys.stderr)
            sys.exit(84)

        print(f"Network saved to {filename}")

    def forward(self, x):
        """
        Performs a forward pass through the network.

        Args:
            x (numpy.ndarray): Input data.

        Returns:
            numpy.ndarray: Output of the network.
        """
        activations, zs = [x], []
        for i, (W, b) in enumerate(zip(self.weights, self.biases)):
            z = np.dot(activations[-1], W) + b
            zs.append(z)
            a = self.relu(z) if i < len(self.weights) - 1 else self.softmax(z)
            activations.append(a)
        self.activations, self.zs = activations, zs
        return activations[-1]

    @staticmethod
    def relu(z):
        """
        Applies the ReLU activation function.

        Args:
            z (numpy.ndarray): Input data.

        Returns:
            numpy.ndarray: Output after applying ReLU.
        """
        return np.maximum(0, z)

    @staticmethod
    def softmax(z):
        """
        Applies the softmax activation function.

        Args:
            z (numpy.ndarray): Input data.

        Returns:
            numpy.ndarray: Output after applying softmax.
        """
        z_shift = z - np.max(z, axis=1, keepdims=True)
        exp_z = np.exp(z_shift)
        return exp_z / np.sum(exp_z, axis=1, keepdims=True)

    def predict(self, x):
        """
        Predicts the class for the input data.

        Args:
            x (numpy.ndarray): Input data.

        Returns:
            numpy.ndarray: Predicted class labels.
        """
        return np.argmax(self.forward(x), axis=1)

    def cross_entropy_loss(self, Y, outputs, class_weights):
        """
        Compute the cross-entropy loss with class weighting.

        Y: True labels, shape (batch_size,)
        outputs: Predicted outputs from the network, shape (batch_size, num_classes)
        class_weights: Weight for each class, shape (num_classes,)

        Returns: scalar loss value
        """
        num_samples = Y.shape[0]
        log_probs = np.log(outputs + 1e-8)  # Avoid log(0) error by adding a small epsilon
        loss = -np.sum(class_weights[Y] * log_probs[np.arange(num_samples), Y]) / num_samples
        return loss