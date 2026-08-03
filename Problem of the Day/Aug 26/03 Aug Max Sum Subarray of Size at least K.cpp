int n = arr.size();

        vector<int> best(n);
        best[0] = arr[0];

        for (int i = 1; i < n; i++)
            best[i] = max(arr[i], best[i - 1] + arr[i]);

        int window = 0;
        for (int i = 0; i < k; i++)
            window += arr[i];

        int ans = window;

        for (int i = k; i < n; i++) {
            window += arr[i] - arr[i - k];

            ans = max(ans, window);                   
            ans = max(ans, window + best[i - k]);     
        }

        return ans;
