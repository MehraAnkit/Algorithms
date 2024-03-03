//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(int row,int col,vector<vector<int>> &board,int n)
    {
        int duprow = row;
        int dupcol = col;
        
        // For LeftUpper Most
        
        while(duprow>=0 && dupcol>=0)
        {
            if(board[duprow][dupcol] != 0)
            {
                return false;
            }
            
            duprow--;
            dupcol--;
        }
        
        
        duprow = row;
        dupcol = col;
        
        // left
        while(dupcol>=0)
        {
            if(board[duprow][dupcol] != 0)
            {
                return false;
            }
            dupcol--;
        }
        
        duprow = row;
        dupcol = col;
        
        
        // down left
        while(dupcol >=0 && duprow<n)
        {
            if(board[duprow][dupcol] !=0)
            {
                return false;
                
            }
            duprow++;
            dupcol--;
        }
            
        return true;  
        
    }
    
    
    void addSolution(vector<vector<int>> board, vector<vector<int>> &solution,int n)
    {
        vector<int> temp;
       for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
               if(board[j][i])
                    temp.push_back(j+1);
            }
 
        }
        
        solution.push_back(temp);
    }
    
    
     void solve(int col,vector<vector<int>> &board, vector<vector<int>> &solution,int n)
    {
        if(col == n)
        {
            addSolution(board,solution,n);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col] = row+1;
                solve(col+1,board,solution,n);
                board[row][col] =0;
            }
        }
        
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n,vector<int> (n,0));
        vector<vector<int>> solution;
        solve(0,board,solution,n);
        
        return solution;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends