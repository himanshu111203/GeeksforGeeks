class Solution {
  public:
    void find(vector<int>&b,vector<int>&lps){
        int pre=0,suf=1,n=b.size();
        while(suf<n){
            if(b[pre]==b[suf]){
                lps[suf]=pre+1;
                pre++,suf++;
            }
            else{
                if(pre==0)
                suf++;
                else
                pre=lps[pre-1];
            }
        }
        return;
    }
    vector<int> search(vector<int> &a, vector<int> &b) {
        // code here
        int n=a.size(),m=b.size();
        vector<int>lps(m,0);
        find(b,lps);
        vector<int>ans;
        int i=0,j=0;
        while(i<n){
            if(a[i]==b[j])
            i++,j++;
            if(j==m){
                ans.push_back(i-m);
                j=lps[j-1];    
            }
            else if(i<n && a[i]!=b[j]) {
                if(j==0)
                i++;
                else
                j=lps[j-1];
            }
        }
        return ans;
    }
};
