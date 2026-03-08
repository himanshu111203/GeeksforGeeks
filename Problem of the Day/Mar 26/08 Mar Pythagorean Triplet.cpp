class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int maxi=0;
        for(int i:arr)
        maxi=max(maxi,i);
        vector<bool>freq(maxi+1,0);
        for(int i:arr)
        freq[i]=1;
        for(int a=1;a<=maxi;a++){
            if(!freq[a])
            continue;
            for(int b=a+1;b<=maxi;b++){
                if(!freq[b])
                continue;
                int c2=a*a+b*b;
                int c=sqrt(c2);
                if(c<=maxi && c*c==c2 && freq[c])
                return 1;
            }
        }
        return 0;
    }
};
