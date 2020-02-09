/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Root pointer of the tree 
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
 struct StackNode { 
    treenode* data; 
    struct StackNode* next; 
}; 
  
struct StackNode* newNode(treenode* data) 
{ 
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode)); 
    stackNode->data = data; 
    stackNode->next = NULL; 
    return stackNode; 
} 
  
int isEmpty(struct StackNode* root) 
{ 
    return !root; 
} 
  
void push(struct StackNode** root, treenode* data ) 
{ 
    struct StackNode* stackNode = newNode(data); 
    stackNode->next = *root; 
    *root = stackNode; 
} 
  
void pop(struct StackNode** root) 
{ 
    struct StackNode* temp = *root; 
    *root = (*root)->next; 
    
    free(temp); 
} 
  
treenode* peek(struct StackNode* root) 
{ 
    if (!isEmpty(root)) 
           return root->data; 
} 
  
int* preorderTraversal(treenode* A, int *len1) {
    treenode* current=A;
   struct StackNode* s=NULL;
     int i=0;
     int* arr=(int*)malloc(sizeof(int)*3000000);
    
    while(!isEmpty(s) || current)
    {
         
        while(current)
        {
            arr[i]=current->val;
        i++;
            push(&s,current);
            current=current->left;
        }
       
        current=peek(s)->right;
        pop(&s);
    }
    *len1=i;
    return arr;
}


