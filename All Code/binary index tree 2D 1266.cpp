//Bismillahir Rahmanir Rahim
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<bitset>
#include<ctime>
using namespace std;

#define i64 long long int
#define u64 unsigned long long int

#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)

#define repc(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define repr(i,a,b) for(__typeof(b) i=(a); i>=(b); i--)

#define clr(a) a.clear()
#define sz(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof a)
#define ERASE(a) a.erase(a.begin(),a.end())

#define sc scanf
#define S(z) scanf("%d",&z)
#define SL(z) scanf("%I64d",&z)
#define S2(xx,zz) scanf("%d %d",&xx,&zz)
#define SL2(xx,zz) scanf("%I64d %I64d",&xx,&zz)
#define SC(z) scanf("%s",&z)

#define pf printf
#define pfn printf("\n")
#define PF(z) printf("%d",z)
#define PFL(z) printf("%I64d",z)
#define PF2(x,y) printf("%d %d",x,y)
#define PFL(z) printf("%I64d",z)
#define PFS(z) printf("%s",z)

#define ff first
#define ss second
#define mp make_pair

#define MI map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define SI set<int>
#define SS set<string>
#define SMI multiset<int>
#define VI vector<int>
#define VI2 vector < vector < int > >
#define QU queue<int>
#define PQU priority_queue<int>
#define STK stack<int>
#define pb push_back

#define inf 2000000000
#define pi  acos(-1.0)
#define MAX 1000007
#define MOD 1000000007
#define eps 1e-9

template <class T>T sqr(T x) {return x*x;}
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0) return 1;
    if(e%2==0){i64 t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((i64)bigmod(p,e-1,M)*(i64)p)%M;
}
template <class T> inline T bigexp(T p,T e)
{
    if(e==0)return 1;
    if(e%2==0){i64 t=bigexp(p,e/2);return (T)((t*t));}
    return (T)((i64)bigexp(p,e-1)*(i64)p);
}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int dx4[]={1,0,-1,0};int dy4[]={0,1,0,-1}; //4 Direction
int dx8[]={1,1,0,-1,-1,-1,0,1};int dy8[]={0,1,1,1,0,-1,-1,-1};//8 direction
int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
/*
struct Graph
{
    int u,v,w;
    bool operator<(const Graph& p)
    const {return w<p.w;} // oporerta chotor jnne
}edge[10];

vector<int>edges,cost;
int l=lower_bound(a+1,a+5,4)-a;
///amake 1 theke 5 tomo index porjnto search dibe. jdi match khay taile oi index i or na match khele 1 add kore dibe.
int u=upper_bound(a+1,a+5,18)-a;
///amake 1 theke 5 tomo index porjnto search dibe. match hok r na hok 1 add kore dibe.
//***last e ekta extra largest element both khetre add korte hbe.
struct compare
{
    bool operator()(const int&l,const int&r)
    {
        return l>r;
    }
};
priority_queue<int,vector<int>,compare>pq;
*/
/******************* Code Starts here *******************/

///http://www.geeksforgeeks.org/two-dimensional-binary-indexed-tree-or-fenwick-tree/
///https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/

int t,q,x,y,x1,y11,x2,y2,c,ind,res,co=0,tree[1005][1005],bl[1005][1005];

void update(int x, int y, int val)
{
    int y1;
    while(x<=1001)
    {
      y1=y;
      while(y1<=1001)
      {
          tree[x][y1]+=val;
          y1+=(y1 & -y1);
      }
      x+=(x & -x);
    }
}

int query(int x ,int y)
{
    int sum=0,y1;
    while(x)
    {
       y1=y;
       while(y1)
       {
           sum+=tree[x][y1];
           y1-=(y1 & -y1);
       }
       x-=(x & -x);
    }
    return sum;
}

int main()
{
    S(t);
    while(t--)
    {
        mem(tree,0);
        pf("Case %d:\n",++co);
       S(q);
       while(q--)
       {
           S(ind);
           if(ind==0)
           {
             S2(x,y);
             x++;y++;
             if(bl[x][y]!=co)
             {
                 bl[x][y]=co;
                 update(x,y,1);
             }
           }
           else
           {
             sc("%d %d %d %d",&x1,&y11,&x2,&y2);
             res=0;
             x1++;y11++;x2++;y2++;
             res=query(x2,y2);
             res-=query(x2,y11-1);
             res-=query(x1-1,y2);
             res+=query(x1-1,y11-1);
             pf("%d\n",res);
           }
       }
    }
    return 0;
}

