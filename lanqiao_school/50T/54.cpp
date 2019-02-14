#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
int f[maxn*maxn];
int ff(int x)
{
    if(f[x]==x) return x;
    return f[x]=ff(f[x]);
}
void uni(int x,int y)
{
    int fx=ff(x);
    int fy=ff(y);
    f[fx]=fy;
}
int m=0,n=0,k=0,a=0,b=0;
int ans=0;
int main()
{
    freopen("input3.txt","r",stdin);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m*n;i++) f[i]=i;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&a,&b);
        uni(a,b);
    }
    for(int i=1;i<=m*n;i++)
    {
        if(ff(i)==i) 
        {
            ans++;
        }
    }
    printf("%d\n",ans);
}