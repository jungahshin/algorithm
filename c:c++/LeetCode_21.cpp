class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // int idx = 0;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        if(l1==NULL || l2==NULL){
            if(l1==NULL){
                return l2;
            }else{
                return l1;
            }
        }
        
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL && l2!=NULL){
                if((l1->val)<(l2->val)){
                    curr->val = l1->val;
                    l1 = l1->next;
                }else{
                    curr->val = l2->val;
                    l2 = l2->next;
                }                
            }else{
                if(l1!=NULL){
                    curr->val = l1->val;
                    l1 = l1->next;
                }else{
                    curr->val = l2->val;
                    l2 = l2->next;
                }
            }
 
            if(l1==NULL && l2==NULL){
                break;
            }
            
            curr->next = new ListNode();
            curr = curr->next;
        }
        
        return dummy;
    }
};