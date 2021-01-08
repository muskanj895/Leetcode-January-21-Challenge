class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* ret = head;
        ListNode* prev = NULL;
        ListNode* cur = head;
        while (cur != NULL) {
            int cnt = 0;
            int val = cur->val;
            while (cur != NULL && cur->val == val) {
                cur = cur->next;
                cnt++;
            }
            if (cnt == 1) {
                ret->val = val;
                prev = ret;
                ret = ret->next;
            }
        }
        if (prev != NULL)
            prev->next = NULL;
        else
            head = NULL;
        return head;
    }
};

 
