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
    int bfs(TreeNode* root){
        queue<TreeNode*> q;
        if(root == NULL){
            return 0;
        }
        q.push(root);
        int level =0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* ele = q.front();q.pop();
                if(ele->right){
                    q.push(ele->right);
                }
                if(ele->left){
                    q.push(ele->left);
                }
            }
            level++;
        }
        return level;
    }
    int maxDepth(TreeNode* root) {
        return bfs(root);
    }
};
