
# 蓝桥杯历届试题做题记录

## 解题报告

标签（空格分隔）： 做题记录

---

鉴于网上蓝桥杯的大多数题目几乎找不到很好的题解，**甚至出现了很多错误的题解**。所以抽时间做了一份结题报告。
按逆序编号，和蓝桥杯练习网站上一样。有一些题在本弱博客上写过就直接贴地址了。
本报告所有题目已经由本弱亲自提交并且AC，**但不排除网站的测试数据会被增强**，以前的AC思路不一定会再次适用，建议对解题思路有疑问的先将AC代码粘上去看结果。

---

[TOC]

---

### [PREV-55 小计算器](http://lx.lanqiao.cn/problem.page?gpid=T459)

#### 题解 

`模拟`

[具体题解见博客](https://xianka.luobotou.org/?p=257)

可以先把所有进制转为十进制，方便计算，要输出的时候再转成要求的进制

#### 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,char> eco;
map<char,ll> deco;
int k=10;
ll ans=0;
char num[99];
void init()
{
    for(ll i=0;i<=9;i++)
    {
        eco[i]=i+'0';
        deco[i+'0']=i;
    }
    for(ll i='A';i<='Z';i++)
    {
        eco[i-'A'+10]=i;
        deco[i]=i-'A'+10;
    }
}
ll getnum()
{
    ll tmp=1;
    ll ret=0;
    for(int i=strlen(num)-1;i>=0;i--)
    {
        ret+=tmp*deco[num[i]];
        tmp*=k;
    }
    return ret;
}
void pout(ll tnum)
{
    //cout<<tnum<<endl;
    if(tnum==0)
    {
        printf("0\n");
        return;
    }
    int cnt[99]={0};
    while(tnum)
    {
        if(tnum/k)
        {
            cnt[++cnt[0]]=tnum%k;
            tnum/=k;
        }
        else
        {
            cnt[++cnt[0]]=tnum;
            tnum/=k;
        }
    }
    for(int i=cnt[0];i>0;i--)
    {
        printf("%c",eco[cnt[i]]);
    }
    printf("\n");
}
string inst;
void opr(int x)
{
    if(x==1) ans+=getnum();
    if(x==2) ans-=getnum();
    if(x==3) ans*=getnum();
    if(x==4) ans/=getnum();
    if(x==5) ans%=getnum();
}
int main()
{
    //freopen("input4.txt","r",stdin);
    init();
    int n;
    scanf("%d",&n);
    int opra=1;
    while(n--)
    {
        //cout<<n<<':'<<ans<<endl;
        cin>>inst;
        if(inst=="CLEAR")
        {
            ans=0;
            opra=1;
        }
        else if(inst=="NUM")
        {
            scanf("%s",num);
            //cout<<ans<<"+-*/%"[opra-1]<<getnum()<<endl;
            opr(opra);
        }
        else if(inst=="CHANGE") scanf("%d",&k);
        else if(inst=="ADD") opra=1;
        else if(inst=="SUB") opra=2;
        else if(inst=="MUL") opra=3;
        else if(inst=="DIV") opra=4;
        else if(inst=="MOD") opra=5;
        else if(inst=="EQUAL") pout(ans);
    }
}
```

### [PREV-54 合根植物](http://lx.lanqiao.cn/problem.page?gpid=T458)

#### 题解

`数据结构` `并查集`

用并查集合并输入的两个植物，最后找有多少个连通块就行了

#### 代码

```cpp
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
    //freopen("input3.txt","r",stdin);
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
```

### [PREV-53 分考场](http://lx.lanqiao.cn/problem.page?gpid=T457)

#### 题解

`搜索`

本来以为需要建补图，找最大团的个数，没想到是个暴力题
搜索染色。直接暴力枚举每个人是否可以染成以前有的颜色，可以的话就试一下每种颜色，看最后染完了是否小于答案。不行的话就新开一种颜色。

#### 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
int mp[maxn][maxn];
int n,m;
int f[maxn][maxn];
int color[maxn];
int ans=0x3f3f3f3f;
void dfs(int x,int cnt)
{
    if(cnt>=ans) return;
    if(x==n+1)
    {
        ans=min(ans,cnt);
        return ;
    }
    for(int i=1;i<=cnt;i++)
    {
        int flag=1;
        for(int j=1;j<=color[i];j++)
        {
            if(mp[x][f[i][j]])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            color[i]++;
            f[i][color[i]]=x;
            dfs(x+1,cnt);
            color[i]--;
        }
    }
    color[cnt+1]++;
    f[cnt+1][color[cnt+1]]=x;
    dfs(x+1,cnt+1);
    color[cnt+1]--;
}
int main()
{
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        mp[a][b]=mp[b][a]=1;
    }
    f[1][1]=1;
    color[1]=1;
    dfs(1,1);
    cout<<ans;
}
```

### [PREV-52 小数第n位](http://lx.lanqiao.cn/problem.page?gpid=T456)

#### 题解

`数论`

[传送门](https://xianka.luobotou.org/?p=259)

考虑到n取1e10，double的精度肯定是不够的。所以把数字放大10^n+2倍%1000进行计算。但由于b和1000不一定互质，所以不一定找得到逆元。

- 这里介绍一个公式

$$\frac{a}{b} \mod p = \frac{a \mod b \times p}{b}$$

所以本题：

$$\frac{a}{b} \times 10^{n+2} \mod 10^3 = \frac{a \times 10^{n+2} \mod b \times 10^3}{b} $$

$$ = \frac{(a \mod b \times 10^3) \times (10^{n+2} \mod b \times 10^3)}{b} $$

n取1e10，所以快速幂一下。就做完了，简单数论（其实还要注意前导零，~~但我写的是未来程序就没管~~，输出的时候用`printf()`就行）

#### 代码 

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,n,mod;
ll ksm(ll n,ll k)
{
    ll ret=1;
    while(k)
    {
        if(k&1) ret=((ret%mod)*(n%mod))%mod;
        n=(n%mod)*(n%mod);
        k>>=1;
    }
    return ret%mod;
}
int main()
{
    cin>>a>>b>>n;
    mod=b*1000;
    ll son=(a%mod*ksm(10,n+2))%mod;
    ll ans=son/b;
    cout<<ans;
}
```

### [PREV-49 发现环](http://lx.lanqiao.cn/problem.page?gpid=T453)

#### 题解

`并查集` `图论` `数据结构`

由于这棵树上只多了一条边，所以先用并查集检查读入的两个点是否有公共祖先，如果有，那么环的起点和终点必定是他们两个，后面的数据可以直接不要了。dfs的时候记录每个点的前驱，也就是父节点，最后排序输出

#### 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
vector<int> e[maxn];
int n;
int fa[maxn],ans[maxn];
int ff(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=ff(fa[x]);
}
void uni(int x,int y)
{
    fa[ff(x)]=ff(y);
}
int vis[maxn],pre[maxn];
void dfs(int x,int p)
{
    pre[x]=p;
    for(int i=0;i<e[x].size();i++)
    {
        int v=e[x][i];
        if(v!=p) dfs(v,x);
    }
}
int main()
{
    int a,b;
    int flag=0,ed=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        if(flag!=0) continue; 
        if(ff(a)==ff(b))
        {
            flag=a;
            ed=b;
        }
        else
        {
            e[a].push_back(b);
            e[b].push_back(a);
            uni(a,b);
        }
    }
    dfs(flag,flag);

    while(pre[ed]!=ed)
    {
        ans[++ans[0]]=ed;
        ed=pre[ed];
    }
    ans[++ans[0]]=ed;
    sort(ans+1,ans+1+ans[0]);
    for(int i=1;i<=ans[0];i++) printf("%d ",ans[i]);
}
```

### [PREV-47 区间移位](http://lx.lanqiao.cn/problem.page?gpid=T451)

#### 题解

`贪心` `二分`

[传送门](https://xianka.luobotou.org/?p=335)

一开始我也没想出来怎么贪，~~wjjj乱猜结论就是对的%%%~~
二分res,从左到右,把b小的线段放在当前点
查找最小的b需要n次，所以查找速度要快，可以二分来找，也可以数据结构优化。总复杂度$O(nlog^{2}(n))$

#### 代码

```cpp
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
```

### [PREV-46 填字母游戏](http://lx.lanqiao.cn/problem.page?gpid=T450)

#### 题解

`博弈` `构造`

这题实际上是[EC FINAL的一道题](https://vjudge.net/problem/Gym-101775L)的改编。EC FINAL原题的题意是给一个长度n，问胜负情况。
原题和本题的突破点就是发现`L**L`是个必胜态，只要谁先走这两个空位里的任何一个谁就是必败的。
这篇博客题解写得很好：[链接](https://blog.csdn.net/Lngxling/article/details/82905435)
可以发现，在最优走法下，只需要四步就可以决出胜负，**而胜负的依据就是先构造出`L**L`的状态并且剩余空格为偶数的人A是必胜的，如果选择构造必胜态以后剩余空格是奇数，那么A就是必败的，此时A可以选择不构造这个必胜态并且破坏掉，那么下一个人B如果能够构造必胜态A就是必败的，如果B无法构造必胜态那么在最优走法下最坏情况也就是平局。**
那么总结一下做法就是：

- 先看初始局面有没有`L**L`，如果有，看剩余步数是偶数还是奇数，如果是奇数，那么必胜，如果是偶数，那么必败。
- 如果没有，那么尝试能否构造一个，找`***L`或者`L***`，如果构造成功并且剩余格子为偶数，那么必胜，如果为奇数，看看有没有其他地方能够构造并且不受这个点的影响（因为如果有影响肯定会被破坏），如果找得到，那么就是必败，如果找不到，就是平局（因为在最优策略下不可能再产生机会）
- 如果不能构造，那就是平局

值得注意的是，`L****L`是不能构造的，`*O***L`也是不能构造的，因为构造成功就是必败的。所以在构造完以后还要check一下。

#### 代码

```cpp
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
```