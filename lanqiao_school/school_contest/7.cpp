#include<bits/stdc++.h>
using namespace std;
int prx1,pry1,prx2,pry2;
int ogcd(int a,int b)
{
    if(b==0) return a;
    return (b,a%b);
}
int main()
{
    scanf("%d%d%d%d",&prx1,&pry1,&prx2,&pry2);
    int pgcd=ogcd(prx2-prx1,pry2-pry1);
    pgcd=abs(pgcd);
    int prxe=prx2-(prx2-prx1)/pgcd;
    int prye=pry2-(pry2-pry1)/pgcd;
    int desx=pry2-prye+prx2;
    int desy=prxe-prx2+pry2;
    printf("%d %d",desx,desy);
}