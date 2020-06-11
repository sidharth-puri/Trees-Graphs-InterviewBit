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
 * @input B : Integer
 * 
 * @Output root pointer of tree.
 */
treenode* getSuccessor(treenode* A, int B) {
    treenode* prev=NULL;
    treenode* current=A;
    while(current!=NULL){
        if(current->val>B){
            prev=current;
            current=current->left;
        }
        else {
            current=current->right;
        }
    }
    return prev;
}
