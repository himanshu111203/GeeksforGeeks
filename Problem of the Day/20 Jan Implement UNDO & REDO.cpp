class Solution {
  public:
  string ans="";
  stack<int>s;
    void append(char x) {
        // append x into document
        ans.push_back(x);
    }

    void undo() {
        // undo last change
        s.push(ans.back());
        ans.pop_back();
    }

    void redo() {
        // redo changes
        if(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
    }

    string read() {
        // read the document
        return ans;
    }
};
