class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        unordered_set<long long>s;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                if(target==0)
                return 1;
                continue;
            }
            else if(target%arr[i]==0){
                int req=target/arr[i];
                if(s.find(req)!=s.end())
                return 1;
            }
            s.insert(arr[i]);
        }
        return 0;
    }
};
