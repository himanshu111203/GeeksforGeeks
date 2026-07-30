class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        // code here
        int n=arr.size(),ind=0;
        for(int bit=31;bit>=0;bit--){
            int maxind=-1;
            for(int i=ind;i<n;i++){
                if(arr[i]&(1<<bit)){
                    maxind=i;
                    break;
                }
            }
            if(maxind==-1)
            continue;
            swap(arr[ind],arr[maxind]);
            for(int i=0;i<n;i++){
                if(i!=ind && (arr[i]&(1<<bit)))
                arr[i]^=arr[ind];
            }
            ind++;
        }
        int ans=0;
        for(int i=0;i<ind;i++)
        ans=max(ans,ans^arr[i]);
        return ans;
    }
};
