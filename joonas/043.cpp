class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        for (auto& l : lists) {
            for (ListNode* it = l; it; it = it->next) {
                v.push_back(it->val);
            }
        }
        sort(v.begin(), v.end());
        ListNode* l = new ListNode(), *h = l;
        for (int i=0; i<v.size(); ++i) {
            l->next = new ListNode(v[i]);
            l = l->next;
        }
        return h->next;
    }
};