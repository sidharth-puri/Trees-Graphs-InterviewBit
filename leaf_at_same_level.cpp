using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


bool check(Node* node);

/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     cout << check(root) << endl;
  }
  return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
/*You are required to complete this method*/
int heigh(Node* root){
    if(root==NULL){
        return 0;
    }
    int l=heigh(root->left);
    int r=heigh(root->right);
    if(l>r){
        return l+1;
    }
    else {
        return r+1;
    }
}
int minh(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    if(!root->left){
        return minh(root->right)+1;
    }
    if(!root->right){
        return minh(root->left) +1;
    }
    return min(minh(root->right),minh(root->left))+1;
}
bool check(Node *root)
{
    int m=minh(root);
    int h=heigh(root);
    if(m==h){
        return 1;
    }
    else {
        return 0;
    }
}
