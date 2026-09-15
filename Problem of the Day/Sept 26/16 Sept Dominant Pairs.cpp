class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int n=arr.size();
        int half=n/2;
        vector<int>left(arr.begin(),arr.begin()+half);
        vector<int>right(arr.begin()+half,arr.end());
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        int ans=0,j=0;
        for(int i=0;i<half;i++){
            while(j<half && (long long)left[i]>=5LL*right[j])
            j++;
            ans+=j;
        }
        return ans;
    }
};
