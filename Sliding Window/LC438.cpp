#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(s.size() < p.size()) return result;
        vector<int> pCount(26, 0), window(26, 0);

        for(char c : p){
            pCount[c-'a']++;
        }

        int k = p.size();
        for(int i = 0; i < s.size(); i++){
            window[s[i] - 'a']++;
            if(i >= k) window[s[i-k]-'a']--;

            if(window == pCount) result.push_back(i - k + 1);
        }
        return result;
    }
};

// TC: O(N)
// SC: O(1)


/*----------Optimized Version-----------*/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(s.size() < p.size()) return result;
        
        vector<int>count(26, 0);
        for(char c: p) count[c-'a']++;

        int required = p.size();
        int left = 0;

        for(int right = 0; right < s.size(); right++){
            if(count[s[right]-'a'] > 0) required--;

            count[s[right]-'a']--;

            if(right-left+1 > p.size()){
                if(count[s[left]-'a'] >= 0) required++;
                count[s[left]-'a']++;
                left++;
            }
            
            if(required == 0) result.push_back(left);

        }
        return result;
    }
};

// TC: O(N)
// SC: O(1)