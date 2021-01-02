class Solution {
public:
    bool isMirror(TreeNode* tree1, TreeNode* tree2){
        if(tree1==NULL && tree2==NULL) return true;
        if(tree1==NULL || tree2==NULL) return false;
        if(tree1->val!=tree2->val) return false;
        
        return isMirror(tree1->left, tree2->right) && isMirror(tree1->right, tree2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};