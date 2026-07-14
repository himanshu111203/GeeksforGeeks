//Time Complexity: O(n)
//Auxiliary Space: O(1)
class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int i=0,n=arr.size();
        int u=0,d=0,ans=1;
        while(i<n-1){
            while(i<n-1 && arr[i]<=arr[i+1]){
                u++,i++;
            }
            while(i<n-1 && arr[i]>=arr[i+1]){
                d++,i++;
            }
            ans=max(ans,u+d+1);
            int j=i,len=0;
            while(j>=0 && arr[j]==arr[j-1])
            j--,len++;
            u=len,d=0;
        }
        return ans;
    }
};


//Time Complexity: O(n)
//Auxiliary Space: O(n)
class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>inc(n,1),dec(n,1);
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1])
            inc[i]=inc[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=arr[i+1])
            dec[i]=dec[i+1]+1;
        }
        int ans=1;
        for(int i=0;i<n;i++)
        ans=max(ans,inc[i]+dec[i]-1);
        return ans;
    }
};
