class Solution {
public:
    char posInfinite(string &s, int pos){
        long long n=s.size();
        vector<long long>len={n};
        long long L=n,step=1;
        while(L<pos){
            L=2*L+step;
            len.push_back(L);
            step++;
        }
        for(int i=len.size()-1;i>=1;i--){
            long long prev=len[i-1];
            long long added=i;
            if(pos<=prev)
            continue;
            else if(pos<=prev+added)
            return '$';
            else
            pos=len[i]-pos+1;
        }
        return s[pos-1];
    }
};
