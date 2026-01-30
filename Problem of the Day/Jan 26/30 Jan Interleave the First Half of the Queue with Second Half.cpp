class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size();
        int a=n/2;
        queue<int>q1;
        while(a){
            q1.push(q.front());
            q.pop();
            a--;
        }
        while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
            q.push(q.front());
            q.pop();
        }
        return;
    }
}; 
