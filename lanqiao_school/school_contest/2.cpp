#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fac[15]={0};
char a[15];
void init()
{
    fac[0]=1;
    for(ll i=1;i<=10;i++) fac[i]=fac[i-1]*i;
}
int main()
{
    init();
    scanf("%s",a);
    ll ans=0;
    for(int i=0;i<strlen(a);i++)
    {
        ll tmp=0;
        for(int j=i+1;j<strlen(a);j++)
        {
            if(a[j]<a[i]) tmp++;
        }
        ans+=tmp*fac[strlen(a)-1-i];
    }
    printf("%lld",ans);
}