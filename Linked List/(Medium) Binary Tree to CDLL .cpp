class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    void solve(Node *root, vector<int> &arr){
        if (!root)
        return;
        solve(root->left, arr);
        arr.push_back(root->data);
        solve(root->right, arr);
    }
    Node *bTreeToCList(Node *root)
    {
        vector<int> arr;
        solve(root, arr);
        if (arr.empty())
        return NULL;
        Node *head = new Node();
        head->data = arr[0];
        Node *tail = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node();
            temp->data = arr[i];
            tail->right = temp;
            temp->left = tail;
            tail = temp;
        }
        tail->right = head;
        head->left = tail;
        return head;
    }
};
