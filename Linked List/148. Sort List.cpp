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
    ListNode* sortList(ListNode* head) {
           if(head==NULL||head->next==NULL)
           {
               return head;
           }
           vector<int> vals;
           ListNode *Cur=head;
           while(Cur->next!=NULL)
           {
               vals.push_back(Cur->val);
               Cur=Cur->next;
           }
           vals.push_back(Cur->val);
           sort(vals.begin(),vals.end());
           ListNode *Sechead=head;
           for(int i=0;i<vals.size();i++)
           {
               Sechead->val=vals[i];
               Sechead=Sechead->next;
           }
           return head;
    }
};
