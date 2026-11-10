class Solution {
  public:
    int firstElementKTime(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>m;
        for(int i:arr){
            m[i]++;
            if(m[i]==k)
            return i;
        }
        return -1;
    }
};
