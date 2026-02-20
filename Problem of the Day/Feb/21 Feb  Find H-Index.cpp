class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n=citations.size();
        vector<int>freq(n+1,0);
        for(int i=0;i<n;i++){
            if(citations[i]>=n)
            freq[n]++;
            else
            freq[citations[i]]++;
        }
        int i=n,s=freq[n];
        while(s<i){
            i--;
            s+=freq[i];
        }
        return i;
    }
};
