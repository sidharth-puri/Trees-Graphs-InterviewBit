void small(Node* root,int k,int *count,int *num){
    if(root==NULL) {
        return ;
    }
    if(root->left) {
        small(root->left,k,count,num);
    }
    *count=*count+1;
    //cout<<root->data;
    if(*count==k){
    
        *num= root->data;
    }
    if(root->right) {
        small(root->right,k,count,num);
    }
    
}
int KthSmallestElement(Node *root, int k)
{
    int num,count=0;
    
   small(root,k,&count,&num); 
   if(num==0){
       return -1;
   }
   return num;
}
