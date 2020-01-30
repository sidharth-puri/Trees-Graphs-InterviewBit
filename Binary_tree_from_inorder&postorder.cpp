/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* construct(vector<int> &in,vector<int> &pos,int inS,int inE,int posS,int posE){
     if(inS>inE){
         return NULL;
     }
     int i,rootindex=0,root=pos[posE];
     for(i=inS;i<=inE;i++){
         if(root==in[i]){
            rootindex=i;
            break;
         }
     }
     int inLs=inS;
     int inLe=rootindex-1;
     int inRs=rootindex+1;
     int inRe=inE;
     int posLs=posS;
     int posLe=posLs + inLe - inLs;
     int posRs=posLe+1;
     int posRe=posE-1;
     TreeNode* node=new TreeNode(root);
     node->left=construct(in,pos,inLs,inLe,posLs,posLe);
     node->right=construct(in,pos,inRs,inRe,posRs,posRe);
     return node;
 }
TreeNode* Solution::buildTree(vector<int> &in, vector<int> &pos) {
    return construct(in,pos,0,in.size()-1,0,pos.size()-1);
}
