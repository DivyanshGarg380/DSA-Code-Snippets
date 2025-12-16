#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int goodNodes(TreeNode* root) {
    return dfs(root, root->val);
}

int dfs(TreeNode* root, int maxSoFar){
    if(!root) return 0;
    int count = 0;
    if(root->val >= maxSoFar) count = 1;
    maxSoFar = max(maxSoFar, root->val);
    count += dfs(root->left, maxSoFar);
    count += dfs(root->right, maxSoFar);
    return count;
}

// TC: O(N)
// SC: O(H)