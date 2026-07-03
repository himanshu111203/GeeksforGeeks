class Solution {
  public:
    int inv=0;
    void merge(vector<int>&arr,int start,int mid,int end){
        vector<int>temp(end-start+1);
        int l=start,r=mid+1,i=0;
        while(l<=mid && r<=end){
            if(arr[l]<=arr[r])
            temp[i++]=arr[l++];
            else{
                inv+=(mid-l+1);
                temp[i++]=arr[r++];
            }
        }
        while(l<=mid)
        temp[i++]=arr[l++];
        while(r<=end)
        temp[i++]=arr[r++];
        i=0;
        for(int j=start;j<=end;j++)
        arr[j]=temp[i++];
    }
    void mergesort(vector<int>&arr,int start,int end){
        if(start>=end)
        return;
        int mid=start+(end-start)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
    int countSubstring(string& s) {
        // Code Here
        int n=s.size();
        vector<int>arr(n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')
            arr[i]=1;
            else
            arr[i]=-1;
            if(i>0)
            arr[i]+=arr[i-1];
            if(arr[i]>0)
            ans++;
        }
        reverse(arr.begin(),arr.end());
        mergesort(arr,0,n-1);
        ans+=inv;
        return ans;
    }
};
