#include<bits/stdc++.h>
using namespace std;
int n=0,ans=1;
pair<int,int> ant[55];
int main()
{
    int x;
    int dir,pos;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        ant[i]=make_pair(abs(x),abs(x)/x);
    }
    pos=ant[1].first;
    dir=ant[1].second;
    sort(ant+1,ant+1+n);
    if(dir==-1)
    {
        for(int i=1;i<=n;i++)
        {
            if(ant[i].first<pos&&ant[i].second==1) ans++;
            if(ant[i].first>pos&&ant[i].second==-1&&ans>1) ans++;
        }
    }
    else
    {
        for(int i=n;i>=1;i--)
        {
            if(ant[i].first>pos&&ant[i].second==-1) ans++;
            if(ant[i].first<pos&&ant[i].second==1&&ans>1) ans++;
        }
    }
    printf("%d",ans);
}