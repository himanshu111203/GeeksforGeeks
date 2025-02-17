class Solution {
  public:
    vector<int> bracketNumbers(string str) {
        vector<int>ans;
        int count=0;
        stack<int>s;
        for(int i=0;i<str.size();i++){
            if(str[i] == '('){
                count +=1;
                s.push(count);
                ans.push_back(s.top());
            }
            else if(str[i] == ')'){
                int temp = s.top();
                s.pop();
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
