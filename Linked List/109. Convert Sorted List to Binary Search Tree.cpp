/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        //if(head) return NULL;
        vector<int> nums;
        while(head)
        {
            nums.push_back(head->val);
            head=head->next;
        }
        return CreatTreeNode(nums,0,nums.size()-1);
    }
    
    TreeNode * CreatTreeNode(vector<int> &nums,int left,int right)
    {
        if(left>right) return NULL;
        int mid=(left+right)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=CreatTreeNode(nums,left,mid-1);
        root->right=CreatTreeNode(nums,mid+1,right);
        return root;
    }    
    
};
