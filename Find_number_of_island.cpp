int isSafe(vector<int> A[], int row , int col , int n, int m,vector<vector<int>> &visited) {
    if((row>=0) && (row<n) && (col>=0) && (col<m) && (!visited[row][col] && A[row][col])) {
        return 1;
    }
    else 
    return 0;
}

void DFS(vector<int> A[],int row,int col,int n,int m,vector<vector<int>> &visited) {
    static int rownbr[]={-1, -1, -1, 0, 0, 1, 1, 1 };
    static int colnbr[]={-1, 0, 1, -1, 1, -1, 0, 1 };
    int i;
    visited[row][col]=1;
    for(i=0;i<8;i++) {
        if(isSafe(A,row+rownbr[i],col+colnbr[i], n, m,visited)) {
            DFS(A,row+rownbr[i],col+colnbr[i],n,m,visited);
        }
    }
}

int findIslands(vector<int> A[], int n, int m) {
     vector<vector<int> > visited( n , vector<int> (m, 0));  
     int i,j,count=0;
   
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(!visited[i][j] && A[i][j]) {
                DFS(A,i,j,n,m,visited);
                count++;
            }
        }
    }
    return count;
}
