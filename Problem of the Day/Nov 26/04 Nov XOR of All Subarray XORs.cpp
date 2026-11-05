class Solution {
	public:
	int subarrayXor(vector<int>& arr) {
		// code here
		int n=arr.size(),ans=0;
		for(int i=0;i<n;i++){
			int cnt=(n-i)*(i+1);
			if (cnt&1)
			ans^=arr[i];
		}
		return ans;
	}
};
