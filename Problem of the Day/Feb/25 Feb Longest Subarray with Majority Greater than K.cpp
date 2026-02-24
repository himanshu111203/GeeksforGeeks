class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n=arr.size(),maxlen=0,psum=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            psum+=(arr[i]>k)?1:-1;
            if(psum>0)
            maxlen=i+1;
            if(m.find(psum-1)!=m.end())  // in map
            maxlen=max(maxlen,i-m[psum-1]);
            if(m.find(psum)==m.end())  // not in map
            m[psum]=i;
        }
        return maxlen;
    }
};
