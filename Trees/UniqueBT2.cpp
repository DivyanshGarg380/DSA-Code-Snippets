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

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return build(1, n);
    }

    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> res;
        if(start > end) {
            res.push_back(NULL);
            return res;
        }

        for(int i = start; i <= end; i++){
            vector<TreeNode*> left = build(start, i -1);
            vector<TreeNode*> right = build(i+1, end);

            for(auto it : left){
                for(auto jt : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = it;
                    root->right = jt;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};


// TC: Catalan Number O((2n)!/((n+1)!n!))
// SC: O(N) for recursion stack + O(N) for each tree in vector