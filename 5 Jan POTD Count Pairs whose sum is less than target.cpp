class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(),arr.end());
        int ans=0,a=0,b=arr.size()-1;
        while(a<b)
        {
            if(arr[a]+arr[b]<target)
            {
                ans+=b-a; // (arr[a],arr[a+1]) (arr[a],arr[a+2])...... (arr[a],arr[b])
                a++;
            }
            else
            b--;
        }
        return ans;
    }
};
