class Solution {
  public:
    bool binary(int x,vector<int>&arr,int s,int e){
        if(s>e)
        return 0;
        int m=s+(e-s)/2;
        if(arr[m]==x)
        return 1;
        else if(arr[m]<x)
        return binary(x,arr,m+1,e);
        else
        return binary(x,arr,s,m-1);
    }
    int binarySearchable(vector<int>& arr) {
        // code here
        int n=arr.size(),c=0;
        for(int i:arr){
            if(binary(i,arr,0,n-1))
            c++;
        }
        return c;
    }
};
