class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {
        // code here
        unordered_set<int>s(arr.begin(),arr.end());
        int a=1;
        while(k){
            if(s.count(a))
            a++;
            else
            a++,k--;
        }
        return a-1;
    }
};
