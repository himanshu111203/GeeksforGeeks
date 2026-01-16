class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' ||s[i]=='/')
            st.push(s[i]);
            else if(s[i]==')'){
                if(st.top()=='(')
                return 1;
                else{
                    while(st.top()!='(')
                    st.pop();
                    st.pop();
                }
            }
        }
        return 0;
    }
};
