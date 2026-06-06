class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        pos--;
        int a=0;
        while(pos){
            if(pos&1)
            a++;
            pos>>=1;
        }
        return (a%2==0)?"Engineer":"Doctor";
    }
};
