#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,np[101];
string s;
bool check()
{
    return (s.find("L*L")==string::npos && s.find("LO*")==string::npos && s.find("*OL")==string::npos);
}
int main()
{
    cin>>n;
    while(n--)
    {
        memset(np,0,sizeof(np));
        cin>>s;
        int len=s.length();
        int cnt=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='*') cnt++;
        }
        if(check())
        {
            if(s.find("L**L")!=string::npos)
            { 
                if(cnt&1) cout<<"1\n";
                else cout<<"-1\n";
                continue;
            }
            else
            {
                int k=s.find("***L");
                while(k!=string::npos)
                {
                    s[k]='L';
                    if(check()) for(int i=k;i<k+3;i++) np[i]++;
                    s[k]='*';
                    k=s.find("***L",k+3);
                }
                k=s.find("L***");
                while(k!=string::npos)
                {
                    s[k+3]='L';
                    if(check()) for(int i=k+1;i<k+3;i++) np[i]++;
                    s[k]='*';
                    k=s.find("L***",k+3);
                }
                int tot=0;
                for(int i=1;i<s.length();i++) if(np[i]!=np[i-1] && np[i]==1) tot++; 
                if(tot==0)
                {
                    cout<<"0\n";
                    continue;
                }
                if((cnt-3) % 2 == 0)
                {
                    cout<<"1\n";
                    continue;
                }
                if((cnt-3) % 2 == 1)
                {
                    if(tot>1) cout<<"-1\n";
                    else cout<<"0\n";
                }
            }   
        }
        else
        {
            cout<<"1\n";
        }    
    }
}