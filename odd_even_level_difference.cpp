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

int getLevelDiff(Node *root);

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
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

   cout<<getLevelDiff(root);
     cout << endl;
  }
  return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*You are required to complete this function*/
int getLevelDiff(Node *root)
{
   queue<Node*> q1 ,q2;
   q1.push(root);
   int sumo=0,sume=0;
   while(!q1.empty() || !q2.empty()){
       while(!q1.empty()){
           Node* current=q1.front();
           if(current->left){
               q2.push(current->left);
           }
           if(current->right){
               q2.push(current->right);
           }
           sumo+=current->data;
           q1.pop();
       }
        while(!q2.empty()){
           Node* current=q2.front();
           if(current->left){
               q1.push(current->left);
           }
           if(current->right){
               q1.push(current->right);
           }
           sume+=current->data;
           q2.pop();
       }
   }
   return (sumo-sume);
}
