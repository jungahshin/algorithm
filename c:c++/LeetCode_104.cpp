class Solution {
public:
    int height = 1;
    
    void countMaxHeight(TreeNode* node, int h){
        if(node==NULL){
            height = max(height, h);
            return;
        }
        
        countMaxHeight(node->left, h+1);
        countMaxHeight(node->right, h+1);
    }
    
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        countMaxHeight(root->left, 1);
        countMaxHeight(root->right, 1);
        
        return height;
    }
};