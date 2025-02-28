class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(s[i]==')' && st.top()=='(')
            st.pop();
            else if(s[i]=='}' && st.top()=='{')
            st.pop();
            else if(s[i]==']' && st.top()=='[')
            st.pop();
            else
            st.push(s[i]);
        }
        return st.empty();
    }
};
