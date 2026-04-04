class Solution {
  public:
    string convert(int a,int n){
        string s;
        while(a){
            int rem=a%2;
            s+=(rem+'0');
            a/=2;
        }
        while(s.size()<n)
        s+='0';
        reverse(s.begin(),s.end());
        return s;
    }
    vector<string> graycode(int n) {
        // code here
        int total=1<<n;
        vector<string>ans;
        for(int i=0;i<total;i++){
            int a=i^(i>>1);
            ans.push_back(convert(a,n));
        }
        return ans;
    }
};
