class Solution {
  public:
    void find(Node *root,int k,vector<int>&arr,int &ans){
        if(!root)
        return;
        arr.push_back(root->data);
        int sum=0;
        for(int i=arr.size()-1;i>=0;i--){
            sum+=arr[i];
            if(sum==k)
            ans++;
        }
        find(root->left,k,arr,ans);
        find(root->right,k,arr,ans);
        //Backtrack - Remove current node from path
        arr.pop_back();
    }
    int sumK(Node *root, int k) {
        vector<int>arr;
        int ans=0;
        find(root,k,arr,ans);
        return ans;
    }
};
