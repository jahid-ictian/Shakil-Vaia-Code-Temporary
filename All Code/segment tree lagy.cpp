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
#define mp m_p make_pair

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

struct ST
{
    i64 prop,sum;
}tree[4*100005];

int t,n,q,x,y,co=0,p;
i64 val;

void update(int node, int b, int e, int l, int r, i64 x)
{
    if(l>e || r<b) return;
    if(l<=b && r>=e)
    {
        tree[node].sum+=(x*(e-b+1));
        tree[node].prop+=x;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    update(left,b,mid,l,r,x);
    update(right,mid+1,e,l,r,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
    return;
}

i64 query(int node, int b, int e, int l, int r, i64 carry=0)
{
    if(l>e || r<b) return 0LL;
    if(l<=b && r>=e) return tree[node].sum+(e-b+1)*carry;
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    return query(left,b,mid,l,r,tree[node].prop+carry)+query(right,mid+1,e,l,r,tree[node].prop+carry);
}

int main()
{
    S(t);
    while(t--)
    {
        S2(n,q);
        mem(tree,0);
        while(q--)
        {
            S(p);
            if(p==0)
            {
              S2(x,y);sc("%lld",&val);
              update(1,1,n,x,y,val);
            }
            else
            {
              S2(x,y);
              i64 res=query(1,1,n,x,y,0LL);
              pf("%lld\n",res);
            }
        }
    }
    return 0;
}

