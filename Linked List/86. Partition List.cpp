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
    ListNode* partition(ListNode* head, int x) {
        ListNode *Newhead=new ListNode(0);
        Newhead->next=head;
        ListNode *Cur=Newhead;
        ListNode *pre,*pos;
        while(Cur->next!=NULL&&Cur->next->val<x)
            Cur=Cur->next;
        pre=Cur;
        pos=Cur->next;
        while(Cur->next!=NULL)
        {
            if(Cur->next->val>=x)
            {
                Cur=Cur->next;
            }
            else
            {
                pre->next=Cur->next;
                pre=pre->next;
                Cur->next=Cur->next->next;
                pre->next=pos;
            }
        }
        
        return Newhead->next;
    }
};





///Slolution first try.and has some preoblems need to be fixed.
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
    ListNode* partition(ListNode* head, int x) {
         if(head==NULL||head->next==NULL) 
        {
            return head;
        }
        ListNode *Prehead=NULL;
        ListNode *Lfthead=NULL;
        ListNode *CurPhead=head;
        ListNode *CurLhead=head;
        ListNode *First;
        ListNode *Last;
        ListNode *Res;
        while(CurPhead!=NULL)// the privous part of the result linked list
        {
            if(CurPhead->val<x)
            {
                if(Prehead==NULL)//Process the first element 
                {
                    Prehead=CurPhead;
                    Res=Prehead;
                }   
                else
                {
                      Prehead->next=CurPhead;
                      Prehead=Prehead->next;
                      Prehead->next=NULL;
                      Last=Prehead;     
                }
            }
            CurPhead=CurPhead->next;
        }
        while(CurLhead!=NULL)// the seconde part of the result linked list
        {
            if(CurLhead->val>=x)
            {
                if(Lfthead==NULL)//Process the fist element
                {
                    Lfthead=CurLhead;
                    //First=CurLhead;
                }    
                else
                {
                      Lfthead->next=CurLhead;
                      Lfthead=Lfthead->next;
                      Lfthead->next=NULL;
                      First=Lfthead;
                }
            }
            CurLhead=CurLhead->next;
        }
        
        if(Prehead==NULL)
            return First;
        Last=First;
        return Res;
        
    }
};

//The solution above is wrong with some places.


