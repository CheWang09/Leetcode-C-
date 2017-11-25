/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
         vector<ListNode*> res;
        if(root==NULL||root->next==NULL) 
        {
            res.push_back(root);
            while(res.size()<k)
            {
                res.push_back({NULL});
            }
            return res;
        }
        ListNode* Lop=root;
        int length=1;
        while(Lop->next!=NULL)
        {
            ++length;
            Lop=Lop->next;
        }
        int Num_each_part=length/k;
        int remainder=length%k;
        //ListNode* part[k];
        ListNode* newhead=root;
        while(newhead!=NULL)
        {
            int size=remainder-- >0?Num_each_part+1:Num_each_part;
            ListNode *head=newhead, *prev=nullptr, *curr=newhead;
            for (int j=0; j<size; ++j){
                prev=curr;
                curr=curr->next;
            }
            prev->next=nullptr;
            newhead=curr;
            res.push_back(head);
        }
        while(res.size()<k)
        {
            res.push_back({NULL});
        }
        return res;
        
        
    }
};
