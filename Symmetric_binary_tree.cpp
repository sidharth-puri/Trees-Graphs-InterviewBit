/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int symmetric(TreeNode* A,TreeNode* B){
     if(A==NULL && B==NULL){
         return 1;
     }
     if(A!=NULL && B==NULL){
         return 0;
     }
     if(A==NULL && B!=NULL){
         return 0;
     }
     if(A->val==B->val && symmetric(A->left,B->right) && symmetric(A->right,B->left)){
         return 1;
     }
     else {
         return 0;
     }
 }
int Solution::isSymmetric(TreeNode* A) {
    if(A==NULL){
        return 0;
    }
    return symmetric(A->left,A->right);
}
