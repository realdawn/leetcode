/**

 * Definition for a binary tree node.

 * struct TreeNode {

 *     int val;

 *     struct TreeNode *left;

 *     struct TreeNode *right;

 * };

 */
/* recurse version */
int maxDepth(struct TreeNode* root) {
	int ldep = 0;
	int rdep = 0;
	if (root == NULL)
		return 0;
	if (root->left != NULL)
	{
		ldep = maxDepth(root->left);
	}	
    	if (root->right != NULL)
	{
		rdep = maxDepth(root->right);
	}
	return ldep > rdep ? ldep + 1 : rdep +1;
}
