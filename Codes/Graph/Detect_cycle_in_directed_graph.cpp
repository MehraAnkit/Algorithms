//DFS CODE

class Solution {
    private:
    bool dfs(int src, vector<int> adj[], vector<int> &vis, vector<int> &pathVis){
        vis[src]=1;
        pathVis[src]=1;
        for(auto ele: adj[src]){
            if(vis[ele]==0){
                if(dfs(ele,adj, vis,pathVis)==true){
                    return true;
                }
            }else if(pathVis[ele]==1){
                return true;
            }
        }
        pathVis[src]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0),pathVis(V, 0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(dfs(i,adj, vis, pathVis)==true){
                    return true;
                }
            }
        }
        return false;
    }
};


//BFS CODE

class Solution {
    private:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V, 0),sol;
	    vector<int> ind(V, 0);
	    
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            ind[adj[i][j]]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(ind[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        sol.push_back(node);
	        for(auto ele: adj[node]){
	            ind[ele]--;
	            if(ind[ele]==0){
	                q.push(ele);
	            }
	        }
	    }
	    return sol;
	}
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0),temp;
        temp=topoSort(V,adj);
        if(temp.size()==V){
            return false;
        }
        return true;
    }
};
