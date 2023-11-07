/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
void indexMapping(map<int,vector<int> >& mapping, int in[],int n)
    {
       for (int i = 0; i < n; i++)
            mapping[in[i]].push_back(i);
        return;
    }
    
    Node* solve(int in[],int post[], int n, map<int,vector<int> >&mapping, int start,int end, int& index){
        if(index <0 || start > end)
            return NULL;
        
        int element=post[index--];
        Node* root=new Node(element);
        
        vector<int>& positions = mapping[element];
        int p = positions.front();
        positions.erase(positions.begin());
        root->right=solve(in,post,n,mapping,p+1,end,index);
        root->left=solve(in,post,n,mapping,start,p-1,index);
        
        
        return root;
    }
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int index=n-1;
        map<int,vector<int> > mapping;
        indexMapping(mapping,in,n);
        return solve(in,post,n,mapping,0,n-1,index);
}
