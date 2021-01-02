class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 루->왼->오
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->val != q->val) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}