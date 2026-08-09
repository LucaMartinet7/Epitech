import numpy as np

class CheckStop:
    """
    Implements early stopping mechanism to halt training when validation loss stops improving.

    Attributes:
        patience (int): Number of epochs to wait for improvement before stopping.
        best_loss (float): Best validation loss observed so far.
        epochs_since_improvement (int): Number of epochs since the last improvement in validation loss.
    """
    def __init__(self, patience=5):
        """
        Initializes the CheckStop instance with a specified patience.

        Args:
            patience (int): Number of epochs to wait for improvement before stopping.
        """
        self.patience = patience
        self.best_loss = float('inf')
        self.epochs_since_improvement = 0

    def should_stop(self, current_loss):
        """
        Checks if training should be stopped based on the current validation loss.

        Args:
            current_loss (float): The current validation loss.

        Returns:
            bool: True if training should be stopped, False otherwise.
        """
        if current_loss < self.best_loss:
            self.best_loss = current_loss
            self.epochs_since_improvement = 0
            return False
        else:
            self.epochs_since_improvement += 1
            return self.epochs_since_improvement >= self.patience

    def reset(self):
        """
        Resets the early stopping parameters.
        """
        self.best_loss = float('inf')
        self.epochs_since_improvement = 0


class DataProcessor:
    """
    Handles data preparation tasks such as shuffling and splitting.

    Methods:
        shuffle_and_split(X, Y, split_ratio=0.8):
            Shuffles and splits the data into training and validation sets.

        compute_class_weights(labels, num_classes=6):
            Computes class weights to handle class imbalance.
    """

    @staticmethod
    def shuffle_and_split(X, Y, split_ratio=0.8):
        """
        Shuffles and splits the data into training and validation sets.

        Args:
            X (np.ndarray): Input features.
            Y (np.ndarray): Input labels.
            split_ratio (float): Ratio of the training set size to the total dataset size.

        Returns:
            tuple: Four numpy arrays representing X_train, Y_train, X_val, Y_val.

        Raises:
            ValueError: If the length of X and Y do not match.
        """
        if len(X) != len(Y):
            raise ValueError("Input features and labels must have the same length.")

        idx = np.random.permutation(len(X))
        split_idx = int(len(X) * split_ratio)
        return X[idx[:split_idx]], Y[idx[:split_idx]], X[idx[split_idx:]], Y[idx[split_idx:]]

    @staticmethod
    def compute_class_weights(labels, num_classes=6):
        """
        Computes class weights to handle class imbalance.

        Args:
            labels (np.ndarray): Array of labels.
            num_classes (int): Number of classes.

        Returns:
            np.ndarray: Array of class weights.
        """
        class_counts = np.bincount(labels, minlength=num_classes)
        total_samples = len(labels)
        class_weights = np.zeros(num_classes, dtype=float)
        for class_idx in range(num_classes):
            if class_counts[class_idx] > 0:
                class_weights[class_idx] = total_samples / (num_classes * class_counts[class_idx])
        return class_weights

