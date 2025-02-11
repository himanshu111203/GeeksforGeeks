class Solution {
  public:
    bool compute(Node* head) {
        string ans="";
        while(head){
            ans+=head->data;
            head=head->next;
        }
        int a=0,b=ans.size()-1;
        while(a<b){
            if(ans[a++]!=ans[b--])
            return 0;
        }
        return 1;
    }
};
