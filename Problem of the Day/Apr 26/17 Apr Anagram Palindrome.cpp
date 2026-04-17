class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        int a;
        for(int i:freq){
            if(i%2==1)
            a++;
        }
        return a<2;
    }
};
