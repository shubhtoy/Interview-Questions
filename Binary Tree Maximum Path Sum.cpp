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
    int maxPathSum(TreeNode* root) {
        int ans=-INT32_MAX;
        height(root,ans);
        return ans;
        
    }
      int height(TreeNode* root,int &ans){
        
        if(root==NULL)
            return 0;
        int l=height(root->left,ans);
        int r=height(root->right,ans);
        int temp=max(root->val,root->val+max(l,r));
        ans=max({ans,temp,root->val+l+r});
        return temp;
    
    }
};
