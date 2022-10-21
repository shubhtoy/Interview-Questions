class Solution {
public:
    struct Node{
        unordered_set<Node*> kids;
        int val;
        Node(int val) : val(val){}
    };
    
    vector<int> res;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        res.clear();
        if(nums.empty()) return res;
        Node* root = new Node(1);   // 'assume' we have a 1 in nums
        for(int num : nums){
            Node* curr = new Node(num);
            update(root, curr);
        }
        vector<int> subset;
        dfs(root, subset);
        if(nums[0] == 1) return res;    // assumption is valid
        for(int i = 0; i != res.size(); ++i){    // else we know nums doesn't have a 1
            if(res[i] == 1){
                res.erase(res.begin() + i); // erase from answer
                break;
            } 
        }
        return res;
    }
    
    void dfs(Node* root, vector<int>& subset){
        subset.push_back(root->val);
        if(root->kids.empty()){ // reached the end of the line
            if(subset.size() > res.size()) res = subset;    // compare line sizes
        }
        for(auto kid : root->kids)
            dfs(kid, subset);
        subset.pop_back();
    }
    
    bool update(Node* root, Node* curr){    // update the poset
        int num = curr->val, rum = root->val;
        if(num % rum != 0 || num == rum) return false;    // cannot be a member of root's descendants
        bool found = false; 
        for(auto kid : root->kids)
            if(update(kid, curr))
                found = true;   // curr is divisible by at least one of root's kids
        if(!found) root->kids.insert(curr); // only insert if root is the 'last' node that divides curr
            
        return true;
    }
};
