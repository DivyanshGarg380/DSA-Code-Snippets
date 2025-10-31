#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n;
        cin >> n;  // Number of elements in the array

        vector<ll> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];  // Input array elements

        vector<pair<ll, int>> arr;
        // Store each element along with its original index
        for (int i = 0; i < n; i++) 
            arr.push_back({a[i], i});

        // Sort the array by element values
        sort(arr.begin(), arr.end());

        vector<ll> res(n, 0);  // Result array initialized with 0s

        // The smallest and largest elements get -1 as per problem condition
        res[arr[0].second] = -1;       // Minimum element
        res[arr[n - 1].second] = -1;   // Maximum element

        // For each middle element, calculate the difference between 
        // the midpoints of its neighbors
        for (int i = 1; i < n - 1; i++) {
            ll L = (arr[i - 1].first + arr[i].first) / 2;   // Midpoint with left neighbor
            ll R = (arr[i].first + arr[i + 1].first) / 2;   // Midpoint with right neighbor
            res[arr[i].second] = R - L;                     // Difference between right and left midpoints
        }

        // Print the result in the original order of indices
        for (int i = 0; i < n; i++)
            cout << res[i] << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}
