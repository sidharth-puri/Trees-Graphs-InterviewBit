/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* invert(TreeNode* A){
    if(A==NULL){
        return NULL;
    }
    invert(A->left);
    invert(A->right);
    TreeNode* temp;
    temp=A->right;
    A->right=A->left;
    A->left=temp;
    return A;
 }
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL){
        return NULL;
    }
    return invert(A);
}
