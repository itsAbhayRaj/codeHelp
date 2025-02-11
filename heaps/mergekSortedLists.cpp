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
    static bool compare(ListNode* a , ListNode* b){
    return a->val < b->val;
}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         int n = lists.size();
    vector<ListNode*> result;
    for(int i =0;i<n;i++){
        ListNode* t = lists[i];
        while(t!=NULL){
            result.push_back(t);
            t = t->next;
        }
    }
    if(result.empty())return NULL;
    sort(result.begin(),result.end(),compare);
    ListNode* head = result[0];
    ListNode* tail = head;
    for(ListNode* t : result){
        tail -> next = t;
        tail = t;
    }
    tail->next = NULL;
    return head;
    }
};






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
 

 #include <queue>
 class Solution {
     public:
     struct compare{
         bool operator()(ListNode* a , ListNode* b){
     return a->val > b->val;
         }
 };
 public:
     ListNode* mergeKLists(vector<ListNode*>& lists) {
         priority_queue<ListNode*,vector<ListNode*> , compare>pq;
          int n = lists.size();
     for(int i =0;i<n;i++){
         if(lists[i])
         pq.push(lists[i]);
     }
     ListNode* head  = new ListNode(-1);
     ListNode* tail = head;
     while(!pq.empty()){
         tail->next = pq.top();
         pq.pop();
         tail = tail->next;
         if(tail->next){
             pq.push(tail->next);
         }
     }
     tail->next = NULL;
     return head->next;
     }
 };