#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
vector<int> e[maxn];
int n;
int fa[maxn],ans[maxn];
int ff(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=ff(fa[x]);
}
void uni(int x,int y)
{
    fa[ff(x)]=ff(y);
}
int vis[maxn],pre[maxn];
void dfs(int x,int p)
{
    pre[x]=p;
    for(int i=0;i<e[x].size();i++)
    {
        int v=e[x][i];
        if(v!=p) dfs(v,x);
    }
}
int main()
{
    int a,b;
    int flag=0,ed=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        if(flag!=0) continue; 
        if(ff(a)==ff(b))
        {
            flag=a;
            ed=b;
        }
        else
        {
            e[a].push_back(b);
            e[b].push_back(a);
            uni(a,b);
        }
    }
    dfs(flag,flag);
    
    while(pre[ed]!=ed)
    {
        ans[++ans[0]]=ed;
        ed=pre[ed];
    }
    ans[++ans[0]]=ed;
    sort(ans+1,ans+1+ans[0]);
    for(int i=1;i<=ans[0];i++) printf("%d ",ans[i]);
}