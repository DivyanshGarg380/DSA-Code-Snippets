#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T; // number of test cases

    while (T--) {
        int N;
        cin >> N; // number of fences

        int A[200005]; // store target colours
        int freq[200005]; // store frequencies
        for (int i = 0; i <= N; i++) {
            freq[i] = 0; // reset
        }

        for (int i = 0; i < N; i++) {
            cin >> A[i];
            freq[A[i]]++;
        }

        int max_freq = 0;
        int max_colour = 1;
        for (int i = 1; i <= N; i++) {
            if (freq[i] > max_freq) {
                max_freq = freq[i];
                max_colour = i;
            }
        }

        // If already all colour 1
        if (max_freq == N && A[0] == 1) {
            cout << 0 << "\n";
        }
        // If all same colour but not 1
        else if (max_freq == N) {
            cout << 1 << "\n";
        }
        else {
            // If most frequent colour is same as initial colour (1)
            if (max_colour == 1) {
                // Just recolour different ones
                cout << (N - freq[1]) << "\n";
            }
            else {
                // Mass paint + fix rest
                cout << 1 + (N - max_freq) << "\n";
            }
        }
    }
    return 0;
}


