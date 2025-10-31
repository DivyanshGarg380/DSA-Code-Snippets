// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map structure:
        // column (x) → row (y) → multiset of node values (sorted automatically)
        map<int, map<int, multiset<int>>> nodes;

        // Queue for BFS traversal: stores {node, {x, y}} where
        // x = column index (left = x-1, right = x+1)
        // y = row index (top = y, down = y+1)
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}}); // Start from root at position (0,0)

        // ---------- BFS TRAVERSAL ----------
        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();

            int x = pos.first;   // column
            int y = pos.second;  // row

            // Insert node value into the map based on its (x, y) position
            nodes[x][y].insert(node->val);

            // For left child: x-1 (go left), y+1 (go down)
            if (node->left)
                q.push({node->left, {x - 1, y + 1}});

            // For right child: x+1 (go right), y+1 (go down)
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }

        // ---------- BUILD THE FINAL RESULT ----------
        vector<vector<int>> ans;

        // Traverse columns in order (map keeps them sorted automatically)
        for (auto& p : nodes) {
            vector<int> col;

            // For each row in this column, insert all values in sorted order
            for (auto& q : p.second)
                col.insert(col.end(), q.second.begin(), q.second.end());

            // Add this column's nodes to the final answer
            ans.push_back(col);
        }

        return ans;
    }
};

