#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
char s1[N],s2[N];
int main()
{
    int n=0;
    scanf("%s",s1);
    scanf("%d",&n);
    while(n--)
    {
        int cnt=1;
        int s2p=0;
        int len=strlen(s1);
        for(int i=1;i<len;i++)
        {
            if(s1[i]!=s1[i-1])
            {
                s2[s2p++]=cnt+'0';
                s2[s2p++]=s1[i-1];
                cnt=1;
            }
            else cnt++;
        }
        s2[s2p++]=cnt+'0';
        s2[s2p++]=s1[len-1];
        s2[s2p]='\0';
        cnt=1;
         
        memcpy(s1,s2,sizeof(s2));
    }
    cout<<s1;
}