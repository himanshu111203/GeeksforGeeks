class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int ans=0,i=0,j=height.size()-1;
        while(i<j){
            ans=max(ans,min(height[i],height[j])*(j-i-1));
            if(height[i]<height[j])
            i++;
            else
            j--;
        }
        return ans;
    }
};
