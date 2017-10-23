//Bismillahir Rahmanir Rahim
//Md. Jahidul Hasan
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
#define erase(a) a.erase(a.begin(),a.end())

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
bool isVowel(char ch){ch=tolower(ch);if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}
bool isUpper(char c){return c>='A' && c<='Z';}
bool isLower(char c){return c>='a' && c<='z';}

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

int n,e;
int mat[105][105],next[105][105],path[100],c;

int floyd(int src, int dest)
{
    repc(k,1,n)
    repc(i,1,n)
    repc(j,1,n)
    if(mat[i][j]>mat[i][k]+mat[k][j])
    {
        mat[i][j]=mat[i][k]+mat[k][j];
        next[i][j]=next[i][k];
    }
    return mat[src][dest];
}

void print_path(int src, int dest)
{
   path[++c]=src;
   /// ami 1st e sob index e destination set kore dilam.
   /// now jdi maje k tomo node e jaowa lage then
   /// ami mat[src][dest] e mat[src][k] set korlam

   while(src!=dest)
   {
       src=next[src][dest];
       path[++c]=src;
   }
}
int main()
{
    int e,x,y,val,src,dest;
    S2(n,e);
    mem(mat,63);
    repc(i,1,n) mat[i][i]=0;
    repc(i,1,e)
    {
        S2(x,y);S(val);
        mat[x][y]=val;
        //mat[y][x]=val;
    }
    pf("Enter the source and destination: ");
    S2(src,dest);
    // setting next to the destination
    repc(i,1,n)
    repc(j,1,n)
    next[i][j]=j;
    int res=floyd(src,dest);
    pf("Shortest length is: %d\n",res);
    c=0;
    print_path(src,dest);
    pf("Path is: ");
    repc(i,1,c) pf("%d   ",path[i]);
    pfn;
    return 0;
}
