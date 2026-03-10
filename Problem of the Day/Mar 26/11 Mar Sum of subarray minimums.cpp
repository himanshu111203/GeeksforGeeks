class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        stack<int>s;
        int ans=0;
        int n=arr.size(),ind;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[i]<arr[s.top()]){ // NSR present
                ind=s.top();
                s.pop();
                if(s.empty())                        // NSL absnet
                ans+=arr[ind]*(ind+1)*(i-ind);
                else                                  // NSL present
                ans+=arr[ind]*(ind-s.top())*(i-ind);
            }
            s.push(i);
        }
        while(!s.empty()){                            // NSR absent 
            ind=s.top();
            s.pop();
            if(s.empty())                            // NSL absnet
            ans+=arr[ind]*(ind+1)*(n-ind);
            else                                    // NSL present
            ans+=arr[ind]*(ind-s.top())*(n-ind);
        }
        return ans;
    }
};
