class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        for(int i=1;i<arr.size();i++){
            if(arr[(i-1)/2]<arr[i])
            return 0;
        }
        return 1;
    }
};
