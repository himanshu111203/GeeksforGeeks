class Solution {
  public:
    //You need to complete this function
    void tohcal(int n,int source,int help,int dest)
    {
        if(n==1)
        {
            cout<<"move disk "<<n<<" from rod "<<source<<" to "<<dest<<endl;
            return;
        }
        tohcal(n-1,source,dest,help);
        cout<<"move disk "<<n<<" from rod "<<source<<" to "<<dest<<endl;
        tohcal(n-1,help,source,dest);
    }
    int towerOfHanoi(int n, int from, int to, int aux) {
        tohcal(n,from,to,aux);
        return pow(2,n)-1;
    }
};
