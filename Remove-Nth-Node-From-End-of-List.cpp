class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode* temp = head;
        while(temp){
            ++cnt;
            temp = temp->next;
        }
        if(cnt==1)
            return NULL;
        if(cnt-n==0){
            head = head->next;
            return head;
        }
        temp = head;
        int i=0;
        while(i<(cnt-n)-1){
            temp = temp->next;
            ++i;
        }
        temp->next = temp->next->next;
        return head;
    }
};
