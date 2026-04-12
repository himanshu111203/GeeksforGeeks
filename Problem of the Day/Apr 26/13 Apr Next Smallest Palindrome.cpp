class Solution {
  public:
    vector<int> nextPalindrome(vector<int>& num) {
        // code here
        int n = num.size();

        // Step 1: Check all 9s
        bool all9 = true;
        for(int x : num){
            if(x != 9){
                all9 = false;
                break;
            }
        }
        if(all9){
            vector<int> res(n+1, 0);
            res[0] = res[n] = 1;
            return res;
        }

        int i = n/2 - 1;
        int j = (n%2) ? n/2 + 1 : n/2;

        // Step 2: Find if left < right
        while(i >= 0 && num[i] == num[j]){
            i--; j++;
        }

        bool leftSmaller = false;
        if(i < 0 || num[i] < num[j])
            leftSmaller = true;

        // Step 3: Mirror left → right
        i = n/2 - 1;
        j = (n%2) ? n/2 + 1 : n/2;

        while(i >= 0){
            num[j] = num[i];
            i--; j++;
        }

        // Step 4: If needed, increment middle
        if(leftSmaller){
            int carry = 1;
            i = n/2 - 1;

            if(n % 2 == 1){
                num[n/2] += carry;
                carry = num[n/2] / 10;
                num[n/2] %= 10;
                j = n/2 + 1;
            } else {
                j = n/2;
            }

            while(i >= 0){
                num[i] += carry;
                carry = num[i] / 10;
                num[i] %= 10;

                num[j] = num[i];
                i--; j++;
            }
        }

        return num;
    }
};
