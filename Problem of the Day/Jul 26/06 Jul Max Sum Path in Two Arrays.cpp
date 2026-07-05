class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int s1=0,s2=0,ans=0;
        int i=0,j=0,m=a.size(),n=b.size();
        while(i<m && j<n){
            if(a[i]==b[j]){
                ans+=a[i]+max(s1,s2);
                s1=0,s2=0;
                i++,j++;
            }
            else if(a[i]<b[j])
            s1+=a[i++];
            else
            s2+=b[j++];
        }
        while(i<m)
        s1+=a[i++];
        while(j<n)
        s2+=b[j++];
        ans+=max(s1,s2);
        return ans;
    }
};
