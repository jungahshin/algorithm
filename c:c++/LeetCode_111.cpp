class Solution {
public:
    queue<pair<TreeNode*, int>> q;
    int MinLevel = INT_MAX;
    
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        q.push(make_pair(root, 1));
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(node->left==NULL && node->right==NULL){
                MinLevel = min(MinLevel, level);
                break;
            }
            
            if(node->left!=NULL){
               q.push(make_pair(node->left, level+1)); 
            }
            
            if(node->right!=NULL){
                q.push(make_pair(node->right, level+1));
            }
        }
        
        return MinLevel;
    }
};