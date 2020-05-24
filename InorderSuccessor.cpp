Node * inOrderSuccessor(Node *root, Node *x)
{
    
   if(root==nullptr)
    {
        return nullptr;
    }
    Node* y=nullptr;
    if(root->data<x->data)
    {
        y=inOrderSuccessor(root->right,x);
    }
    else if(root->data>x->data)
    {
        y=inOrderSuccessor(root->left,x);
        if(y==nullptr)
        y=root;
    }
    else
    {
        y=inOrderSuccessor(root->right,x);
    }
    
    return y;
 
    
}
