class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
           int size = q.size();
        
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                v.push_back(node->val);
                q.pop();
                
                if(node->left!=NULL){
                    q.push(node->left);
                }
                
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            
            ans.push_back(v);
            v.clear();
        }
        
        return ans;  
    }
};