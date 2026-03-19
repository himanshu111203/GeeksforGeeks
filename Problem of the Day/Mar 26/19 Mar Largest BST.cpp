/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class box
{
    public:
    bool bst;
    int size;
    int min,max;
    box(int data)
    {
        bst=1;
        size=1;
        min=data;
        max=data;
    }
};
class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    box *find(Node *root,int &totalsize)
    {
        if(!root->left && !root->right)
        {
            totalsize=max(1,totalsize);
            return new box(root->data);
        }
        else if(!root->left && root->right)
        {
            box *head=find(root->right,totalsize);
            if(head->bst && head->min>root->data)
            {
                head->size++;
                head->min=root->data;
                totalsize=max(head->size,totalsize);
                return head;
            }
            else
            {
                head->bst=0;
                return head;
            }
        }
        else if(root->left && !root->right)
        {
            box *head=find(root->left,totalsize);
            if(head->bst && head->max<root->data)
            {
                head->size++;
                head->max=root->data;
                totalsize=max(head->size,totalsize);
                return head;
            }
            else
            {
                head->bst=0;
                return head;
            }
        }
        else
        {
            box *lefthead=find(root->left,totalsize);
            box *righthead=find(root->right,totalsize);
            if(lefthead->bst && righthead->bst && lefthead->max<root->data && righthead->min>root->data)
            {
                box *head=new box(root->data);
                head->size+=lefthead->size+righthead->size;
                totalsize=max(head->size,totalsize);
                head->min=lefthead->min;
                head->max=righthead->max;
                return head;
            }
            else
            {
                lefthead->bst=0;
                return lefthead;
            }
        }
    }
    int largestBst(Node *root) {
        // Your code here
        int totalsize=0;
    	find(root,totalsize);
    	return totalsize;
    }
};
