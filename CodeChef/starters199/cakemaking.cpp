#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;   // Input two integers A and B

    int ans;         // Variable to store the result

    // If A is greater than or equal to B
    if (A >= B) {
        ans = (A - 1) * B;  // Use (A - 1) multiplied by B
    } 
    else {
        ans = (B - 1) * A;  // Otherwise, use (B - 1) multiplied by A
    }

    cout << ans;     // Output the final answer
    return 0;
}
