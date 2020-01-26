/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int height(TreeNode* root){
     if(root==NULL){
         return 1;
     }
    int l=height(root->left);
    int r=height(root->right);
    if(l>r){
        return l+1;
    }
    else {
        return r+1;
    }
 }
int Solution::isBalanced(TreeNode* A) {
    if(A==NULL){
        return 1;
    }
    int l=height(A->left);
    int r=height(A->right);
    int x=abs(l-r);
    if(x<=1 && isBalanced(A->left) && isBalanced(A->right)){
        return 1;
    }
    else {
        return 0;
    }
}
