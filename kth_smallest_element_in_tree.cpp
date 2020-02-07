/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int nodes(TreeNode* A){
     if(A==NULL){
         return 0;
     }
     return nodes(A->left)+1+nodes(A->right);
 }
 void inorder(int *arr,int *n,TreeNode* A){
     if(A==NULL){
         return;
     }
     inorder(arr,n,A->left);
     arr[*n]=A->val;
     (*n)=(*n)+1;
     inorder(arr,n,A->right);
 }
int Solution::kthsmallest(TreeNode* A, int B) {
    int size=nodes(A);
    int arr[size];
    int n=0;
    inorder(arr,&n,A);
    return arr[B-1];
}
