#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const double eps=1e-12;
const int N=20000;
vector<pii> ab;
int vis[10001];
multiset<pii> c2;
int line[10001]; 
int main()
{
    int n,a,b;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        a*=2;b*=2;
        c2.insert({b,a});
    }
    int l=0,r=N;
    while(r>l)
    {
        multiset<pii> c1(c2);
        int mid=(l+r)>>1;
        int now=0;
        while(1)
        {
            int flag=0;
            multiset<pii>::iterator it;
            for(it=c1.begin();it!=c1.end();it++)
            {
                pii tmp=*it;
                int tta=tmp.second,ttb=tmp.first;
                if(tta-mid <= now && ttb+mid >= now)
                {
                    flag=1;
                    int len=ttb-tta;
                    if(now<=tta+mid) now+=len;
                    else now=ttb+mid;
                    c1.erase(it);
                    break;
                }
            }
            if(!flag || now>=N) break;
        }
        if(now>=N) r=mid;
        else l=mid+1;
    }
    double ans=l*1.0/2.0;
    cout<<ans;
}