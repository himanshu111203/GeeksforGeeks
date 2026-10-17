class Solution {
  public:
    bool isItPossible(string &s1, string &s2) {
        // code here
        int n=s1.size(),m=s2.size();
        if(n!=m)
        return 0;
        int i=0,j=0;
        while(i<n && j<n){
            while(i<n && s1[i]=='#')
            i++;
            while(j<n && s2[j]=='#')
            j++;
            if(i==n || j==n)
            break;
            if(s1[i]!=s2[j])
            return 0;
            if(s1[i]=='A' && i<j)
            return 0;
            if(s1[i]=='B' && i>j)
            return 0;
            i++,j++;
        }
        while(i<n && s1[i]=='#')
        i++;
        while(j<n && s2[j]=='#')
        j++;
        return i==n && j==n;
    }
};
