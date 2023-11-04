class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int, int>> s;
        vector<int> vis(V, 0);
        vector<int> dist(V, INT_MAX);
        dist[S]=0;
        s.insert({0, S});
        
        while(!s.empty()){
            auto it= *(s.begin());
            int node= it.second;
            int dis= it.first;
            s.erase(it);
            
            for(auto it: adj[node]){
                int adjnode= it[0];
                int ew= it[1];
                
                if(dis +ew<dist[adjnode]){
                    if(dist[adjnode]!=INT_MAX){
                        s.erase({dist[adjnode], adjnode});
                    }
                    
                    dist[adjnode]= dis+ ew;
                    s.insert({dist[adjnode], adjnode});
                }
            }
        }
        return dist;
    }
};
