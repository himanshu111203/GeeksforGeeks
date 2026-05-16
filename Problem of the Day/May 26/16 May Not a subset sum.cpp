class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        sort(arr.begin(),arr.end());
        int a=1,n=arr.size();
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=a)
            a+=arr[i];
        }
        return a;
    }
};
