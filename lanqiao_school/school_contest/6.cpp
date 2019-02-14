#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=1e5+233;
set<int> s;
int b[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        if(b[i]<=n)
        s.erase(b[i]);
    }
    set<int>::iterator it=s.begin();
    int pos=1;
    for(int i=1;i<=n;i++)
    {
        if(*it<b[pos]||pos>m)
        {
            cout<<*it<<endl;
            it++;
        }
        else
        {
            cout<<b[pos]<<endl;
            pos++;
        }
    }
}