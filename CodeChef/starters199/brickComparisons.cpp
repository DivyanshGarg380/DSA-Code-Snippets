#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;  // Read number of test cases

    while (tc--) {
        int size;
        cin >> size;  // Read size of the array

        vector<int> a(size + 1);  // +1 so we can use 1-based indexing safely

        // Input array elements (starting from index 1)
        for (int i = 1; i <= size; i++) {
            cin >> a[i];
        }

        int maxi = -1;  // To keep track of the maximum value found so far
        int k = 0;      // To store the index of the maximum element

        // Loop through the array to find the index of the maximum element
        for (int j = 1; j <= size; j++) {
            if (a[j] > maxi) {
                maxi = a[j];  // Update maximum value
                k = j;        // Store its index
            }
        }

        cout << k << endl;  // Print index of the maximum element
    }
}
