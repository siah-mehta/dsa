/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* next=curr->next;
        int pos=1;
        int first=-1;
        int last=-1;
        int mindist=INT_MAX;
        while(curr->next != nullptr){
            bool critical=(curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val);

            
            if(critical){
                if(first==-1){
                    first=pos;
                    last=pos;
                }
                else{
                    mindist=min(mindist,pos-last);
                    last=pos;
                }
            }
            pos++;
            prev=curr;
            curr=next;
            next=next->next;
        }
        if(first==-1 || first==last){
            return {-1,-1};
        }
        int maxdist=last-first;
        return {mindist, maxdist};
    }
};