struct Node {
    int data;
    Node* right;
    Node* left;

};
*/

/*You are required to complete
this function*/
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(root==NULL)
   {
       return root;
   }
   while(root!=NULL)
   {
       // if both are less than root then lca lies in left subtree as soon as we encounter a root having one of the values grater and other lesser than root
       if(n1 < root->data && n2 < root->data)
       {
           root = root->left;
       }
       else if(n1 > root->data && n2 > root->data)
       {
           root = root->right;
       }
       else
       {
           break;
       }
   }
   
   return root;
 
}
