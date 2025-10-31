#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;  // Read number of test cases

    while (tc--) {
        int N;
        cin >> N;  // Read the size of the matrix

        // Special case: if N = 1, output 0 and continue
        if (N == 1) {
            cout << 0 << "\n";
            continue;
        }

        int a[35][35];  // Declare a 2D array (maximum size 35x35)

        // Fill the matrix using the formula (i + j + 1) % N
        // This creates a pattern where each row is a cyclic shift of the previous one
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                a[i][j] = (i + j + 1) % N;
            }
        }

        // Print the matrix
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";  // New line after each row
        }
    }
}
