class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n=s.size();
        if(n&n-1)
        k*=2;
        else
        k/=2;
        if(k>=n)
        return "-1";
        stack<char>st;
        st.push(s[0]);
        int i=1;
        while(k && i<n){
            while(!st.empty() && k && st.top()>s[i]){
                st.pop();
                k--;
            }
            st.push(s[i++]);
        }
        while(k){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(i<n)
        ans+=s[i++];
        return ans;
    }
};
