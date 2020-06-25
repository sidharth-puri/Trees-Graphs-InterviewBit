
int printans(Node* root,int t,int arr[],int *l){
    if(root==NULL){
        return 0;
    }
    if(root->data==t){
        return 1;
    }
    if(printans(root->left,t,arr,l) || printans(root->right,t,arr,l)){
        arr[(*l)]=root->data;
        (*l)=(*l)+1;
        return 1;
    }
    else{
        return 0;
    }
}
bool isCousins(Node *root, int x, int y)
{
    int arr1[1000];
    int arr2[1000];
    int s1=0,s2=0;
    printans(root,x,arr1,&s1);
    printans(root,y,arr2,&s2);
   if(s1<2 || s2<2){
       return 0;
   }
    if(s1==s2 && arr1[s1-3]!=arr2[s1-3]){
        return 1;
    }
    else {
        return 0;
    }
}
// check geeksforgeeks for stub
