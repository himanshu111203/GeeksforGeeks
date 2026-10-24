class Solution {
  public:
    bool isPossible(int n, int m, string& s) {
        // code here
        int x=0,y=0,maxix=0,minix=0,maxiy=0,miniy=0;
        for(char c:s){
            if(c=='L')
            y--;
            else if(c=='R')
            y++;
            else if(c=='D')
            x--;
            else
            x++;
            maxix=max(maxix,x);
            minix=min(minix,x);
            maxiy=max(maxiy,y);
            miniy=min(miniy,y);
        }
        x=abs(maxix)+abs(minix);
        y=abs(maxiy)+abs(miniy);
        return x<n && y<m;
    }
};
