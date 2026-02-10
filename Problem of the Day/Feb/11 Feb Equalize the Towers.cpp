//The cost function is convex (U-shaped), meaning it decreases until a single minimum point and then increases,
//so comparing f(mid) and f(mid+1) tells us which side the minimum lies on: if a1 = f(mid) is less than or equal to a2 = f(mid+1), 
//the cost is flat or increasing as we move right, which means we are already at or past the minimum 
//and it must be at mid or somewhere to the left, so we move left by setting end = mid - 1; otherwise, if a1 > a2, 
//the cost is still decreasing when moving right, so the minimum lies to the right and we move right by setting start = mid + 1

class Solution {
  public:
    long long find(int mid,vector<int>& heights, vector<int>& cost){
        int n=cost.size();
        long long a=0;
        for(int i=0;i<n;i++)
        a+=1ll*abs(mid-heights[i])*cost[i];
        return a;
    }
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int start=INT_MAX,end=INT_MIN,n=cost.size(),mid;
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
            start=min(start,heights[i]);
            end=max(end,heights[i]);
        }
        while(start<=end){
            mid=start+(end-start)/2;
            long long a1=find(mid,heights,cost);
            long long a2=find(mid+1,heights,cost);
            ans=min(ans,a1);
            if(a1<=a2)
            end=mid-1;
            else
            start=mid+1;
        }
        return ans;
    }
};
