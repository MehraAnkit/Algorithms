//BFS CODE

lass Solution {
    private:
        bool bfs(int src, vector<int>adj[], vector<int> &vis){
            queue<int> q;
            q.push(src);
            vis[src]=0;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it: adj[node]){
                    if(vis[it]==-1){
                        vis[it]=!vis[node];
                        q.push(it);
                    }else if(vis[node]==vis[it]){
                        return false;
                    }
                }
            }
            return true;
        }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V,-1);
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	            if(bfs(i,adj, vis)==false){
        	       return false;
        	   }
	        }
	    }
	    
	    return true;
	}

};


//DFS CODE


class Solution {
    private:
        bool dfs(int src, vector<int>adj[], vector<int> &vis, int color){
            vis[src]=color;
            for(auto it: adj[src]){
                if(vis[it]==-1){
                    if(dfs(it, adj, vis, !color)==false){
                        return false;
                    }
                }else if(color==vis[it]){
                    return false;
                }
            }
            return true;
        }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V,-1);
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	            if(dfs(i,adj, vis, 0)==false){
        	       return false;
        	   }
	        }
	    }
	    
	    return true;
	}

};
