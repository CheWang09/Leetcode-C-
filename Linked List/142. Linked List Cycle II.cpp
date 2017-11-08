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
    ListNode *detectCycle(ListNode *head) {
        if(!head)  
        return NULL;  
        ListNode *Fast = head;  
        ListNode *Slow = head;  
  
        do {  
            if(!Fast||!Slow)   
                return NULL;//If LinkNode exist NULL node,then return NULL  
            Fast = Fast->next;  
            Slow = Slow->next;  
            if(Fast)   
                Fast = Fast->next;  
            else   
                return NULL;//If LinkNode exist NULL node,then return NULL
        }while(Fast!=Slow);  
  
        Slow = head;  
        while(Slow!=Fast) {  
            Fast = Fast->next;  
            Slow = Slow->next;  
        }  
        return Slow;  
       
    }
};
