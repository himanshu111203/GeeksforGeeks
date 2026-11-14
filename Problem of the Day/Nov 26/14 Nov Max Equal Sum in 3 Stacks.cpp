class Solution {
  public:
    int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
        // code here
        int sum1=accumulate(s1.begin(),s1.end(),0);
        int sum2=accumulate(s2.begin(),s2.end(),0);
        int sum3=accumulate(s3.begin(),s3.end(),0);
        int n=s1.size(),m=s2.size(),o=s3.size(),i=0,j=0,k=0;
        while(i<n && j<m && k<o){
            if(sum1==sum2 && sum1==sum3)
            return sum1;
            if(sum1>=sum2 && sum1>=sum3)
            sum1-=s1[i++];
            else if(sum2>=sum1 && sum2>=sum3)
            sum2-=s2[j++];
            else
            sum3-=s3[k++];
        }
        if(sum1==sum2 && sum1==sum3)
        return sum1;
        return 0;
    }
};
