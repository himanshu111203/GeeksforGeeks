class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        if(arr[0]>=0)
        return arr[0];
        int n=arr.size();
        int neg=0;
        for(int i:arr){
            if(i<0)
            neg++;
        }
        int i=neg-1,prod=1;
        if(neg%2==0)
        i--;
        while(i>=0)
        prod*=arr[i--];
        for(int j=neg;j<n;j++){
            if(arr[j]>0)
            prod*=arr[j];
        }
        return prod;
    }
};
