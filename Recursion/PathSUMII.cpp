#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


void dfs(TreeNode* node, int targetSum, int curSum, vector<int>&path, vector<vector<int>>&res){
	if(!node) return;
	curSum += node->val;
	path.push_back(node->val);
	if(!node->left && !node->right && curSum == targetSum){
		res.push_back(path);
	}
	dfs(node->left,targetSum,curSum,path,res);
	dfs(node->right,targetSum,curSum,path,res);
	path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
	vector<vector<int>>result;
	vector<int>path;
	dfs(root,targetSum,0,path,result);
	return result;
}

int main() {
	// your code goes here
	// Input your tests to validate the code
    return 0;
}

// TC: O(N) where N is number of nodes in the tree
// SC: O(H) where H is height of the tree