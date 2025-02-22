#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {

    // Constant data array and dimensions, can be rewritten to accept input
    const int SAMPLE_NUM = 6;
    const int SAMPLE_SIZE = 4;

    double data[6][4] = {
        {-1, 1.7, 1,  4},
        {1, 5.5, 2,  9},
        {1, 2.2, 5,  6},
        {1, 1.3, 4,  5},
        {-1, 1.4, 6, 0.7},
        {-1, 4.2, 1, 1.5}
    };

    double samples[SAMPLE_NUM][SAMPLE_SIZE];
    memcpy(samples, data, sizeof(data));

    double w[SAMPLE_SIZE];
    int epoch = -1; // Loop from -1 as we have to loop an extra time to confirm stability
    int stable = 0;


    // Iterate over data samples

    while (!stable)
    {
        stable = 1;
        epoch++;
        for (int i=0; i<SAMPLE_NUM; i++)
        {
            const double* x = samples[i];
            double sum = w[0];
            for (int j=1; j<SAMPLE_SIZE; j++) {
                sum += w[j] * x[j];
            }
            if (sum) sum = sum / fabs(sum); // Map to 1 or -1 if not 0

            if (sum != x[0]) // Adjust weights if incorrectly classified
            {
                stable = 0;

                w[0] += x[0];
                for (int j=1; j<SAMPLE_SIZE; j++) {
                    w[j] += x[0] * x[j];
                }
            }
        }
    }

    printf("w[0]: %.2f\nw[1]: %.2f\nw[2]: %.2f\nw[3]: %.2f\n"
           "Stabilised in %d epochs", w[0], w[1], w[2], w[3], epoch);
    return 0;
}
