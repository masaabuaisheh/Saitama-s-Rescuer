#include <stdio.h>

#define Nn 1000 // Define maximum size of arrays

int pp[Nn]; // Array to store weights of people
int Zz[Nn]; // Array to store maximum weight Saitama can carry

// Function to compute the maximum number of people Saitama can save
int savedbySaitama(int N) {
    // Initialize the first two elements of Zz array based on the weights of the first two people
    Zz[0] = pp[0];
    if (N >= 2) {
        if (pp[0] > pp[1]) {
            Zz[1] = pp[0];
        }
        else {
            Zz[1] = pp[1];
        }
    }
    // Iterate through the rest of the people and calculate the maximum weight Saitama can carry
    int i = 2;
    while (i < N) {
        int scenario1 = pp[i] + Zz[i - 2]; // Weight if Saitama carries current person and person two steps back
        int scenario2 = Zz[i - 1]; // Weight if Saitama does not carry current person
        // Choose the maximum weight between carrying the current person and not carrying them
        if (scenario1 > scenario2) {
            Zz[i] = scenario1;
        }
        else {
            Zz[i] = scenario2;
        }
        i++;
    }
    // Return the maximum weight Saitama can carry, which represents the maximum number of people he can save
    return Zz[N - 1];
}

int main() {
    int N;
    scanf_s("%d", &N); // Read the number of people

    // Read the weights of each person into the pp array
    for (int i = 0; i < N; ++i) {
        scanf_s("%d", &pp[i]);
    }

    // Compute the maximum number of people Saitama can save and print the result
    int maximumnumberofpeople = savedbySaitama(N);
    printf("%d\n", maximumnumberofpeople);
    return 0;
}
