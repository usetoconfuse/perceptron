#include <stdio.h>

int main() {
    const double samples[6][4] = {
        {1.7, 1,  4, -1},
        {5.5, 2,  9,  1},
        {2.2, 5,  6,  1},
        {1.3, 4,  5,  1},
        {1.4, 6, 0.7,-1},
        {4.2, 1, 1.5,-1}
    };

    double w0 = 0, w1 = 0, w2 = 0, w3 = 0;
    int epoch = -1; // Increment from -1 as we have to loop an extra time to confirm stability
    int stable = 0;
    const int sampleSize = sizeof(samples)/sizeof(*samples);

    while (!stable) // Loop until convergence
    {
        stable = 1;
        for (int i=0; i<sampleSize; i++)
        {
            const double* pt = samples[i];
            const double sum = w0 + w1 * pt[0] + w2 * pt[1] + w3 * pt[2];
            if (sum * pt[3] <= 0) // Adjust weights if incorrectly classified
            {
                stable = 0;
                w0 += pt[3];
                w1 += pt[3] * pt[0];
                w2 += pt[3] * pt[1];
                w3 += pt[3] * pt[2];
            }
        }
        epoch++;
    }

    printf("w0: %.2f\nw1: %.2f\nw2: %.2f\nw3: %.2f\n"
           "Stabilised in %d epochs", w0, w1, w2, w3, epoch);
    return 0;
}
