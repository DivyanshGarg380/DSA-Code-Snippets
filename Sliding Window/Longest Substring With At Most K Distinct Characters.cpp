#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    if(k==0) return 0;
    unordered_map<char,int>mp;
    int l = 0, maxLen = 0;
    for(int r = 0; r < s.size(); r++){
    	mp[s[r]]++;
    	while(mp.size() > k){
    		mp[s[l]]--;
    		if(mp[s[l]] == 0) mp.erase(s[l]);
    		l++;
    	}
    	maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}

int main() {
    string s = "eceba";
    int k = 2;

    cout << lengthOfLongestSubstringKDistinct(s, k);
}

// TC: O(N)
// SC: O(K) but equal to O(256)