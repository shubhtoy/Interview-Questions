class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
   vector<int> v[2000];
        
        vector<vector<int>> res;
        if(root==NULL)
        {
return res;
            
        }
        
        int i=0;
       queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
  
            TreeNode *it=(q.front()).first;
            if(it!=NULL){
            int y=it->val;
            int x=(q.front()).second;
       v[x].push_back(y);
            
            
            
          q.pop();
            if(it->left!=NULL)
            {
                q.push({it->left,x+1});
                
            }
            if(it->right!=NULL)
            {
                q.push({it->right,x+1});
                
            }
            
            }
        }
        for(int i=0;i<2000;i++)
        {
            if(v[i].size()==0)
                break;
            
            vector<int> aux;
            for(int j=0;j<v[i].size();j++)
            {
                aux.push_back(v[i][j]);
                
            }
            res.push_back(aux);
        }
      
        
        
        return res;
    }
};
