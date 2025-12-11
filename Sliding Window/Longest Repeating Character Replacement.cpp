#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    vector<int> freq(26, 0);
    int l = 0, maxFreq = 0, maxLen = 0;

    for (int r = 0; r < s.size(); r++) {
        freq[s[r] - 'A']++;
        maxFreq = max(maxFreq, freq[s[r] - 'A']);

        // if replacements needed > k, shrink window
        while ((r - l + 1) - maxFreq > k) {
            freq[s[l] - 'A']--;
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}

int main() {
    string s = "AABABBA";
    int k = 1;

    cout << characterReplacement(s, k);
}

// TC: O(N)
// SC: O(1)