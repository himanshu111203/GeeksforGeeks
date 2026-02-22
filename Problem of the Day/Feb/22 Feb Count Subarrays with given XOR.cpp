class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long count=0,prexor=0;
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            prexor^=arr[i];
            if(prexor==k)
            count++;
            if(m.find(prexor^k)!=m.end())
            count+=m[prexor^k];
            m[prexor]++;
        }
        return count;
    }
};
