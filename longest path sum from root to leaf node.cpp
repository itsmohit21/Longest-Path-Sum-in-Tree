class Solution
{
public:
    void helper(Node *r,int &n,int cnt,int sum,int &ans)
    {
        if(!r)
            return ;
        if(r->left==NULL&&r->right==NULL)
        {
            if(cnt>n)
            {
                n=cnt;
                ans=sum;
            }
            else if(cnt==n)
            {
                ans=max(ans,sum);
            }
            cnt=1;
        }
        if(r->left)
            helper(r->left,n,cnt+1,r->left->data+sum,ans);
        if(r->right)
            helper(r->right,n,cnt+1,r->right->data+sum,ans);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        if(!root)
            return 0;
        int n=-1,cnt=1,sum=root->data,ans=0;
        helper(root,n,cnt,sum,ans);
        return ans;
    }
};
