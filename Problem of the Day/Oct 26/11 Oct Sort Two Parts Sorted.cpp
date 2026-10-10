class Solution {
  public:
    void mergeTwoParts(vector<int>& arr) {
        // code here
        vector<int>sarr=arr;
        int k=0,n=arr.size();
        while(k+1<n && arr[k]<=arr[k+1])
        k++;
        int i=0,j=k+1,idx=0;
        while(i<=k && j<n){
            if(sarr[i]<=sarr[j])
            arr[idx++]=sarr[i++];
            else
            arr[idx++]=sarr[j++];
        }
        while(i<=k)
        arr[idx++]=sarr[i++];
        while(j<n)
        arr[idx++]=sarr[j++];
    }
};
