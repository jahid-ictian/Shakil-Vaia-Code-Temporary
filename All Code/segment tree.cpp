//Bismillahir Rahmanir Rahim
//CoU_Campus_Boyz
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
#define sc scanf
#define pf printf
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
#define rep(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define repc(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define S(z) scanf("%d",&z)
#define S2(xx,zz) scanf("%d %d",&xx,&zz)
#define SC(z) scanf("%s",&z)
#define clr(a) a.clear()
#define sz(a) (int)a.size()
#define pfn printf("\n")
#define mem(a,b) memset(a,b,sizeof a)
#define ERASE(a) a.erase(a.begin(),a.end())

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
    const {return w>p.w;} // oporerta chotor jnne
}edge[10];

vector<int>edges,cost;
*/

int ar[10000],tree[30000];

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=ar[b];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
    return;
}

int query(int node, int b, int e, int i, int j)
{
 if(b>=i && e<=j) return tree[node];
 if(b>j ||  e<i) return 0;
 int left=2*node;
 int right=2*node+1;
 int mid=(b+e)/2;
 int p1=query(left,b,mid,i,j);
 int p2=query(right,mid+1,e,i,j);
 return p1+p2;
}

void update(int node, int b, int e, int pos, int newV)
{
  if(pos>=b && pos<=e)
  {
      tree[node]=newV;
      return ;
  }
  if(pos<b || pos>e) return;
  int left=2*node;
  int right=2*node+1;
  int mid=(b+e)/2;
  update(left, b,mid,pos,newV);
  update(right,mid+1,e,pos,newV);
  tree[node]=tree[left]+tree[right];
}

int main()
{
    int n,q,x,y,pos,newV;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    printf("Enter the elements:");
    repc(i,1,n) S(ar[i]);
    init(1,1,n);

    pf("Enter the number of query: ");
    scanf("%d",&q);
    while(q--){
    scanf("%d %d",&x,&y);
    int result=query(1,1,n,x,y);
    pf("%d\n",result);}
    printf("Enter the value and position of newValue:");
    scanf("%d %d\n",&pos,&newV);
    update(1,1,n,pos,newV);

    pf("Enter the number of query: ");
    scanf("%d",&q);
    while(q--){
    scanf("%d %d",&x,&y);
    int result=query(1,1,n,x,y);
    pf("%d\n",result);}
    return 0;
}
