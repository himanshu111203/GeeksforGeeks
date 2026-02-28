class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int n=arr1.size(),m=arr2.size(),i,j,a,b;
        i=0,j=m-1;
        int diff=INT_MAX;
        while(i<n && j>=0){
            int sum=arr1[i]+arr2[j];
            int difference=abs(sum-x);
            if(difference<diff){
                if(difference==0)
                return {arr1[i],arr2[j]};
                a=arr1[i],b=arr2[j];
                diff=difference;
            }
            if(sum<x)
            i++;
            else
            j--;
        }
        return {a,b};
    }
};
