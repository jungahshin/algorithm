class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool check = false;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int mok = 0;
        while(l1!=NULL || l2!=NULL){
            int x = (l1!=NULL) ? l1->val : 0;
            int y = (l2!=NULL) ? l2->val : 0;
            int sum = x+y+mok;
            
            if(l1!=NULL){
                l1 = l1->next;
            }
            
            if(l2!=NULL){
                l2 = l2->next;
            }
            curr->val = (sum%10);
            mok = (sum/10);
            if(l1==NULL && l2==NULL) break;
            curr->next = new ListNode();
            curr = curr->next;
        }
        
        if(mok!=0){
            curr->next = new ListNode(mok);
        }
                        
        return dummy;
    }
};