This perceptron takes a set of data samples containing an outcome, -1 or 1, and 3 double values, x1, x2, x3, which map to this outcome.
It will iterate over the data set to determine the correct value weights, including a bias, to accurately categorise the entire set.

We have weights $w_0, w_1, w_2, w_3$ which are all 0 to begin with.

There are two learning algorithms:
The perceptron evaluates each sample as $w_0 + w_1x_1 + w_2x_2 + w_3x_3$. A positive result maps to 1 and a negative
result maps to -1 (0 maps to itself and is always considered incorrect).

By default, if the sample is evaluated wrong, it will add the values of $x_1$, $x_2$ and $x_3$
to the weights if the correct evaluation was 1 and subtract them if it was -1.

If the adaline flag is set to 1, the set of weights is $W* = W + \rho(C - S)I$, 
where $W*$ and $W$ are the new and old set of weights, $\rho$ is the learning parameter 
(0.01 by default) and $I$ is the input vector, and $C-S$ is the difference between the correct
output and the modelled output.