class Solution {
  public:
    vector<int> deleteElement(vector<int>& arr, int k) {
        stack<int> st;
        vector<int> ans;
        int n=arr.size();
        int count =0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top()<arr[i] && count<k)
            {
                st.pop();
                count++;
            }
            st.push(arr[i]);
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
