class Solution {
public:
    int minimumCost(vector<int>& cost) {
        priority_queue<int>q(cost.begin(),cost.end());
        int ans=0,c=0;
        while(!q.empty()){
            int temp=q.top();
            q.pop();
            if(c==2)
            c=0;
            else{
                ans+=temp;
                c++;
            }
        }
        return ans;
    }
};
