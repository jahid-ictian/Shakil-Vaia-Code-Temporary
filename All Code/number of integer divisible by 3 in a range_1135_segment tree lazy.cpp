///TLE

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
#define S2(xx,zz) scanf("%d %d",&xx,&zz)
#define SC(z) scanf("%s",&z)

#define pf printf
#define pfn printf("\n")
#define PF(z) printf("%d",z)
#define PF2(x,y) printf("%d %d",x,y)
#define PFL(z) printf("%I64d",z)
#define PFS(z) printf("%s",z)

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
#define ff first
#define ss second

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
*/
/******************* Code Starts here *******************/
///0 keu kintu 3 dara vaag jay jeta d te rakhchi build korar somoy, taile protitai prothom jay.
struct T
{
    int a,b,c,d,prop;//a=1,b=2,c=3
}tree[300005];

void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].d=1;//protita index ke counting
        return ;
    }
    int left=2*node,right=2*node+1,mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].d=tree[left].d+tree[right].d;
}

void update(int node, int b, int e, int i, int j)
{
    if(b>j || e<i)
    {
        return;
    }
    if(b>=i && e<=j)
    {
        int tamp=tree[node].c+tree[node].d;// three+zero
        tree[node].c=tree[node].b;
        tree[node].b=tree[node].a;
        tree[node].a=tamp;
        tree[node].d=0;//zero gula removed
        tree[node].prop++;
        return;
    }
    int left=2*node,right=2*node+1,mid=(b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);

    tree[node].a=tree[left].a+tree[right].a;
    tree[node].b=tree[left].b+tree[right].b;
    tree[node].c=tree[left].c+tree[right].c;
    tree[node].d=tree[left].d+tree[right].d;
    int rem=tree[node].prop%3;
       if(rem==1)
       {
        int tamp=tree[node].c+tree[node].d; tree[node].c=tree[node].b;
            tree[node].b=tree[node].a; tree[node].a=tamp;
       tree[node].d=0;
       }
       else if(rem==2)
       {
        int tamp=tree[node].c+tree[node].d; tree[node].c=tree[node].b;
            tree[node].b=tree[node].a; tree[node].a=tamp;
            tamp=tree[node].c;tree[node].c=tree[node].b;
            tree[node].b=tree[node].a; tree[node].a=tamp;
            tree[node].d=0;
       }
    return ;
}

int query(int node, int b, int e, int i, int j, int carry)
{
    if(b>j || e<i) return 0;
    if(b>=i && e<=j)
    {
       int rem=carry%3;
       int aa=tree[node].a,bb=tree[node].b,cc=tree[node].c+tree[node].d;
       if(rem==1)
       {
        int tamp=cc; cc=bb;
            bb=aa; aa=tamp;
       }
       else if(rem==2)
       {
        int tamp=cc; cc=bb;
            bb=aa; aa=tamp;
            tamp=cc; cc=bb;
            bb=aa; aa=tamp;
       }
       return cc;
    }
    int left=2*node,right=2*node+1,mid=(b+e)/2;
    return query(left,b,mid,i,j,carry+tree[node].prop)+query(right,mid+1,e,i,j,tree[node].prop+carry);
}

int main()
{
    int n,q,t,id,x,y,res,co=0;
    S(t);
    while(t--)
    {
        mem(tree,0);
        S2(n,q);
        build(1,1,n);
        pf("Case %d:\n",++co);
        while(q--)
        {
            S(id);
            if(id==0)
            {
               S2(x,y);
               update(1,1,n,x+1,y+1);
            }
            else
            {
               S2(x,y);
               x++;y++;
               res=query(1,1,n,x,y,0);
               pf("%d\n",res);
            }
        }
    }
    return 0;
}


