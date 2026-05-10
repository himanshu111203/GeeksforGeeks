class Solution {
  public:
    bool ispal(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
            return 0;
            i++,j--;
        }
        return 1;
    }
    bool palindromePair(vector<string>& arr) {
        // Code here
        int n=arr.size();
        unordered_map<string,int>m;
        for(int i=0;i<n;i++)
        m[arr[i]]=i;
        for(int i=0;i<n;i++){
            string s=arr[i];
            int sz=s.size();
            for(int cut=0;cut<=sz;cut++){
                string left=s.substr(0,cut);
                string right=s.substr(cut);
                if(ispal(left)){
                    string revright=right;
                    reverse(revright.begin(),revright.end());
                    if(m.count(revright) && m[revright]!=i)
                    return 1;
                }
                if(cut!=sz && ispal(right)){
                    string revleft=left;
                    reverse(revleft.begin(),revleft.end());
                    if(m.count(revleft) && m[revleft]!=i)
                    return 1;
                }
            }
        }
        return 0;
    }
};
