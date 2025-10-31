// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    // Function to find the Lowest Common Ancestor (LCA) of two nodes (p and q)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Base case 1: if current node is null, return null
        if (!root) return nullptr;

        // Base case 2: if current node is either p or q, return current node
        // Because one of the nodes itself could be the ancestor
        if (root == p || root == q) return root;

        // Recursively search in the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are not null,
        // it means p and q are found in different subtrees → root is their LCA
        if (left && right) return root;

        // Otherwise, if only one side is non-null, return that side
        // (because both p and q are in the same subtree)
        return left ? left : right;
    }
};

