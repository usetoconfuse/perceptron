#include <stdio.h>

int main() {
    double samples[6][3] = {
        {1,  4, -1},
        {2,  9,  1},
        {5,  6,  1},
        {4,  5,  1},
        {6, 0.7,-1},
        {1, 1.5,-1}
    };

    double w0 = 0, w1 = 0, w2 = 0;
    int epoch = -1; // Increment from -1 as we have to loop an extra time to confirm stability
    int stable = 0;
    int sampleSize = sizeof(samples)/sizeof(*samples);

    while (!stable) // Loop until convergence
    {
        stable = 1;
        for (int i=0; i<sampleSize; i++)
        {
            const double* pt = samples[i];
            const double sum = w0 + w1 * pt[0] + w2 * pt[1];
            if (sum * pt[2] <= 0) // Adjust weights if incorrectly classified
            {
                stable = 0;
                w0 += pt[2];
                w1 += pt[2] * pt[0];
                w2 += pt[2] * pt[1];
            }
        }
        epoch++;
    }

    printf("w0: %.2f\nw1: %.2f\nw2: %.2f\nStabilised in %d epochs", w0, w1, w2, epoch);
    return 0;
}
