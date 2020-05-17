void dfs(int s, vector<int> g[], bool vis[])
{
    
    vis[s]=true;
    cout<<s<<" ";
    vector<int>::iterator i;
    for(i=g[s].begin();i<g[s].end();i++) {
        if(!vis[*i]) {
            dfs(*i,g,vis);
        }
    }

}

// i have completed the dfs function in geeksforgeeks dfs practice problem.
// see the stud from geekforgeeks.
