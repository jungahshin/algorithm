class Solution {
public:
    vector<int> val;
    int first, second;
    
    void InorderTraversal(TreeNode* root){
        if(root==NULL){
            return;
        }    
        
        InorderTraversal(root->left);
        
        val.push_back(root->val);
        
        InorderTraversal(root->right);
    }
    
    void changeValTree(TreeNode *root){
        if(root==NULL){
            return;
        }
        
        changeValTree(root->left);
        
        if((root->val)==first){
            (root->val) = second;
        }else if((root->val)==second){
            (root->val) = first;
        }
        
        changeValTree(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        // Inorder Traversal로 먼저 vector에 값 넣어주고
        // 하나씩 탐색하면서 역전되는 곳 찾기
        // 역전되는 곳 1pair -> 첫 번째 값이 first, 두번째 값이 second
        // 역전되는 곳 2pair -> 첫 번째 pair의 첫 번째 값이 first, 두 번째 pair의 두 번째 값이 second
        
        InorderTraversal(root);
        
        int prev = val[0];
        first = NULL, second = NULL;
        for(int i=1; i<val.size(); i++){
            if(prev>val[i] && first==NULL){
                first = prev;
            }
            
            if(prev>val[i] && first!=NULL){
                second = val[i];
            }
            
            prev = val[i];
        }
                
        changeValTree(root);
    }
};