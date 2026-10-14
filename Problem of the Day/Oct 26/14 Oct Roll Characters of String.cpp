class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        // code here
        int n=s.size();
        vector<int>arr(n,0);
        for(int i:roll)
        arr[i-1]++;
        if(arr[n-1]!=0)
        s[n-1]='a'+((s[n-1]-'a')+arr[n-1])%26;
        for(int i=n-2;i>=0;i--){
            arr[i]+=arr[i+1];
            s[i]='a'+((s[i]-'a')+arr[i])%26;
        }
        return s;
    }
};
