import sys

class Parser:
    def __init__(self, config_file: str):
        """
        Initializes the Parser with the given configuration file.

        Args:
            config_file (str): Path to the configuration file.
        """
        self.config_file = config_file
        self.input_neurons = 0
        self.output_neurons = 0
        self.hidden_neurons_list = list()
        self.training_params = {
            "learning_rate": 0.01,
            "epochs": 10
        }

    def parse(self):
        """
        Parses the configuration file and sets the network parameters.

        Raises:
            SystemExit: If the configuration file is not found or there is an error while parsing.
        """
        try:
            with open(self.config_file, 'r') as file:
                for line in file:
                    line = line.strip()
                    if not line or line.startswith("#"):
                        continue

                    key, value = line.split("=")
                    key, value = key.strip(), value.strip()

                    if key == "input_layer.input_neurons":
                        self.input_neurons = int(value)
                    elif key.startswith("hidden_layer_"):
                        layer_index = int(key.split(".")[0].split("_")[-1]) - 1
                        while len(self.hidden_neurons_list) <= layer_index:
                            self.hidden_neurons_list.append(0)
                        self.hidden_neurons_list[layer_index] = int(value)
                    elif key == "output_layer.output_neurons":
                        self.output_neurons = int(value)
                    elif key.startswith("training."):
                        param_name = key.split(".")[1]
                        self.training_params[param_name] = int(value) if value.isdigit() else float(value)

            self.validate_config()

        except FileNotFoundError:
            print(f"Error: Configuration file '{self.config_file}' not found.", file=sys.stderr)
            sys.exit(84)
        except Exception as e:
            print(f"Error while parsing: {e}", file=sys.stderr)
            sys.exit(84)

    def validate_config(self):
        """
        Validates the parsed configuration to ensure all required parameters are set.

        Raises:
            SystemExit: If any required parameter is invalid.
        """
        if self.input_neurons <= 0:
            print("Error: input_neurons must be greater than 0", file=sys.stderr)
            sys.exit(84)

        if self.output_neurons <= 0:
            print("Error: output_neurons must be greater than 0", file=sys.stderr)
            sys.exit(84)

    def get_config(self):
        """
        Returns the parsed configuration as a dictionary.

        Returns:
            dict: The configuration dictionary containing network parameters.
        """
        return {
            "input_neurons": self.input_neurons,
            "hidden_neurons_list": self.hidden_neurons_list,
            "output_neurons": self.output_neurons,
            "training_params": self.training_params,
        }