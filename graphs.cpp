/*
    1. BFS
    Time Complexity: O(V+E), where V is the number of nodes and E is the number of edges.
    Auxiliary Space: O(V)

vector<int> bfsOfGraph(int V, vector<int> adj[]) 
{
    vector<int> visited(V);
    visited[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> ans;
    while(!q.empty())
    {
        int frontNode=q.front();
        ans.push_back(frontNode);
        q.pop();
        for(i:adj[frontNode])
        {
            if(!visited[i])
            {
                visited[i]=1;
                q.push(i);
            }
        }
    }
    return ans;
}

    2.DFS
    Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
    Auxiliary Space: O(V + E), since an extra visited array of size V is required, And stack size for iterative call to DFS function.

void dfs(int s, vector<int> g[], bool vis[])
{
    stack<int>st;
    int e,flag,i;
    st.push(s);
    cout<<s<<" ";
    vis[s]=1;
    while(!st.empty())
    {
        e=st.top();
        flag=0;
        for(i=0;i<g[e].size();i++)
        {
            if(vis[g[e][i]]!=1)
            {
                st.push(g[e][i]);
                cout<<g[e][i]<<" ";
                vis[g[e][i]]=1;
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            st.pop();
        }
    }
}

    3. Dijkstra's Algorithm
    Time Complexity: O(V2)
    Auxiliary Space: O(V)
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)//V is no of vertices, S is source, adj is adjadency list..
{
    vector<int>dist(V,INT_MAX);
    //priority_queue<pair<int,int>,vector<pair<int,int>>greater<pair<int,int>>>q;
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
    q.push({S,0});
    dist[S]=0;
    while(!q.empty())
    {
        int src=q.top().first;
        int weight=q.top().second;
        q.pop();
        for(auto x:adj[src])
        {
            int edge=x[1];
            int adjNode=x[0];
            if(dist[adjNode]>edge+weight)
            {
                dist[adjNode]=edge+weight;
                q.push({adjNode,dist[adjNode]});
            }
        }
    }
    return dist;
}
    4. Topological Sort->only for Directed Acyclic Graph;//Also known as Kahn's algorithm for topological sort
    Time Complexity: O(V+E). The outer for loop will be executed V number of times and the inner for loop will be 
    executed E number of times. 
    
    Auxiliary Space: O(V). The queue needs to store all the vertices of the graph. So the space required is O(V)

vector<int> topoSort(int N, vector<int> adj[]) 
{
    queue<int>q;
    vector<int>indegree(N,0),topo;
    int i;
    for(i=0;i<N;i++)
    {
        for(auto x:adj[i])
        {
            indegree[x]++;
        }
    }
    for(i=0;i<N;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto x:adj[node])
        {
            indegree[x]--;
            if(indegree[x]==0)
            {
                q.push(x);
            }
        }
        
    }
    return topo;
    // code here
}
    5. Floyd Warshall
    Time Complexity: O(V3), where V is the number of vertices in the graph and we run three nested loops each of size V
    Auxiliary Space: O(V2), to create a 2-D matrix in order to store the shortest distance for each pair of nodes.

void floydWarshall(int dist[][V])
{
 
    int i, j, k;
    for (k = 0; k < V; k++) 
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) 
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INT_MAX
                        && dist[i][k] != INT_MAX))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    // Print the shortest distance matrix
    printSolution(dist);
}

    5.Lee's Algorithm//shortest dist from one point to another using bfs
Time complexity: O(M*N)
Auxiliary Space: O(M*N)

bool isValid(int i, int j, int N, int M, vector<vector<bool>>&vis,vector<vector<int>>&A)
{
    if(i<0 ||j<0 ||i>=N || j>=M || vis[i][j] ||A[i][j]==0)
    {
        return false;
    }
    return true;
}
int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) 
{
    vector<vector<bool>>vis(N,vector<bool>(M,false));
    queue<pair<pair<int,int>,int>>coordinates;
    int dist=0;
    
    if(A[0][0]!=1 || A[X][Y]!=1)//if src or dest is not 1;
    {
        return -1;
    }
    coordinates.push({{0,0},dist});
    vis[0][0]=true;
    while(!coordinates.empty())
    {
        int i=coordinates.front().first.first;
        int j=coordinates.front().first.second;
        int currdist=coordinates.front().second;
        //cout<<"Curr dist right :"<<dist<<" i :"<<i<<" j :"<<j<<endl;
        coordinates.pop();
        if(X==i&&Y==j)
        {
            //cout<<"final dist :"<<dist<<endl;
            return currdist;
        }
        
        if(isValid(i-1,j,N,M,vis,A))//up
        {
            coordinates.push({{i-1,j},currdist+1});
            vis[i-1][j]=true;
            //cout<<"Curr dist up :"<<dist<<" i :"<<i<<" j :"<<j<<endl;
        }
        if(isValid(i,j-1,N,M,vis,A))//left
        {
            coordinates.push({{i,j-1},currdist+1});
            vis[i][j-1]=true;
            //cout<<"Curr dist left :"<<dist<<" i :"<<i<<" j :"<<j<<endl;
        }
        if(isValid(i+1,j,N,M,vis,A))//down
        {
            coordinates.push({{i+1,j},currdist+1});
            vis[i+1][j]=true;
            //cout<<"Curr dist down :"<<dist<<" i :"<<i<<" j :"<<j<<endl;
        }
        if(isValid(i,j+1,N,M,vis,A))//right
        {
            coordinates.push({{i,j+1},currdist+1});
            vis[i][j+1]=true;
            //cout<<"Curr dist right :"<<dist<<" i :"<<i<<" j :"<<j<<endl;
        }
    }
    return -1;
    // code here
}
*/