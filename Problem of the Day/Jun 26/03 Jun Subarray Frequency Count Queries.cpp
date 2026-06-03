class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int s=arr.size(),n=queries.size();
        unordered_map<int,vector<int>>m;
        for(int i=0;i<s;i++){
            m[arr[i]].push_back(i);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int l=queries[i][0],r=queries[i][1],x=queries[i][2];
            
            vector<int>temp=m[x];
            int lower=-1,upper=-1,start=0,end=temp.size()-1,mid;
            while(start<=end){
                mid=start+(end-start)/2;
                if(temp[mid]==l){
                    lower=mid;
                    break;
                }else if(temp[mid]>l){
                    if(temp[mid]<=r)
                    lower=mid;
                    end=mid-1;
                }else
                start=mid+1;
            }
            start=0,end=temp.size()-1;
            while(start<=end){
                mid=start+(end-start)/2;
                if(temp[mid]==r){
                    upper=mid;
                    break;
                }else if(temp[mid]<r){
                    if(temp[mid]>=l)
                    upper=mid;
                    start=mid+1;
                }else
                end=mid-1;
            }
            if(lower==-1 || upper==-1)
            ans[i]=0;
            else
            ans[i]=upper-lower+1;
        }
        return ans;
    }
};
