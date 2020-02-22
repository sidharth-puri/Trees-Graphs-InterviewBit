/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Root pointer of the tree 
 * 
 * @Output Integer
 */
int maxDepth(treenode* A) {
    if(A==NULL)
    {
        return 0;
    }
    int l=maxDepth(A->left);
    int r=maxDepth(A->right);
    if(l>r)
    {
        return l+1;
    }
    else
    {
        return r+1;
    }
}
