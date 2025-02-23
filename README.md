# Single-layer Perceptron

This algorithm takes a training set $`T = \{x_0, x_1, \ldots, x_i\}`$ of $`m`$ training vectors $`x`$ and calculates a weight vector $`W`$ that
correctly classify all input vectors $`I`$ with respect to some binary class. ($`T`$ is currently hard-coded)

Each $`n`$-dimensional vector $`x`$ contains the input vector $`I`$ with $`n-1`$ features followed by the correct
classification of the data $`C`$.


That is, for all $`x`$:
- $`x_0 = 1`$ (to represent bias)
- $`(x_0, x_1,\;\ldots\;,x_{n-1}) = I`$
- $`x_n = C`$


Let $`w_k`$ be the $`k`$th weight in $`W`$ and let $`I_x`$ be the input vector contained in $`x`$.\
As the perceptron assigns one weight for each feature (including the bias), $`|W| = n-1`$.

The perceptron calculates the weighted sum $`w_x`$ of a given $`x`$ using the formula

$`w_x = w_0 + w_1x_1+ w_2x_2 +\ldots+w_{n-1}x_{n-1} = W \cdot I_x`$ .

Classification is defined by applying the Heaviside step function $`H`$ to $`w_x`$.\
For the purposes of this program, $`H(0) = 0`$, i.e., a predicted value of $`0`$ is always an incorrect classification.

# Behaviour

The program prompts the user to select which artificial neural network to train on the data:
a standard perceptron or an Adaline perceptron. They will then enter any relevant parameters.\
The perceptron then generates the weight vector $`W`$ using the corresponding algorithm, and prints

$`w_x = w_0 + w_1x_1+ w_2x_2 +\ldots+w_{n-1}x_{n-1}`$

with the calculated weights $`w_0, \ldots, w_{n-1}`$ in $`W`$.

## Standard

Starting values for all weights in $W$ are $0$.

The standard perceptron iterates over $`T`$ in order, classifying each $`I_x`$ as $`H(w_x)`$.

If a point is incorrectly classified, i.e., $`H(w_x) \neq C`$, then the perceptron adjusts W
with the formula

$`W* = W + C(I_x)`$

where $`W*`$ is the adjusted set of weights.

The perceptron continues to iterate until it completes an iteration over $`T`$ where it correctly classifies every $`I`$.
Upon completion, the program will output the number of epochs this took.

## Adaline

Starting values for all weights in $W$ are randomised between $0$ and $1$ inclusive.

When selecting the Adaline perceptron, you will be prompted to input a learning parameter $`\rho`$ and a limit value.

The Adaline perceptron iterates over $`T`$ in order like the standard perceptron. However, it does not classify each
$`I_x`$. Instead, it adjusts the weights based on the error in each $`w_x`$ using the formula

$`W* = W + \rho(C-w_x)I_x`$ .

The limit value determines how many epochs the perceptron iterates for.