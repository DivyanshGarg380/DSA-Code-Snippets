#include <iostream>
using namespace std;
class Solution {
public:
    int minimumBuckets(string h) {
        int buk = 0;              // Count of buckets needed
        int n = h.size();         // Length of the street string

        for (int i = 0; i < n; i++) {
            // Check if current position has a house ('H')
            if (h[i] == 'H') {

                // If there's already a bucket placed on the left side ('A'), skip this house
                if ((i >= 1) && (h[i - 1] == 'A')) {
                    continue;
                }

                // Try to place a bucket on the right if there's an empty spot ('.')
                if (i + 1 < n && h[i + 1] == '.') {
                    h[i + 1] = 'A';  // Mark that a bucket is placed here
                    buk++;           // Increase bucket count
                    continue;
                }

                // If right is not possible, try to place bucket on the left
                else if (i > 0 && h[i - 1] == '.') {
                    h[i - 1] = 'A';  // Mark left spot as having a bucket
                    buk++;           // Increase bucket count
                }

                // If neither side has space, it's impossible to give this house water
                else {
                    return -1;
                }
            }
        }
        return buk;  // Return total number of buckets placed
    }
};
