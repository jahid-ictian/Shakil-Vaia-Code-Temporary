//Bismillahir Rahmanir Rahim
//Md. Jahidul Hasan Shakil
//Dept. of ICT, Comilla University

#include<bits/stdc++.h>
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
#define pfs printf(" ")
#define PF(z) printf("%d",z)
#define PFL(z) printf("%I64d",z)
#define PF2(x,y) printf("%d %d",x,y)
#define PFS(z) printf("%s",z)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define inf 2000000007
#define pi  acos(-1.0)
#define MAX 1000
#define MOD 1000000007LL
#define eps 1e-13

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
int nx8[]={1,1,-1,-1,2,2,-2,-2};int ny8[]={2,-2,2,-2,1,-1,1,-1};//8 direction
int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
/*
struct Graph
{
    int u,v,w;
    bool operator<(const Graph& p)
    const {return w<p.w;} // oporerta chotor jnne
}edge[10];
struct compare
{
    bool operator()(const int&l,const int&r)
    {
        return l>r;
    }
};
priority_queue<int,vector<int>,compare>pq;

i64 ncr[1005][1005];
void nCr()
{
    repc(i,0,1002) ncr[i][0]=1LL;
    repc(i,1,1002)
    repc(j,1,i)
    ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%MOD;
}


*/
/******************* Code Starts here *******************/
//directed graph
int n,m,component,u,v;
bool visited[MAX],color[MAX];
stack<int>s;
vector<int>edges[MAX],components[MAX],redges[MAX];

void dfs(int u)
{
    color[u]=true;
    for(int i=0;i<(int)edges[u].size();i++)
        if(color[edges[u][i]]==false)
        dfs(edges[u][i]);
    s.push(u);
}

void dfs2(int u, int component)
{
    visited[u]=true;
    components[component].pb(u);
    for(int i=0;i<(int)redges[u].size();i++)
    {
        if(visited[redges[u][i]]==false)
            dfs2(redges[u][i],component);
    }
}
void find_scc()
{
    repc(i,1,n)
    visited[i]=false,color[i]=false,components[i].clear();
    component=0;
    while(!s.empty()) s.pop();
    for(int i=1;i<=n;i++)
        if(color[i]==false)
        dfs(i);
    while(!s.empty())
    {
        u=s.top();
        s.pop();
        if(visited[u]==false)
        {
            component++;
            dfs2(u,component);
        }
    }
}
int main()
{
    S2(n,m);
    repc(i,1,m)
    {
        S2(u,v);
        edges[u].pb(v);
        redges[v].pb(u);
    }
    find_scc();
    cout<<component,pfn;
    for(int i=1;i<=component;i++)
    {
        for(int j=0;j<components[i].size();j++)
            pf("%d ",components[i][j]);
        pfn;
    }
    repc(i,1,n) components[i].clear(),edges[i].clear(),redges[i].clear();
    return 0;
}
