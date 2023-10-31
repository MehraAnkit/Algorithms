//DFS CODE
class Solution
{
    private:
        void dfs(int src, vector<int> adj[], stack<int> &st, vector<int> &vis, vector<int> &sol){
            vis[src]=1;
            for(auto ele: adj[src]){
                if(vis[ele]==0){
                    dfs(ele, adj, st, vis, sol);
                }
            }
            st.push(src);
        }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V, 0),sol;
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            dfs(i, adj,st, vis, sol);
	        }
	    }
	    while(!st.empty()){
	        sol.push_back(st.top());
	        st.pop();
	    }
	    return sol;
	}
};



//BFS CODE



class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
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
};
