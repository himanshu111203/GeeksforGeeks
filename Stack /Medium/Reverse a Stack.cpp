class Solution{
public:
    void Reverse(stack<int> &St){
        queue<int>q;
        while(!St.empty())
        {
            q.push(St.top());
            St.pop();
        }
        while(!q.empty())
        {
            St.push(q.front());
            q.pop();
        }
    }
};
