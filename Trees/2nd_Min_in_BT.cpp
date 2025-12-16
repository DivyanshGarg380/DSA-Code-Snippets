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
int findSecondMinimumValue(TreeNode* root) {
    if(!root) return -1;
    int parent = root->val;
    long ans = helper(root,parent);
    return ans == LONG_MAX ? -1 : ans;
}

long helper(TreeNode* node, int parent){
    if(!node) return LONG_MAX;
    if(node->val > parent){
        return node->val;
    }
    long left = helper(node->left,node->val);
    long right = helper(node->right,node->val);
    return min(left,right);
}
