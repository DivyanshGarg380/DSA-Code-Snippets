#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;  // Read number of test cases

    while (T--) {
        int N;
        cin >> N;  // Read length of string to be generated

        // Handle small cases manually with fixed outputs
        if (N == 1) cout << "a\n";
        else if (N == 2) cout << "aa\n";
        else if (N == 3) cout << "aba\n";
        else if (N == 4) cout << "abaa\n";

        // For N >= 5, generate pattern using repetition of "abcde"
        else {
            string p = "abcde";  // Base pattern
            string s = "";       // String to store the result

            // Append letters cyclically from "abcde" until length N
            for (int i = 0; i < N; i++) {
                s += p[i % 5];   // Use modulo 5 to repeat pattern
            }

            cout << s << "\n";   // Output the final string
        }
    }

    return 0;
}
