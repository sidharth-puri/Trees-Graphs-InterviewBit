/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* construct(vector<int> in,vector<int> pre,int inS,int inE,int preS,int preE){
     if(inS>inE){
         return NULL;
     }
     int rootnode=pre[preS];
     int i;
     int rootindex=-1;
     for(i=inS;i<=inE;i++){
         if(in[i]==rootnode){
             rootindex=i;
             break;
         }
     }
     int inLs=inS;
     int inLe=rootindex-1;
     int inRs=rootindex+1;
     int inRe=inE;
     int preLs=preS+1;
     int preLe=inLe-inLs + preLs;
     int preRs=preLe+1;
     int preRe=preE;
     TreeNode* root=new TreeNode(rootnode);
     root->left=construct(in,pre,inLs,inLe,preLs,preLe);
     root->right=construct(in,pre,inRs,inRe,preRs,preRe);
     return root;
 }
TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &in) {
    return construct(in,pre,0,in.size()-1,0,pre.size()-1);
}
