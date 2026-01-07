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

class Solution {
public:
    long long totalSum = 0;
    long long maxProd = 0;
    const int MOD = 1e9 + 7;

    int maxProduct(TreeNode* root) {
        totalSum = getSum(root);   
        dfs(root);                 
        return maxProd % MOD;
    }

    long long getSum(TreeNode* node) {
        if (!node) return 0;
        return node->val + getSum(node->left) + getSum(node->right);
    }

    long long dfs(TreeNode* node) {
        if (!node) return 0;

        long long left = dfs(node->left);
        long long right = dfs(node->right);

        long long subtreeSum = node->val + left + right;

        long long product = subtreeSum * (totalSum - subtreeSum);
        maxProd = max(maxProd, product);

        return subtreeSum;
    }
};
