class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n=s.size();
        // Step 1: Record the last occurrence of each digit (0–9)
        // temp[digit] = last index where 'digit' appears in string
        vector<int>temp(10);
        for(int i=0;i<n;i++)
        temp[s[i]-'0']=i;
       // Step 2: Traverse digits from left to right
        for(int i=0;i<n;i++){
            // Step 3: For each position, check if a bigger digit (j)
            // exists later in the string
            for(int j=9;j>s[i]-'0';j--){
                // Condition: candidate j occurs later (temp[j] > i)
                if(i<temp[j]){
                    swap(s[i],s[temp[j]]);
                    return s;
                }
            }
        }
        return s;
    }
};
