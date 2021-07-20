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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr, *t = new ListNode(INT_MAX), *p, *cur;
        int pos;
        bool flag = true;

        while(flag){
            p = t, flag = false;

            for(int i=0; i<lists.size(); i++){
                if(lists[i] != nullptr && lists[i]->val < p->val){
                    p = lists[i];
                    pos = i;
                    flag = true;
                }
            }

            if(flag){
                lists[pos] = p->next;
                if(head == nullptr){
                    head = p;
                    head->next = nullptr;
                    cur = head;
                }
                else{
                    cur->next = p;
                    cur = p;
                    cur->next = nullptr;
                }
            }
        }
        return head;
    }
};