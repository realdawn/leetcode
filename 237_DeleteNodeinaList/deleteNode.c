/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
        struct ListNode* p;
        struct ListNode* q = node;
        if (node == NULL || node->next == NULL)
                return;
        while ((p = node->next) != NULL)
        {
                node->val = p->val;
                q = node;
                node = node->next;
        }
        q->next = NULL;
        free(node);
}
