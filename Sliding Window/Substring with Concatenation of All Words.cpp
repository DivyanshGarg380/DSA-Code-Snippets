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

// Intuition
/*
    1) Store required word counts in Freq Map
    2) Start loop 1 from 0 to wordLen
    3) Initialize sliding window variables -> left, window map
    4) Move right pointer in jumps of wordLen !!
    5) Extract the current word -> string word = s.substr(right, wordLen)
      - Case1: Word is Required
         - window[word]++; and count++;
      - Too many same words ?
         - move left pointer and decrease count
      - Word NOT required
         - reset everything
    6) if valid window found, push left pointer in the result
*/