class Solution {
public:
    void Traversal(vector<vector<int>> &ans, TreeNode* node, int level){
        if(node==NULL){
            return;
        }

// 새로운 level에 도달했을 때 새로운 배열을 생성해서 넣어준다.
        if(level==ans.size()){
            ans.push_back({});
        }
        
        ans[level].push_back(node->val);
        Traversal(ans, node->left, level+1);
        Traversal(ans, node->right, level+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        Traversal(ans, root, 0);
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};