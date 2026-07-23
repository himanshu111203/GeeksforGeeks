class Solution {
  public:
    int n;
    bool build(int &i,int mini,int maxi,vector<int>&arr){
        if(i==n)
        return 1;
        if(mini>arr[i] || maxi<arr[i])
        return 1;
        int data=arr[i++];
        return build(i,mini,data,arr) && build(i,data,maxi,arr);
    }
    bool canRepresentBST(vector<int> &arr) {
        // code here
        n=arr.size();
        int i=0;
        bool ok=build(i,INT_MIN,INT_MAX,arr);
        return ok && i==n;
    }
};
