class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<long long>freq(32,0);
        for(int i=0;i<n;i++){
            int num=arr[i];
            int j=0;
            while(num>0){
                freq[j]+=(num&1);
                j++;
                num>>=1;
            }
        }
        long long sum=0;
        for(int i=0;i<32;i++){
            sum+=(long long)pow(2,i)*(freq[i]*(n-freq[i]));
        }
        return sum;
    }
};
