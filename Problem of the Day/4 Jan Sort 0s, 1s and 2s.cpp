class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here                                   // Use 3 Pointer
        int i=0,k=arr.size()-1,j=0;
        while(i<=k){
            if(arr[i]==0)
            swap(arr[i++],arr[j++]);
            else if(arr[i]==2)
            swap(arr[i],arr[k--]);
            else
            i++;
        }
        
    }
};
