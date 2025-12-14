#include <bits/stdc++.h>
using namespace std;

// Sliding window + Hashmap
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int>res;
    if(words.empty()) return res;
    int wordLen = words[0].size();
    int k = words.size();
    int totalLen = wordLen*k;
    unordered_map<string,int>freq;
    for(auto &w: words) freq[w]++;
    for(int i=0; i<wordLen; i++){
    // Sliding window from here
        unordered_map<string, int> window;
        int left = i, count = 0;
        for(int right = i; right + wordLen <= s.size(); right += wordLen){
            string word = s.substr(right,wordLen);
            if(freq.count(word)){
                window[word]++;
                count++;
                while(window[word] > freq[word]){
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }
                if(count == k) res.push_back(left);
            }else{
                    window.clear();
                    count = 0;
                    left = right + wordLen;
            }
        }
    } 
    return res;
}

// TC: O(N)
// SC: O(K)