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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        q.push(root);
        int flip = 0;
        while(!q.empty()){
            int q_size = q.size();
            vector<int> tmp;
            for(int i=0;i<q_size;i++){
                auto x = q.front();q.pop();
                tmp.push_back(x->val);
                if(x->left){
                    q.push(x->left);
                }
                if(x->right){
                    q.push(x->right);
                }
            }
            if(flip == 0){
                ans.push_back(tmp);
            }else{
                reverse(tmp.begin(),tmp.end());
                ans.push_back(tmp);
            }
            
            flip ^=1;
        }
        return ans;
    }
};
