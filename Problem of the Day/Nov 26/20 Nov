class Solution {
  public:
    int minFlips(string &s) {
        // code here
        int oo=0,ez=0,oz=0,eo=0,n=s.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(s[i]=='1')
                ez++;
                else
                eo++;
            }else{
                if(s[i]=='1')
                oz++;
                else
                oo++;
            }
        }
        return min(oo+ez,eo+oz);
    }
};
