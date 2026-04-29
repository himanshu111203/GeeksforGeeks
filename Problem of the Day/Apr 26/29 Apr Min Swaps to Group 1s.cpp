class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int cone=0,n=arr.size();
        for(int i:arr){
            if(i==1)
            cone++;
        }
        if(cone==0)
        return -1;
        if(cone==1)
        return 0;
        int czero=0;
        for(int i=0;i<cone;i++){
            if(arr[i]==0)
            czero++;
        }
        int ans=czero;
        for(int i=cone;i<n;i++){
            if(arr[i-cone]==0)
            czero--;
            if(arr[i]==0)
            czero++;
            ans=min(ans,czero);
        }
        return ans;
    }
};
