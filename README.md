This perceptron takes a set of data samples containing 3 double values, x1, x2, x3, and an outcome, -1 or 1.
It will iterate over the data set to determine the correct value weights, including a bias, to accurately categorise the entire set.

We have weights w0 (bias), w1, w2, w3, which are all 0 to begin with.
The perceptron evaluates each sample as w0 + w1\*x1 + w2\*x2 + w3*x3. The sign of the result determines the outcome it maps to.

The perceptron adjusts its weights using negative reinforcement; when it categorises a sample wrong, it adjusts its weights based on the correct outcome.
It then iterates over the dataset until categorises every entry correctly.
