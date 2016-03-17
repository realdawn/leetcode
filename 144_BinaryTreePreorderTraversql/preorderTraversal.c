/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
        int* leftReturnSize = (int *)malloc(sizeof(int));
        int* rightReturnSize = (int *)malloc(sizeof(int));
        int* leftReturnArray;
        int* rightReturnArray;
        int* returnArray;
        int i,j;
        if (root == NULL)
        {   
                *returnSize = 0;
                return NULL;    
        } else {
                leftReturnArray = preorderTraversal(root->left, leftReturnSize);    
                rightReturnArray = preorderTraversal(root->right, rightReturnSize);
                returnArray = (int *)malloc( (1 + *leftReturnSize + *rightReturnSize) * sizeof(int));  
                returnArray[0] = root->val;    
                for (i = 0 , j = 1; i < *leftReturnSize; i++, j++) {
                        returnArray[j] = leftReturnArray[i];
                }   
                free(leftReturnSize);
                if (leftReturnArray != NULL) {
                        free(leftReturnArray);
                }   
                for (i = 0; i < *rightReturnSize; i++, j++) {
                        returnArray[j] = rightReturnArray[i];
                }   
                if (rightReturnArray != NULL) {
                        free(rightReturnArray);
                }   
                free(rightReturnSize);
                *returnSize = j;
                return returnArray;
        } 
}
