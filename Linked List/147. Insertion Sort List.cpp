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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL) 
        {
            return head;
        }
        ListNode * Curhead=head;
        ListNode * Afthead=head;
        Curhead=Curhead->next;
        Afthead->next=NULL;
        while(Curhead!=NULL)
        {
            ListNode *temp=Curhead;
            Curhead=Curhead->next;
            ListNode *AftCurPos=Afthead;
            ListNode *AftPrePos=Afthead;
            while(AftCurPos!=NULL)
            {
                if(Afthead->val>=temp->val)
                {
                    temp->next=Afthead;
                    Afthead=temp;
                    break;
                }
                if(AftCurPos->next==NULL&&temp->val>=AftCurPos->val)
                {
                    AftCurPos->next=temp;
                    temp->next=NULL;
                    break;
                }
                if(AftCurPos->val<temp->val)
                {
                    AftPrePos=AftCurPos;
                    AftCurPos=AftCurPos->next;
                    continue;
                }
                else
                {
                    AftPrePos->next=temp;
                    temp->next=AftCurPos;
                    break;
                }
            }
        }
        
        return Afthead;                                                                                                
        }               
    
};
