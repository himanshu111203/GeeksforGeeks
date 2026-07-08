class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        vector<int>modulo(k,0);
        for(int i:arr)
        modulo[i%k]++;
        int ans=modulo[0]*(modulo[0]-1)/2;
        int a=1,b=k-1;
        while(a<b){
            ans+=modulo[a]*modulo[b];
            a++,b--;
        }
        if(a==b)
        ans+=modulo[a]*(modulo[a]-1)/2;;
        return ans;
    }
};