class Optimizer:
    """
    Handles optimization logic such as Adam updates.

    Attributes:
        learning_rate (float): The learning rate for the optimizer.
        beta1 (float): The exponential decay rate for the first moment estimates.
        beta2 (float): The exponential decay rate for the second moment estimates.
        epsilon (float): A small constant for numerical stability.
        t (int): The time step used for bias correction.
        m (dict): Dictionary to store the first moment estimates for weights and biases.
        v (dict): Dictionary to store the second moment estimates for weights and biases.
    """
    def __init__(self, learning_rate, beta1=0.9, beta2=0.999, epsilon=1e-8):
        """
        Initializes the Optimizer instance with specified hyperparameters.

        Args:
            learning_rate (float): The learning rate for the optimizer.
            beta1 (float): The exponential decay rate for the first moment estimates.
            beta2 (float): The exponential decay rate for the second moment estimates.
            epsilon (float): A small constant for numerical stability.
        """
        self.learning_rate = learning_rate
        self.beta1 = beta1
        self.beta2 = beta2
        self.epsilon = epsilon
        self.t = 0
        self.m = {'w': [], 'b': []}  # Storing momentums for weights and biases
        self.v = {'w': [], 'b': []}  # Storing squared gradients for weights and biases

    def initialize(self, weights, biases):
        """
        Initialize first moment (m) and second moment (v) estimates for weights and biases.

        Args:
            weights (list of np.ndarray): List of weight matrices for each layer.
            biases (list of np.ndarray): List of bias vectors for each layer.
        """
        self.m['w'] = [np.zeros_like(w) for w in weights]
        self.v['w'] = [np.zeros_like(w) for w in weights]
        self.m['b'] = [np.zeros_like(b) for b in biases]
        self.v['b'] = [np.zeros_like(b) for b in biases]

    def _update_moments(self, grad, moment, squared_moment, layer):
        """
        Update the first and second moments (m and v) for a given gradient.

        Args:
            grad (np.ndarray): The gradient for the current layer.
            moment (list of np.ndarray): The first moment estimates for the current layer.
            squared_moment (list of np.ndarray): The second moment estimates for the current layer.
            layer (int): The index of the current layer.

        Returns:
            tuple: The corrected first and second moment estimates.
        """
        moment[layer] = self.beta1 * moment[layer] + (1 - self.beta1) * grad
        squared_moment[layer] = self.beta2 * squared_moment[layer] + (1 - self.beta2) * (grad ** 2)
        m_corr = moment[layer] / (1 - self.beta1 ** self.t)
        v_corr = squared_moment[layer] / (1 - self.beta2 ** self.t)
        return m_corr, v_corr

    def _compute_update(self, m_corr, v_corr):
        """
        Compute the parameter update using corrected moments.

        Args:
            m_corr (np.ndarray): The corrected first moment estimate.
            v_corr (np.ndarray): The corrected second moment estimate.

        Returns:
            np.ndarray: The parameter update.
        """
        return self.learning_rate * m_corr / (np.sqrt(v_corr) + self.epsilon)

    def _get_gradients(self, gradients, layer):
        """
        Calculate the weight and bias updates for a given layer.

        Args:
            gradients (tuple): A tuple containing the gradients for weights and biases.
            layer (int): The index of the current layer.

        Returns:
            tuple: The weight and bias updates for the current layer.
        """
        grad_w, grad_b = gradients
        grad_w_update, grad_b_update = [], []

        for grad, moment_key, squared_moment_key in zip([grad_w, grad_b], ['w', 'b'], ['w', 'b']):
            m_corr, v_corr = self._update_moments(grad, self.m[moment_key], self.v[squared_moment_key], layer)
            grad_update = self._compute_update(m_corr, v_corr)
            if moment_key == 'w':
                grad_w_update = grad_update
            else:
                grad_b_update = grad_update

        return grad_w_update, grad_b_update

    def update(self, gradients, layer):
        """
        Update weights and biases using Adam optimization.

        Args:
            gradients (tuple): A tuple containing the gradients for weights and biases.
            layer (int): The index of the current layer.

        Returns:
            tuple: The weight and bias updates for the current layer.
        """
        self.t += 1
        return self._get_gradients(gradients, layer)

