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
            if(lis.empty() || x>lis[lis.size()-1])
            lis.push_back(x);
            else{
                int ind=-1;
                int start=0,end=lis.size()-1,mid;
                while(start<=end){
                    mid=start+(end-start)/2;
                    if(lis[mid]>=x){
                        ind=mid;
                        end=mid-1;
                    }else
                    start=mid+1;
                }
                if(ind!=-1)
                lis[ind]=x;
            }
            
        }
        int len=lis.size();
        return (n-len)+(m-len);
    }
};
