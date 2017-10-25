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
        if(l1->val==0) return l2;
        if(l2->val==0) return l1;
        ListNode *l1head=l1;
        ListNode *l2head=l2;
        vector<int> nums1;
        vector<int> nums2;
        while(l1head)
        {
            nums1.push_back(l1head->val);
            l1head=l1head->next;
        }
        while(l2head)
        {
            nums2.push_back(l2head->val);
            l2head=l2head->next;
        }
        int i=nums1.size()-1;
        int j=nums2.size()-1;
        int k=i>j?i:j;
        int lengthK=k;
        int mark=0;
        vector<int> result;
        int addNum=0;int carry=0;int remainder=0;
        while(i>=0&&j>=0)
        {
            addNum=nums1[i]+nums2[j]+carry;
            if(addNum>=10)
            {
                carry=1;
                remainder=addNum-10;
                result.push_back(remainder);
                i--;
                j--;
                k--;
            }
            else
            {
                carry=0;
                result.push_back(addNum);
                i--;
                j--;
                k--;
            }
            
        }
        if(i==j&&carry==1)
        {
            result.push_back(carry);
            mark=1;
        }
        while(k>=0)
        {
            if(i<0)
            {
                addNum=carry+nums2[j];
                if(addNum>=10)
                {
                    carry=1;
                    remainder=addNum-10;
                    result.push_back(remainder);
                    k--;
                    j--;
                }
                else
                {
                    carry=0;
                    result.push_back(addNum);
                    k--;
                    j--;
                }
                
            }
            if(j<0&&i>=0)
            {
                addNum=carry+nums1[i];
                if(addNum>=10)
                {
                    carry=1;
                    remainder=addNum-10;
                    result.push_back(remainder);
                    k--;
                    i--;
                }
                else
                {
                    carry=0;
                    result.push_back(addNum);
                    k--;
                    i--;
                }
               
            }
        }
        if(carry==1&&mark!=1)
        {
            result.push_back(carry);
        }
        ListNode *head;
        if(nums1.size()>nums2.size())
            head=l1;
        else
            head=l2;
        ListNode* resulthead=head;
        int m=result.size()-1;
        while(head->next!=NULL)
        {
              head->val=result[m];
              head=head->next; 
              m--;
        }
        if(m==0)
        {
            head->val=result[m];
            return resulthead;  
        }
        else
        {
            head->val=result[1];
            head->next=new ListNode(result[0]);
            return resulthead;  
        }
          
    }
};
