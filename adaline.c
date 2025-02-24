#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Adaline algorithm

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
    double lrnParam = 0;
    long long limit = 0;

    // Randomise starting weights from 0 to 1 inclusive
    srand(time(NULL));
    for (int i=0; i<n-1; i++)
    {
        w[i] = (double)rand() / (double)RAND_MAX;
    }

    // Learning parameter
    while (1)
    {
        char lrnBuf[64];
        puts("Input learning parameter (real number >0)");
        scanf("%s", lrnBuf);
        errno = 0;
        lrnParam = strtod(lrnBuf, NULL);
        if (lrnParam > 0 && errno != ERANGE) break;
        puts ("Error: invalid input");
    }

    // Limit of iterations over T
    while (1)
    {
        char limBuf[50];
        puts("Input number of epochs to iterate for");
        scanf("%s", limBuf);
        errno = 0;
        limit = strtoll(limBuf, NULL, 10);
        if (limit > 0 && errno != ERANGE) break;
        puts("Error: invalid input");
    }


    // Iterate over data samples

    for (long long k=1; k<=limit; k++)
    {
        for (int i=0; i<m; i++)
        {
            const double* x = T[i]; // This sample

            // Calculate weighted sum
            double sum = 0;
            for (int j=0; j<n-1; j++) {
                sum += w[j] * x[j];
            }
            const double diff = lrnParam * (x[n-1] - sum);

            // Update weights
            for (int j=0; j<n-1; j++)
            {
                w[j] += diff * x[j];
                if (w[j] != w[j]) // Exit program if weight is NaN
                {
                    printf("Error: w%d overflowed during epoch %lld", j, k);
                    exit(EXIT_FAILURE);
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

    return 0;
}
