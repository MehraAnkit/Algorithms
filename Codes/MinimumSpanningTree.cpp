											//PRIM'S ALGORITHM
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue <pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> gq;
        vector<int> vis(V, 0);
        
        gq.push({0, 0});
        int sum=0;
        while(!gq.empty()){
            auto it= gq.top();
            gq.pop();
            int wt=it.first;
            int node= it.second;
            
            if(vis[node]){
                continue;
            }
            vis[node]=1;
            sum +=wt;
            for(auto it: adj[node]){
                int adjn=it[0];
                int ewt=it[1];
                if(!vis[adjn]){
                    gq.push({ewt, adjn});
                }
            }
        }
        return sum;
        
    }
};

											// KRUSKAL ALGORITHM


class Solution
{
    class DisjointSet{
        vector<int> rank;
        vector<int> size,parent;
        
        public:
            DisjointSet(int V){
                rank.resize(V+1, 0);
                parent.resize(V+1);
                size.resize(V+1);
                for(int i=0;i<=V;i++){
                    parent[i]=i;
                    size[i]=1;
                }
            }
            int findUParent(int node){
                if(parent[node]==node) return node;
                
                return parent[node]= findUParent(parent[node]);
            }
            
            void unionBySize(int u, int v){
                int ulp_u=findUParent(u);
                int ulp_v=findUParent(v);
                if(ulp_u==ulp_v){
                    return;
                }
                if(size[ulp_u]<size[ulp_v]){
                    parent[ulp_u]=parent[ulp_v];
                    size[ulp_v] += size[ulp_u];
                }else{
                    parent[ulp_v]=parent[ulp_u];
                    size[ulp_u] += size[ulp_v];
                }
                
            }
            void unionByRank(int u, int v){
                int ulp_u=findUParent(u);
                int ulp_v=findUParent(v);
                if(ulp_u==ulp_v){
                    return;
                }
                if(rank[ulp_u]<rank[ulp_v]){
                    parent[ulp_u]=parent[ulp_v];
                }else if(rank[ulp_v]<rank[ulp_u]){
                    parent[ulp_v]=parent[ulp_u];
                }else{
                    parent[ulp_v]=parent[ulp_u];
                    rank[ulp_u]++;
                }
            }
    };
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        DisjointSet s(V);
        sort(edges.begin(), edges.end());
        int eWt=0;
        for(auto it: edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(s.findUParent(u)!=s.findUParent(v)){
                eWt +=wt;
                s.unionBySize(u, v);
            }
        }
        return eWt;
    }
};
