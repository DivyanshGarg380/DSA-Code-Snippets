class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    TreeNode* deserializeHelper(queue<string>& nodes) {
        string val = nodes.front(); nodes.pop();
        if (val == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(nodes);
        root->right = deserializeHelper(nodes);
        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        queue<string> nodes;
        while (getline(ss, val, ',')) nodes.push(val);
        return deserializeHelper(nodes);
    }
};
