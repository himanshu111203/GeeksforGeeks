class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        stack<int>s;
        for(int i:arr){
            bool destroy=0;
            while(!s.empty() && s.top()*i<0){
                if(abs(s.top())==abs(i)){
                    s.pop();
                    destroy=1;
                    break;
                }
                else if(abs(s.top())>abs(i)){
                    destroy=1;
                    break;
                }
                else
                s.pop();
            }
            if(!destroy)
            s.push(i);
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
