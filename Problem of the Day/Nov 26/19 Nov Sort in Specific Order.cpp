class Solution {
  public:
    void merge(vector<int>&arr,int start,int mid,int end){
        vector<int>temp(end-start+1);
        int i=start,j=mid+1,k=0;
        while(i<=mid && j<=end){
            if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
            else
            temp[k++]=arr[j++];
        }
        while(i<=mid)
        temp[k++]=arr[i++];
        while(j<=end)
        temp[k++]=arr[j++];
        k=0;
        while(start<=end)
        arr[start++]=temp[k++];
    }
    void mergesort(vector<int>&arr,int start,int end){
        if(start>=end)
        return;
        int mid=start+(end-start)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
    void sortIt(vector<int>& arr) {
        // code here
        int k=0,n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]%2)
            swap(arr[i],arr[k++]);
        }
        mergesort(arr,0,k-1);
        mergesort(arr,k,n-1);
        int a=0,b=k-1;
        while(a<b)
        swap(arr[a++],arr[b--]);
        return;
    }
};
