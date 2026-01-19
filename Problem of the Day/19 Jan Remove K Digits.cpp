class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        stack<char>st;
        for(char c:s){
            while(!st.empty() && k && c<st.top()){
                st.pop();
                k--;
            }
            if(!st.empty() || c!='0')
            st.push(c);
        }
        while(!st.empty() && k){
            st.pop();
            k--;
        }
        if(st.empty())
        return "0";
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
