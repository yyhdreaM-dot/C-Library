/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode list3;
    list3.next = NULL;
    struct ListNode* p = &list3;
    struct ListNode* q1 = list1;
    struct ListNode* q2 = list2;
    while(q1 != NULL && q2 != NULL)
    {
         if(q1 -> val <= q2 -> val)
        {
            p -> next = q1;
            q1 = q1 -> next;
        }
        else
        {
            p-> next = q2;
            q2 = q2 -> next;
        }
        p = p -> next;
    }
   
    if(q2 != NULL)
    {
        p -> next = q2;
    }
    else
    {
        p -> next = q1;
    }
    return list3.next;
}
