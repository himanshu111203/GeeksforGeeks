class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>ans;
        int i=0,j=0,m=a.size(),n=b.size();
        int q=INT_MAX;
        while(i<m && j<n){
            if(a[i]<b[j])
            i++;
            else if(a[i]>b[j])
            j++;
            else{
                if(q!=a[i]){
                    ans.push_back(a[i]);
                    q=a[i];
                }
                i++,j++;
            }
        }
        return ans;
    }
};
