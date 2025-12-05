#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<int> arr = {1, 2, 3};
void permutations(vector<int>& newArr, vector<bool>& used) {
    if (newArr.size() == arr.size()) {
        ans.push_back(newArr);
        return;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        newArr.push_back(arr[i]);
        permutations(newArr, used);
        newArr.pop_back();
        used[i] = false;
    }
}

int main() {
    vector<int> curr;
    vector<bool> used(arr.size(), false);
    permutations(curr, used);
    for (auto &v : ans) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }
    return 0;
}

// Time Complexity: O(n * n!) 
// Space Complexity: O(n)

// Approach 2 -> Swap Method
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
vector<int> arr = {1,2,3};
void permutations(int index) {
    if (index == arr.size()) {
        ans.push_back(arr);
        return;
    }
    unordered_set<int>used;
    for(int i=index;i<arr.size();i++){
    	if(used.count(arr[i])) continue;
    	used.insert(arr[i]);
    	swap(arr[index],arr[i]);
    	permutations(index+1);
    	swap(arr[index],arr[i]);
    }
}

int main() {
	sort(arr.begin(),arr.end());
    permutations(0);
    for (auto &v : ans) {
        for (int x : v) cout << x << " ";
        cout << endl;
    }
    return 0;
}