class Trainer:
    """
    Coordinates the training process for a neural network.

    Attributes:
        nn (NeuralNetwork): The neural network to be trained.
        optimizer (Optimizer): The optimizer used for updating the network parameters.
        early_stopping (CheckStop): The early stopping mechanism to halt training when validation loss stops improving.
    """
    def __init__(self, neural_net):
        """
        Initializes the Trainer instance with the specified neural network.

        Args:
            neural_net (NeuralNetwork): The neural network to be trained.
        """
        self.nn = neural_net
        self.optimizer = Optimizer(neural_net.learning_rate)
        self.early_stopping = CheckStop()

    def train(self, X, Y, epochs=10, batch_size=64, patience=5):
        """
        Trains the neural network.

        Args:
            X (np.ndarray): Input features.
            Y (np.ndarray): Input labels.
            epochs (int): Number of epochs to train the network.
            batch_size (int): Size of the mini-batches used for training.
            patience (int): Number of epochs to wait for improvement before stopping.
        """
        X_train, Y_train, X_val, Y_val = DataProcessor.shuffle_and_split(X, Y)
        class_weights = DataProcessor.compute_class_weights(Y_train)
        self.optimizer.initialize(self.nn.weights, self.nn.biases)

        for epoch in range(1, epochs + 1):
            train_loss, train_accuracy = self.run_epoch(X_train, Y_train, batch_size, class_weights)
            val_loss, val_accuracy = self.validate(X_val, Y_val, class_weights)

            self.log_epoch(epoch, epochs, train_loss, train_accuracy, val_loss, val_accuracy)

            if self.early_stopping.should_stop(val_loss):
                print("Early stopping triggered.")
                break

    def run_epoch(self, features, labels, batch_size, class_weights):
        """
        Runs one training epoch.

        Args:
            features (np.ndarray): Input features for training.
            labels (np.ndarray): Input labels for training.
            batch_size (int): Size of the mini-batches used for training.
            class_weights (np.ndarray): Array of class weights to handle class imbalance.

        Returns:
            tuple: Average loss and accuracy for the epoch.
        """
        num_samples = len(features)
        indices = np.random.permutation(num_samples)
        total_loss, correct_predictions = 0, 0

        for start_idx in range(0, num_samples, batch_size):
            end_idx = start_idx + batch_size
            batch_indices = indices[start_idx:end_idx]
            batch_features, batch_labels = features[batch_indices], labels[batch_indices]

            predictions = self.nn.forward(batch_features)
            loss = self.nn.cross_entropy_loss(batch_labels, predictions, class_weights)
            total_loss += loss
            correct_predictions += self.compute_correct_predictions(predictions, batch_labels)

            gradients = self.compute_gradients(batch_features, batch_labels, predictions, class_weights)
            self.apply_gradients(gradients)

        average_loss = total_loss / num_samples
        accuracy = (correct_predictions / num_samples) * 100
        return average_loss, accuracy

    def compute_correct_predictions(self, outputs, Y_batch):
        """
        Computes the number of correct predictions.

        Args:
            outputs (np.ndarray): The output predictions from the network.
            Y_batch (np.ndarray): The true labels.

        Returns:
            int: The number of correct predictions.
        """
        predictions = np.argmax(outputs, axis=1)
        return np.sum(predictions == Y_batch)

    def compute_gradients(self, X, Y, outputs, class_weights):
        """
        Computes the gradients for the model parameters.

        Args:
            X (np.ndarray): Input features.
            Y (np.ndarray): Input labels.
            outputs (np.ndarray): The output predictions from the network.
            class_weights (np.ndarray): Array of class weights to handle class imbalance.

        Returns:
            tuple: Gradients for weights and biases.
        """
        delta = self.compute_delta(Y, outputs, class_weights)
        grad_w, grad_b = self.compute_all_layer_gradients(delta, Y)
        return grad_w, grad_b

    def compute_delta(self, Y, outputs, class_weights):
        """
        Computes the delta for backpropagation.

        Args:
            Y (np.ndarray): Input labels.
            outputs (np.ndarray): The output predictions from the network.
            class_weights (np.ndarray): Array of class weights to handle class imbalance.

        Returns:
            np.ndarray: The delta for backpropagation.
        """
        delta = outputs.copy()
        delta[np.arange(len(Y)), Y] -= 1
        delta *= class_weights[Y].reshape(-1, 1)
        return delta

    def compute_all_layer_gradients(self, delta, Y):
        """
        Computes the gradients for all layers.

        Args:
            delta (np.ndarray): The delta for backpropagation.
            Y (np.ndarray): Input labels.

        Returns:
            tuple: Gradients for weights and biases for all layers.
        """
        grad_w, grad_b = [], []
        for layer_idx in range(len(self.nn.weights) - 1, -1, -1):
            grad_w_layer, grad_b_layer = self.compute_layer_gradients(layer_idx, delta, Y)
            grad_w.append(grad_w_layer)
            grad_b.append(grad_b_layer)

            if layer_idx > 0:
                delta = self.backpropagate_delta(delta, layer_idx)

        return grad_w[::-1], grad_b[::-1]

    def compute_layer_gradients(self, layer_idx, delta, Y):
        """
        Computes the gradients for a specific layer.

        Args:
            layer_idx (int): The index of the layer.
            delta (np.ndarray): The delta for backpropagation.
            Y (np.ndarray): Input labels.

        Returns:
            tuple: Gradients for weights and biases for the specified layer.
        """
        grad_w_layer = np.dot(self.nn.activations[layer_idx].T, delta) / len(Y)
        grad_b_layer = np.mean(delta, axis=0)
        return grad_w_layer, grad_b_layer

    def backpropagate_delta(self, delta, layer_idx):
        """
        Backpropagates the delta to the previous layer.

        Args:
            delta (np.ndarray): The delta for backpropagation.
            layer_idx (int): The index of the current layer.

        Returns:
            np.ndarray: The delta for the previous layer.
        """
        delta = np.dot(delta, self.nn.weights[layer_idx].T)
        delta[self.nn.zs[layer_idx - 1] <= 0] = 0  # ReLU derivative
        return delta

    def apply_gradients(self, gradients):
        """
        Applies the gradients to update the model parameters.

        Args:
            gradients (tuple): Gradients for weights and biases.
        """
        for layer_idx, (grad_w, grad_b) in enumerate(zip(*gradients)):
            grad_w_update, grad_b_update = self.optimizer.update((grad_w, grad_b), layer=layer_idx)
            self.nn.weights[layer_idx] -= grad_w_update
            self.nn.biases[layer_idx] -= grad_b_update

    def validate(self, X, Y, class_weights):
        """
        Validates the model on validation data.

        Args:
            X (np.ndarray): Input features for validation.
            Y (np.ndarray): Input labels for validation.
            class_weights (np.ndarray): Array of class weights to handle class imbalance.

        Returns:
            tuple: Validation loss and accuracy.
        """
        outputs = self.nn.forward(X)
        loss = self.nn.cross_entropy_loss(Y, outputs, class_weights)
        accuracy = self.compute_accuracy(outputs, Y)
        return loss, accuracy

    def compute_accuracy(self, outputs, Y):
        """
        Computes the accuracy of the model.

        Args:
            outputs (np.ndarray): The output predictions from the network.
            Y (np.ndarray): The true labels.

        Returns:
            float: The accuracy of the model.
        """
        predictions = np.argmax(outputs, axis=1)
        return np.mean(predictions == Y) * 100

    def log_epoch(self, epoch, total_epochs, train_loss, train_accuracy, val_loss, val_accuracy):
        """
        Logs the training and validation metrics for an epoch.

        Args:
            epoch (int): The current epoch number.
            total_epochs (int): The total number of epochs.
            train_loss (float): The training loss for the epoch.
            train_accuracy (float): The training accuracy for the epoch.
            val_loss (float): The validation loss for the epoch.
            val_accuracy (float): The validation accuracy for the epoch.
        """
        log_message = (
            f"[Epoch {epoch}/{total_epochs}] - "
            f"[Training Loss: {train_loss:.4f}] - [Training Accuracy: {train_accuracy:.2f}%] - "
            f"[Validation Loss: {val_loss:.4f}] - [Validation Accuracy: {val_accuracy:.2f}%]"
        )
        print(log_message)