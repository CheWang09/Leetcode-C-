/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        unordered_map<int,int> ans;
        int Fre=0;
        int sum=postorder(root,res,ans,Fre);
        return res;
    }

private:
    int postorder(TreeNode *root,vector<int> &res,unordered_map<int, int>&ans, int &Fre)
    {
        if(root==NULL) return 0;
        int left=postorder(root->left,res,ans,Fre);
        int right=postorder(root->right,res,ans,Fre);
        int sum=left+right+root->val;
        ans[sum]++;
        if(ans[sum]>=Fre)
        {
            if(ans[sum]>Fre)
                res.clear();
            res.push_back(sum);
            Fre=ans[sum];
        }
        return sum;
    }
    
};
