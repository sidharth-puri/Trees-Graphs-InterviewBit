
treenode* getSuccessor(treenode* A, int B) {
    treenode* prev=NULL;
    treenode* current=A;
    while(current!=NULL){
        if(current->val>B){
            prev=current;
            current=current->left;
        }
        else {
            current=current->right;
        }
    }
    return prev;
}
