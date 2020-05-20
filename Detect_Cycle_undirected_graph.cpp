bool DFS(int s,vector<int> adj[],bool visited[],int parent) {
    visited[s]=true;
    vector<int>::iterator i;
    for(i=adj[s].begin();i<adj[s].end();i++) {
        if(!visited[*i]){
           if( DFS(*i,adj,visited,s) )
            return true;
        }
        else if(*i!=parent){
            return true;
        }
    }
    return false;
}
bool isCyclic(vector<int> adj[], int V)
{
   bool visited[V];
   int i;
   for(i=0;i<V;i++) {
       visited[i]=0;
   }
   for(i=0;i<V;i++) {
       if(visited[i]==false) {
          if( DFS(i,adj,visited,-1) )
           return true;
       }
   }
   return false;
}

//Get the stub from geeksforgeeks compilor.
