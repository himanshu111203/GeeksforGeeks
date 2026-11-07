class Solution {
  public:
    vector<string> generateUsernames(vector<string> arr) {

        vector<string> ans;
        unordered_map<string,bool> visited;

        for (auto x : arr) {
            visited[x] = false;
        }

        for (int i=0;i<arr.size();i++) {

            if (visited[arr[i]] == false) {
                ans.push_back(arr[i]);
                visited[arr[i]] = true;
            } else {

                string str = arr[i];
                int k = 1;
                string news = str;

                while (visited.find(news) != visited.end()) {
                    news = str+to_string(k);
                    k++;
                }

                visited[news] = false;
                ans.push_back(news);
            }
        }

        return ans;

    }
};
