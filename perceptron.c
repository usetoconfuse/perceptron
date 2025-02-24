#include <stdio.h>
#include <math.h>


// Standard/Rosenblatt perceptron algorithm

int main() {

    // Constant data array and dimensions, can be rewritten to accept input
    #define m 6 // Number of training vectors
    #define n 4 // Dimension of each training vector

    const double T[m][n] = {
        {1, 1,  4,  -1},
        {1, 2,  9,   1},
        {1, 5,  6,   1},
        {1, 4,  5,   1},
        {1, 6, 0.7, -1},
        {1, 1, 1.5, -1}
    };

    double w[n-1];
    unsigned long long epoch = 0;
    int stable = 0;


    // Iterate over data samples

    while (!stable)
    {
        epoch++;
        stable = 1;

        for (int i=0; i<m; i++)
        {
            const double* x = T[i]; // This training vector

            // Calculate weighted sum
            double sum = 0;
            for (int j=0; j<n-1; j++) {
                sum += w[j] * x[j];
            }

            if (sum) sum = sum / fabs(sum); // Apply Heaviside step function
            if (sum != x[n-1]) // Adjust weights if incorrectly classified
            {
                stable = 0;
                for (int j=0; j<n-1; j++) {
                    w[j] += x[n-1] * x[j];
                }
            }
        }
    }

    epoch--; // -1 as we had to loop an extra time to confirm stability

    printf("w_x = %.4f", w[0]);
    for (int i=1; i<n-1; i++)
    {
        const char sign = w[i] >= 0 ? '+' : '\0';
        printf(" %c%.4f(x%d)", sign, w[i], i);
    }
    printf("\nStabilised in %llu epochs", epoch);

    return 0;
}
