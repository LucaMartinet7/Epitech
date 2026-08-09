import math
import json
import sys
import numpy as np
from typing import List, Tuple, Dict

class NetworkManager:
    def __init__(self, config: dict):
        """
        Initializes the NetworkManager with the given configuration.

        Args:
            config (dict): Configuration dictionary containing network parameters.
        """
        self.config = config

    def init_network(self) -> List[Tuple[List[List[float]], List[float]]]:
        """
        Initializes the network layers based on the configuration.

        Returns:
            List[Tuple[List[List[float]], List[float]]]: A list of tuples where each tuple contains
            the weights and biases for a layer.
        """
        layer_sizes = self.get_layer_sizes()
        return [self.initialize_layer(layer_sizes[i], layer_sizes[i + 1]) for i in range(len(layer_sizes) - 1)]

    def get_layer_sizes(self) -> List[int]:
        """
        Calculates the sizes of all layers based on the configuration.

        Returns:
            List[int]: A list of integers representing the number of neurons in each layer.
        """
        return [self.config["input_neurons"]] + self.config["hidden_neurons_list"] + [self.config["output_neurons"]]

    def initialize_layer(self, in_dim: int, out_dim: int) -> Tuple[List[List[float]], List[float]]:
        """
        Initializes weights and biases for a single layer.

        Args:
            in_dim (int): Number of input neurons.
            out_dim (int): Number of output neurons.

        Returns:
            Tuple[List[List[float]], List[float]]: A tuple containing the weights and biases for the layer.
        """
        weights = self.initialize_weights(in_dim, out_dim)
        biases = self.initialize_biases(out_dim)
        return weights, biases

    def initialize_weights(self, in_dim: int, out_dim: int) -> List[List[float]]:
        """
        Generates weights with a standard normal distribution.

        Args:
            in_dim (int): Number of input neurons.
            out_dim (int): Number of output neurons.

        Returns:
            List[List[float]]: A list of lists representing the weights matrix.
        """
        stdev = math.sqrt(2.0 / in_dim)
        return np.random.normal(0, stdev, (in_dim, out_dim)).tolist()

    def initialize_biases(self, out_dim: int) -> List[float]:
        """
        Initializes biases to zero for the given output dimension.

        Args:
            out_dim (int): Number of output neurons.

        Returns:
            List[float]: A list of biases initialized to zero.
        """
        return [0.0] * out_dim

    def save_network(self, filename: str, network: List[Tuple[List[List[float]], List[float]]], config: dict):
        """
        Saves the initialized network and configuration to a file.

        Args:
            filename (str): The name of the file to save the network to.
            network (List[Tuple[List[List[float]], List[float]]]): The network to save.
            config (dict): The configuration dictionary.
        """
        data = self.prepare_save_data(network, config)
        try:
            with open(filename, 'w') as f:
                json.dump(data, f, indent=4)
            print(f"Network saved to {filename}")
        except Exception as e:
            print(f"Error: cannot save network file ({e})", file=sys.stderr)
            sys.exit(84)

    def prepare_save_data(self, network: List[Tuple[List[List[float]], List[float]]], config: dict) -> Dict:
        """
        Prepares the data structure to save the network.

        Args:
            network (List[Tuple[List[List[float]], List[float]]]): The network to save.
            config (dict): The configuration dictionary.

        Returns:
            Dict: A dictionary containing the network and configuration data.
        """
        return {
            "input_neurons": config["input_neurons"],
            "output_neurons": config["output_neurons"],
            "hidden_neurons_list": config["hidden_neurons_list"],
            "learning_rate": config["training_params"]["learning_rate"],
            "epochs": config["training_params"]["epochs"],
            "layers": self.serialize_network(network),
        }

    def serialize_network(self, network: List[Tuple[List[List[float]], List[float]]]) -> List[Dict]:
        """
        Serializes the network's layers into a dictionary format.

        Args:
            network (List[Tuple[List[List[float]], List[float]]]): The network to serialize.

        Returns:
            List[Dict]: A list of dictionaries where each dictionary represents a layer with weights and biases.
        """
        return [{"weights": W, "biases": b} for W, b in network]