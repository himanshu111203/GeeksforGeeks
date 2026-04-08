class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int i=0,j=arr.size()-1;
        while(i<=j){
            if(arr[i]==1)
            swap(arr[i],arr[j--]);
            else
            i++;
        }
        return;
    }
};
