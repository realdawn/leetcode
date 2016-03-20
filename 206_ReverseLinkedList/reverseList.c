/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode *pre=NULL, *now=head, *post;
	if (head == NULL)
		return NULL;
	while (now->next != NULL) {
		post = now->next;
		now->next = pre;
		pre = now;
		now = post;
	}    
	now->next = pre;
	return now;
}
