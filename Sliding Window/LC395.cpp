#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int maxLen = 0;

        for(int i = 1; i <= 26; i++){
            vector<int> freq(26, 0);
            int left = 0, right = 0, unique = 0, cnt = 0;
            while(right < n){
                if(freq[s[right]-'a'] == 0) unique++;
                freq[s[right]-'a']++;
                if(freq[s[right]-'a'] == k) cnt++;

                while(unique > i){
                    if(freq[s[left]-'a'] == k) cnt--;
                    freq[s[left]-'a']--;
                    if(freq[s[left]-'a'] == 0) unique--;
                    left++;
                }

                if(unique == i && unique == cnt){
                    maxLen = max(maxLen, right-left+1);
                }

                right++;
            }
        }
        return maxLen;
    }
};

// TC: O(26 * N)
// SC: O(26)