class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int r=matrix.size();
	    int c=matrix[0].size();
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e8;
	            }
	            if(i==j){
	                matrix[i][j]=0;
	            }
	        }
	    }
	    
	    for(int k=0;k<r;k++){
	        for(int i=0;i<r;i++){
	            for(int j=0;j<c;j++){
	                matrix[i][j]= min(matrix[i][j], matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    
	    
	    for(int i=0;i<r;i++){
	        for(int j=0;j<c;j++){
	            if(matrix[i][j]==1e8){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	}
};
