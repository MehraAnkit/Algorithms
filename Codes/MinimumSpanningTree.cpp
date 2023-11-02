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
