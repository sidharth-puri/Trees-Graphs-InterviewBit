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
int Solution::t2Sum(TreeNode* A, int B) {
     int size=nodes(A);
    int arr[size];
    int n=0;
    inorder(arr,&n,A);
    int l=0;
    int r=n-1;
    while(l<r){
        if(arr[l]+arr[r]==B){
            return 1;
        }
        else if(arr[l]+arr[r]<B){
            l++;
        }
        else {
            r--;
        }
    }
    return 0;
}
