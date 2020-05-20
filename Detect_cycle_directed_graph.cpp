bool DFS(int s,vector<int> adj[],bool visited[],bool stack[]) {
    visited[s]=true;
    stack[s]=true;
    vector<int>::iterator i;
    for(i=adj[s].begin();i<adj[s].end();i++) {
        if(!visited[*i]){
           if( DFS(*i,adj,visited,stack) )
            return true;
        }
        else if(stack[*i]){
            return true;
        }
    }
    stack[s]=false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
   bool visited[V];
   bool stack[V];
   int i;
   for(i=0;i<V;i++) {
       visited[i]=0;
       stack[i]=0;
   }
   for(i=0;i<V;i++) {
       if(!visited[i]) {
          if( DFS(i,adj,visited,stack) )
           return true;
       }
   }
   return false;
}
