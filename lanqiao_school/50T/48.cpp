#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+233;
typedef long long ll;
ll n,m,a[maxn],sum[maxn],add[maxn];
ll t;
ll L[maxn],R[maxn],pos[maxn];
int op,l1,r1,l2,r2;
void change(int l,int r,ll d)
{
    int p=pos[l],q=pos[r];
    if(p==q)
    {
        for(int i=l;i<=r;i++) a[i]+=d;
        sum[p]+=d*(r-l+1);
    }
    else
    {
        for(int i=p+1;i<=q-1;i++) add[i]+=d;
        for(int i=l;i<=R[p];i++) a[i]+=d;
        sum[p]+=d*(R[p]-l+1);
        for(int i=L[q];i<=r;i++) a[i]+=d;
        sum[q]+=d*(r-L[q]+1);
    }
}
ll tmp[maxn];
void cp(int l1,int r1,int l2,int r2)
{
    for(int j=l1,i=l2;i<=r2;i++,j++) tmp[j]=a[i]+add[pos[i]];
    int p=pos[l1],q=pos[r1];
    if(p==q)
    {
        sum[p]=0;
        for(int i=L[p];i<=l1-1;i++) sum[p]+=a[i]+add[p];
        for(int i=l1;i<=r1;i++) a[i]=tmp[i],sum[p]+=a[i];
        for(int i=r1+1;i<=R[p];i++) sum[p]+=a[i]+add[p];
        add[p]=0;
    }
    else
    {
        for(int i=p+1;i<=q-1;i++) sum[i]=0,add[i]=0;
        for(int i=R[p]+1;i<=L[q]-1;i++)
        {
            a[i]=tmp[i];
            sum[pos[i]]+=a[i];
        }

        sum[p]=0;
        for(int i=L[p];i<=l1-1;i++) sum[p]+=a[i]+add[p];
        for(int i=l1;i<=R[p];i++) a[i]=tmp[i],sum[p]+=a[i];
        add[p]=0;

        sum[q]=0;
        for(int i=r1+1;i<=R[q];i++) sum[q]+=a[i]+add[q];
        for(int i=L[q];i<=r1;i++) a[i]=tmp[i],sum[q]+=a[i];
        add[q]=0;
    }
    
}
ll ask(int l,int r)
{
    int p=pos[l],q=pos[r];
    ll ans=0;
    if(p==q)
    {
        for(int i=l;i<=r;i++) ans+=a[i];
        ans+=add[p]*(r-l+1);
    }
    else
    {
        for(int i=p+1;i<=q-1;i++) ans+=sum[i]+add[i]*(R[i]-L[i]+1);
        for(int i=l;i<=R[p];i++) ans+=a[i];
        ans+=add[p]*(R[p]-l+1);
        for(int i=L[q];i<=r;i++) ans+=a[i];
        ans+=add[q]*(r-L[q]+1);
    }
    return ans;
}
int main()
{
    freopen("C:\\work\\bk\\lanqiao_school\\50T\\data\\input4.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%lld",&n);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    t=sqrt(n);
    for(int i=1;i<=t;i++)
    {
        L[i]=(i-1)*t+1;
        R[i]=i*t;
    }
    if(R[t]<n) t++,L[t]=R[t-1]+1,R[t]=n;
    for(int i=1;i<=t;i++)
    {
        for(int j=L[i];j<=R[i];j++)
        {
            pos[j]=i;
            sum[i]+=a[j];
        }
    }
    while(m--)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d%d",&l1,&r1,&l2);
            change(l1,r1,l2);
        }
        else if(op==2)
        {
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            cp(l1,r1,l2,r2);
        }
        else
        {
            scanf("%d%d",&l1,&r1);
            printf("%lld\n",ask(l1,r1));
        }
    }
}