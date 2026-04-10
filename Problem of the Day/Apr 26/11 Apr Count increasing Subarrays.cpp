class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int ans=0,a=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>arr[i-1]){
                a++;
                ans+=(a-1);
            }else
            a=1;
        }
        return ans;
    }
};
