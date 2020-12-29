class Solution {
public:
    bool check = true;
    vector<int> v;
    
    // Inorder Traversal
    void Traversal(TreeNode *root){
        if(check==false) return;
        
        if(root->left!=NULL){
            Traversal(root->left);
        }
        
        if(v.size()==0){
            v.push_back(root->val);
        }else{
            if(v[v.size()-1]>=root->val){
                check = false;
                return;
            }else{
                v.push_back(root->val);
            }
        }
        
            
        if(root->right!=NULL){
            Traversal(root->right);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        Traversal(root);       
        
        return check;
    }
};