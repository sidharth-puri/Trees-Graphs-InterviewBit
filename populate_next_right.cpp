/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 /*
void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*>q;
q.push(A);
q.push(NULL);

while(!q.empty())
{

    TreeLinkNode* current=q.front();
    q.pop();
    if(current!=NULL)
    {
        current->next=q.front();
     
    
        if(current->left)
        {
            q.push(current->left);
        }
        if(current->right)
        {
            q.push(current->right);
        }
   // printf("%d",current->val);
    }
    else if(!q.empty())
    {
        q.push(NULL);
    }
}
}*/
void Solution::connect(TreeLinkNode* A){
    queue<TreeLinkNode*> q1,q2;
    q1.push(A);
    while(!q1.empty() || !q2.empty()) {
       
        while(!q1.empty()){
            TreeLinkNode*  current=q1.front();
            if(current->left)
            q2.push(current->left);
            if(current->right)
            q2.push(q1.front()->right);
            q1.pop();
            if(q1.empty()){
                current->next=NULL;
            }
            else
            current->next=q1.front();
        }
     
          while(!q2.empty()){
           TreeLinkNode*   current=q2.front();
            if(current->left)
            q1.push(current->left);
            if(current->right)
            q1.push(current->right);
            q2.pop();
            if(q2.empty()){
                current->next=NULL;
            }
            else
             current->next=q2.front();
        }
    
    }
}
