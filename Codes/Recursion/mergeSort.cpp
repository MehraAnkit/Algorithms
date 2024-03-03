//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int temp[r-l+1];
         int low=l,high=m+1;
         int i=0;
         
         while(low<=m && high<=r){
             if(arr[low]<arr[high]){
                 temp[i]=arr[low];
                 low++;
             }else{
                 temp[i]=arr[high];
                 high++;
             }
             i++;
         }
         
         while(low<=m){
             temp[i++]=arr[low++];
         }
         while(high<=r){
             temp[i++]=arr[high++];
         }
         
         for(int j=l;j<=r;j++){
             arr[j]=temp[j-l];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r)return;
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends