class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        int i,j,k;
        i=0;
        j=0;
        k=0;
        int mini=INT_MAX;
        vector<int>ans;
        while(i<a.size() && j<b.size() && k<c.size()){
            if(a[i]>=b[j] && a[i]>=c[k]){
                if(b[j]>=c[k]){
                    int diff=a[i]-c[k];
                    if(diff<mini){
                        mini=diff;
                        ans={a[i],b[j],c[k]};
                    }
                    k++;
                }
                else{
                    int diff=a[i]-b[j];
                    if(diff<mini){
                        mini=diff;
                        ans={a[i],b[j],c[k]};
                    }
                    j++;
                }
            }
            else if(b[j]>=a[i] && b[j]>=c[k]){
                if(a[i]>=c[k]){
                    int diff=b[j]-c[k];
                    if(diff<mini){
                        mini=diff;
                        ans={a[i],b[j],c[k]};
                    }
                    k++;
                }
                else{
                    int diff=b[j]-a[i];
                    if(diff<mini){
                        mini=diff;
                        ans={a[i],b[j],c[k]};
                    }
                    i++;
                }
            }
            else{
                if(b[j]>=a[i]){
                    int diff=c[k]-a[i];
                    if(diff<mini){
                        mini=diff;
                        ans={a[i],b[j],c[k]};
                    }
                    i++;
                }
                else{
                    int diff=c[k]-b[j];
                    if(diff<mini){
                        mini=diff;
                        ans={a[i],b[j],c[k]};
                    }
                    j++;
                }
            }
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};
