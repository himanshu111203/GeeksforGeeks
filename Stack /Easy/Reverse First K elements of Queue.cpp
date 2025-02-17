class Solution {
  public:
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> &q, int k) {
        int n=q.size();
        n-=k;
        stack<int>s;
        while(k--){
            s.push(q.front());
            q.pop();
        }
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        while(n--){
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};
