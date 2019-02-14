#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
int mp[maxn][maxn];
int n,m;
int f[maxn][maxn];
int color[maxn];
int ans=0x3f3f3f3f;
void dfs(int x,int cnt)
{
    if(cnt>=ans) return;
    if(x==n+1)
    {
        ans=min(ans,cnt);
        return ;
    }
    for(int i=1;i<=cnt;i++)
    {
        int flag=1;
        for(int j=1;j<=color[i];j++)
        {
            if(mp[x][f[i][j]])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            color[i]++;
            f[i][color[i]]=x;
            dfs(x+1,cnt);
            color[i]--;
        }
    }
    color[cnt+1]++;
    f[cnt+1][color[cnt+1]]=x;
    dfs(x+1,cnt+1);
    color[cnt+1]--;
}
int main()
{
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        mp[a][b]=mp[b][a]=1;
    }
    f[1][1]=1;
    color[1]=1;
    dfs(1,1);
    cout<<ans;
}