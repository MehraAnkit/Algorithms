class Solution{
    private:
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
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i=0;i<N-1;i++){
            int n=min(dict[i].size(), dict[i+1].size());
            for(int j=0;j<n;j++){
                if(dict[i][j]!=dict[i+1][j]){
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        
        vector<int> topo_sort= topoSort(K, adj);
        string sol="";
        for(auto it: topo_sort){
            sol +=char(it+'a)';
        }
        return sol;
    }
};
