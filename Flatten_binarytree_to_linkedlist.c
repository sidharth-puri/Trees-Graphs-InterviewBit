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
 * @Output root pointer of tree.
 */
 void flat(treenode* A)
 {
     if(A==NULL || A->left==NULL && A->right==NULL){
        return;
    }
    if(A->left!=NULL){
     flat(A->left); 
     treenode* temp=A->right;
     A->right=A->left;
     A->left=NULL;
     treenode* t=A->right;
     while(t->right!=NULL){
         t=t->right;
     }
     t->right=temp;
    }
    flat(A->right);
 }
treenode* flatten(treenode* A) {
    flat(A);
    return A;
}
