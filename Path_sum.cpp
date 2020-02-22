/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* A, int sum) {
    if(A==NULL){
        if(sum==0){
            return 1;
        }
        else {
            return 0;
        }
    }
    sum-=A->val;
    int ans=0;
    if(sum==0 && A->left==NULL && A->right==NULL){
        return 1;
    }
    
    ans=ans||  hasPathSum(A->left,sum) ;
    ans=ans||  hasPathSum(A->right,sum);
    return ans;
}
