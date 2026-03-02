class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int k=2,n=arr.size(),start=0,ans=0;
        unordered_map<int,int>m;
        for(int end=0;end<n;end++){
            m[arr[end]]++;
            if(m[arr[end]]==1)
            k--;
            while(k<0){
                if(m[arr[start]]==1)
                k++;
                m[arr[start++]]--;
            }
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};
