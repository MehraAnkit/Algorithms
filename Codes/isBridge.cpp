class Solution
{
    int visTime=1;
    private:
    bool dfs(int node, vector<int> &vis,int parent, vector<int> adj[], int low[], int tim[], int c, int d){
        vis[node]=1;
        tim[node]=low[node]=visTime;
        visTime++;
        for(auto it: adj[node]){
            if(it==parent){
                continue;
            }
            if(!vis[it]){
                if(dfs(it, vis,node, adj, low, tim, c, d)){
                    return true;
                }
                low[node]=min(low[node], low[it]);
                //node -----it
                if((tim[node]<low[it]) &&((c==node && d==it) || (c==it && d==node))){
                    return true;
                }
            }else{
                low[node]= min(low[node], tim[it]);
            }
        }
        return false;
    }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        int tim[V];
        int low[V];
        vector<int> vis(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i, vis,-1, adj, low, tim, c, d)){
                    return 1;
                }
            }
        }
        
        return 0;
        
    }
    
};
