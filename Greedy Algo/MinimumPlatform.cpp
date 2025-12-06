#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int>& arrival, vector<int>& departure){
    //your code goes here
    int n = arrival.size();
    sort(arrival.begin(),arrival.end());
    sort(departure.begin(),departure.end());
    int i=0,j=0;
    int platforms = 0, maxplatforms = 0;
    while(i<n && j<n){
        if(arrival[i] < departure[j]){
            platforms++;
            maxplatforms = max(maxplatforms,platforms);
            i++;
        }else{
            platforms--;
            j++;
        }
    }
    return maxplatforms;
}
// TC: O(NlogN)
// SC: O(1)