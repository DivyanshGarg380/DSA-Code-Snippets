#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int>count(26, 0);
        for(char c : s1){
            count[c-'a']++;
        }

        int required = s1.size();
        int left = 0;

        for(int right = 0; right < s2.size(); right++){
            if(count[s2[right]-'a'] > 0) required--;
            count[s2[right]-'a']--;

            if(right - left + 1 > s1.size()){
                if(count[s2[left]-'a'] >= 0) required++;
                count[s2[left++]-'a']++;
            }

            if(required == 0) return true;
        }
        return false;
    }
};

// TC: O(n)
// SC: O(1)