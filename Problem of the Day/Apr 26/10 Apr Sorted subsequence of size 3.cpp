class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n = arr.size(), minL = INT_MAX, maxR = INT_MIN;
        vector<int> minLeft(n), maxRight(n);
        for ( int i = 0; i<n; i++ ){
            minLeft[i] = minL; maxRight[n-i-1] = maxR;
            minL = min(minL, arr[i]); maxR = max(maxR, arr[n-i-1]);
        }
        for ( int i = 1; i<n-1; i++ ){
            if ( minLeft[i] < arr[i] && arr[i] < maxRight[i] ){
                return { minLeft[i], arr[i], maxRight[i] };
            }
        } return {};
    }
};
