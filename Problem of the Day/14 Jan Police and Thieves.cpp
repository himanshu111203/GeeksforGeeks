class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n=arr.size(),ans=0,p=0,t=0;
        while(p<n && t<n){
            while(p<n && arr[p]!='P')
            p++;
            while(t<n && arr[t]!='T')
            t++;
            if(p<n && t<n){
                if(abs(t-p)<=k){
                    ans++,p++,t++;
                }
                else{
                    if(p>t)
                    t++;
                    else
                    p++;
                }
            }
        }
        return ans;
    }
};
