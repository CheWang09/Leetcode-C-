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
        if(!l1) return l1;
        if(!l2) return l2;
        ListNode *l1head=l1;
        ListNode *l2head=l2;
        vector<int> nums1;
        vector<int> nums2;
        while(l1head->next)
        {
            nums1.push_back(l1head->val);
            l1head=l1head->next;
        }
        while(l2head->next)
        {
            nums2.push_back(l2head->val);
            l2head=l2head->next;
        }
        int i=nums1.size()-1;
        int j=nums2.size()-1;
        int k=i>j?i:j;
        int lengthK=k;
        vector<int> result(k+1);
        int addNum=0;int carry=0;int remainder=0;
        while(i>=0||j>=0)
        {
            addNum=nums1[i]+nums2[j]+carry;
            if(addNum>=10)
            {
                carry=1;
                remainder=addNum-10;
                result[k]=remainder;
                i--;
                j--;
                k--;
            }
            else
            {
                carry=0;
                result[k]=addNum;
                i--;
                j--;
                k--;
            }
            
        }
        while(k>=0)
        {
            if(i==0)
            {
                addNum=carry+nums2[j];
                if(addNum>=10)
                {
                    carry=1;
                    remainder=addNum-10;
                    result[k]=remainder;
                    k--;
                    j--;
                }
                else
                {
                    carry=0;
                    result[k]=addNum;
                    k--;
                    j--;
                }
                
            }
            if(j==0)
            {
                addNum=carry+nums1[i];
                if(addNum>=10)
                {
                    carry=1;
                    remainder=addNum-10;
                    result[k]=remainder;
                    k--;
                    i--;
                }
                else
                {
                    carry=0;
                    result[k]=addNum;
                    k--;
                    i--;
                }
               
            }
        }
        ListNode *head;
        if(nums1.size()>nums2.size())
            head=l1;
        else
            head=l2;
        ListNode* resulthead=head;
        for(int m=0;m<=lengthK;m++)
        {
              head->val=result[0];
              head=head->next;
        }
        return resulthead;    
    }
};
