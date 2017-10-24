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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode SumLs(0), *p=&SumLs;
        int carry=0;
        //int result=0;
        while(l1||l2)
        {
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
            carry=sum/10;
            //result=sum%10;
            p->next=new ListNode(sum%10);
            p=p->next;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        }
        if(carry>0)
        {
            p->next=new ListNode(carry);
        }
        return p;
    }
};