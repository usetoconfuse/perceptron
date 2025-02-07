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

    for (int k=0; k<32; k++) // The perceptron converges in 32 epochs
    {
        for (int i=0; i<6; i++)
        {
            double* pt = samples[i];
            double sum = w0 + w1 * pt[0] + w2 * pt[1];
            if (sum * pt[2] <= 0) // Adjust weights if incorrectly classified
            {
                w0 += pt[2];
                w1 += pt[2] * pt[0];
                w2 += pt[2] * pt[1];
            }
        }
    }

    printf("w0: %.2f\nw1: %.2f\nw2: %.2f\n", w0, w1, w2);
    return 0;
}