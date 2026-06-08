class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        int n=seats.size();
        for(int i=0;i<n;i++){
            if(seats[i]==0){
                if(i==0){
                    if(seats[i+1]==0){
                        seats[i]=1;
                        k--;
                    }
                }else if(i==n-1){
                    if(seats[i-1]==0){
                        seats[i]=1;
                        k--;
                    }
                }else{
                    if(seats[i-1]==0 && seats[i+1]==0){
                        seats[i]=1;
                        k--;
                    }
                }
            }
            if(k==0)
            break;
        }
        return k==0;
    }
};
