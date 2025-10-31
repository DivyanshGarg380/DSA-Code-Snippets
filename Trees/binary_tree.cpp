#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int ans = INT_MIN;  // Global variable to store the maximum path sum

    // Helper function: performs DFS and returns the maximum sum path *ending* at this node
    int dfs(TreeNode* root) {
        // Base case: if node is null, return 0 (no contribution to path sum)
        if (!root) return 0;

        // Recursively find the maximum sum path from left and right subtrees
        // If a subtree gives a negative sum, ignore it (take max with 0)
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Update global answer:
        // current node value + best path from left + best path from right
        ans = max(ans, root->val + left + right);

        // Return the best single path going *upward* from current node
        // (You can’t take both sides when going upward)
        return root->val + max(left, right);
    }

public:
    // Main function to get the maximum path sum in the binary tree
    int maxPathSum(TreeNode* root) {
        dfs(root);  // Run DFS to calculate and update ans
        return ans; // Return the maximum path sum found
    }
};

