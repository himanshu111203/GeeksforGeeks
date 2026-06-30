class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        int n=a.size(),m=b.size();
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++)
        mp[b[i]]=i;
        vector<int>seq;
        for(int i=0;i<n;i++){
            if(mp.count(a[i]))
            seq.push_back(mp[a[i]]);
        }
        int k=seq.size();
        vector<int>lis;
        for(int x:seq) {
            auto it=lower_bound(lis.begin(),lis.end(),x);
            if(it==lis.end())
            lis.push_back(x);
            else
            *it=x;
        }
        int len=lis.size();
        return (n-len)+(m-len);
    }
};
