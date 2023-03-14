/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void preorder(TreeNode *root,int number){
        if(root->left == NULL && root->right == NULL){
            ans += number;
            number = number/10;
            return;
        }
        
        if(root->left){
            preorder(root->left,(number*10) + root->left->val);
        }
        if(root->right){
            preorder(root->right,number*10 + root->right->val);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        preorder(root,root->val);
        return ans;
    }
};


// when a node is leaf node == when node->left == NULL && node->right ==NULL
