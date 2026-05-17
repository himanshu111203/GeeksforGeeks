class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int>s;
        int i=0,n=arr.size();
        while(i<n){
            if(s.empty()){
                s.push(arr[i]);
            }else if(arr[i]>=0){
                if(s.top()<0)
                s.pop();
                else
                s.push(arr[i]);
            }else{
                if(s.top()>=0)
                s.pop();
                else
                s.push(arr[i]);
            }
            i++;
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
