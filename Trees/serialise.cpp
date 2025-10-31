// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Codec {
public:

    // ---------- SERIALIZE FUNCTION ----------
    // Converts the binary tree into a string representation.
    string serialize(TreeNode* root) {
        // Base case: if node is null, return "null," to mark no child
        if (!root) return "null,";

        // Convert current node value to string and recursively serialize
        // left and right subtrees.
        // Format: "value,left_subtree,right_subtree"
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // ---------- DESERIALIZE HELPER ----------
    // Helper function that reconstructs the tree using preorder traversal.
    TreeNode* deserializeHelper(queue<string>& nodes) {
        // Get the current node value from the queue
        string val = nodes.front();
        nodes.pop();

        // If the value is "null", there is no node here (base case)
        if (val == "null") return nullptr;

        // Create a new tree node with the current value
        TreeNode* root = new TreeNode(stoi(val));

        // Recursively build the left and right subtrees
        root->left = deserializeHelper(nodes);
        root->right = deserializeHelper(nodes);

        return root;
    }

    // ---------- DESERIALIZE FUNCTION ----------
    // Converts a serialized string back into the original binary tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);   // Use stringstream to split string by commas
        string val;
        queue<string> nodes;     // Store each value (including "null") in a queue

        // Extract all comma-separated values into the queue
        while (getline(ss, val, ',')) {
            nodes.push(val);
        }

        // Reconstruct tree using the helper function
        return deserializeHelper(nodes);
    }
};

