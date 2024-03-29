//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
     bool isValid(int row, int col, int val, int grid[N][N]) {
        for(int i=0;i<9;i++) {
            if(grid[row][i]==val) return 0;
            if(grid[i][col]==val) return 0;
            if(grid[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==val) return 0;
        }
        return 1;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i=0;i<N;i++) {
           for(int j=0;j<N;j++) {
               if(grid[i][j]==0) {
                   for(int k=1;k<=9;k++) {
                       if(isValid(i, j, k, grid)) {
                           grid[i][j]=k;
                           if(SolveSudoku(grid)) return 1;
                           grid[i][j]=0;
                       }
                   }
                   return 0;
               }
           }
       }
       return 1;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends