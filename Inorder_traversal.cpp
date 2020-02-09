/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<int>s;
    vector<int>v;
    int i=0;
    TreeNode* current=A;
    while(!s.empty() || current)
    {
        while(current)
        {
            s.push(current);
            current=current.left;
        }
        v[i]=s.top().data;
        i++;
        current=s.top().right;
        s.pop();
    }
}
