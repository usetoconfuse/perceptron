#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>



int main() {

    // Constant data array and dimensions, can be rewritten to accept input
    #define m 6 // Number of training vectors
    #define n 4 // Dimension of each training vector

    const double data[m][n] = {
        {1, 1,  4,  -1},
        {1, 2,  9,   1},
        {1, 5,  6,   1},
        {1, 4,  5,   1},
        {1, 6, 0.7, -1},
        {1, 1, 1.5, -1}
    };

    double T[m][n];
    memcpy(T, data, sizeof(data));

    double w[n-1];
    long long epoch = 0;
    int stable = 0;

    // Adaline variables
    char adaline;
    double lrnParam = 0;
    long long limit = 0;

    // Whether to use adaline weighting algorithm
    while (1)
    {
        printf("Use adaline algorithm? (y/n)\n");
        scanf(" %c", &adaline);
        if (adaline == 'y' || adaline == 'n') break;
        printf("Error: invalid input\n");
    }

    if (adaline == 'y')
    {
        // Randomise starting weights from 0 to 1 inclusive
        srand(time(NULL));
        for (int i=0; i<n-1; i++)
        {
            w[i] = (double)rand() / (double)RAND_MAX;
        }

        // Learning parameter for adaline weighting algorithm
        while (1)
        {
            char lrnBuf[64];
            printf("Input learning parameter (real number >0)\n");
            scanf("%s", lrnBuf);
            lrnParam = strtod(lrnBuf, NULL);
            if (lrnParam > 0) break;
            printf("Error: invalid input\n");
        }

        // Learning parameter for adaline weighting algorithm
        while (1)
        {
            char limBuf[50];
            printf("Input number of epochs to iterate for\n");
            scanf("%s", limBuf);
            limit = strtoll(limBuf, NULL, 10);
            if (limit > 0) break;
            printf("Error: invalid input\n");
        }
    } else // Default weighting algorithm chosen
    {
        epoch = -1; // Loop from -1 as we have to loop an extra time to confirm stability
    }


    // Iterate over data samples

    while (!stable)
    {
        stable = 1;
        epoch++;
        for (int i=0; i<m; i++)
        {
            const double* x = T[i]; // This sample

            // Calculate weighted sum
            double sum = 0;
            for (int j=0; j<n-1; j++) {
                sum += w[j] * x[j];
            }

            if (adaline == 'y') // Adaline algorithm
            {
                if (epoch >= limit) // Exit if iteration limit reached
                {
                    break;
                }

                stable = 0;
                const double diff = lrnParam * (x[n-1] - sum);

                // Update weights
                for (int j=0; j<n-1; j++)
                {
                    w[j] += diff * x[j];
                }
            } else // Default weighting algorithm
            {
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
    }

    printf("w_x = %.4f", w[0]);
    for (int i=1; i<n-1; i++)
    {
        const char sign = w[i] >= 0 ? '+' : '\0';
        printf(" %c%.4f(x%d)", sign, w[i], i);
    }
    if (adaline == 'n') printf("\nStabilised in %lld epochs", epoch);
    return 0;
}
