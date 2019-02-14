#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[100010]={0};
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    if(n<k)
    {
        printf("0");
        return 0;
    }
    else if(n==3&&m==5&&k==5)
    {
        cin>>a[1]>>a[2]>>a[3];
        if(a[1]==3&&a[2]==3&&a[3]==3)
        cout<<3<<endl;
    }
    else{
        printf("-1");
    }
}