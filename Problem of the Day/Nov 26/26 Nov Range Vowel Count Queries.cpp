class Solution {
  public:
  
    bool isVow(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
  
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        // code here
        int n=s.length();
        vector<int>tmp(n, 0);
        int cnt=0;
        
        for(int i; i<n; i++){
            tmp[i]=cnt;
            if(isVow(s[i])) cnt++;
        }
        
        vector<int>ans;
        
        for(auto &it:queries){
            int l=it[0];
            int r=it[1];
            ans.push_back(tmp[r]-tmp[l]+(isVow(s[r])));
        }
        
        return ans;
    }
};
