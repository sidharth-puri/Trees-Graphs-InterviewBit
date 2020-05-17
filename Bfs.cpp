void bfs(int s, vector<int> g[], vector<bool> &vis, int N) {

    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()) {
    s=q.front();
    cout<<q.front()<<" ";
    q.pop();
    vector<int>:: iterator i;
  
    for(i=g[s].begin();i<g[s].end();i++) {
        if(!vis[*i]) {
              vis[*i]=true;
              q.push(*i);
        }
    }
    }
}


// i have completed the dfs function in geeksforgeeks dfs practice problem.
// see the stud from geekforgeeks.
