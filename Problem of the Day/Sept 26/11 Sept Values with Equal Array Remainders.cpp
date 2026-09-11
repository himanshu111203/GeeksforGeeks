class Solution {
  public:
    int sameMod(vector<int> &arr) {
        // code here
        int g=0,n=arr.size();
        for(int i=1;i<n;i++)
        g=gcd(g,abs(arr[i]-arr[0]));
        if(g==0)
        return -1;
        int ans=0;
        for(int k=1;k*k<=g;k++){
            if(g%k==0){
                ans++;
                if(k!=g/k)
                ans++;
            }
        }
        return ans;
    }
};
