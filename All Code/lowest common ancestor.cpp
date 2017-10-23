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
#define SC(z) scanf("%s",&z)

#define S2(xx,zz) scanf("%d %d",&xx,&zz)
#define SL2(xx,zz) scanf("%I64d %I64d",&xx,&zz)

#define S3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define SL3(x,y,z) scanf("%I64d %I64d %I64d",&x,&y,&z)


#define pf printf
#define pfn printf("\n")
#define pfs printf(" ")

#define PF(z) printf("%d",z)
#define PFL(z) printf("%I64d",z)
#define PFS(z) printf("%s",z)

#define PF2(x,y) printf("%d %d",x,y)
#define PFL2(x,y) printf("%I64d %I64d",x,y)

#define PF3(x,y,z) printf("%d %d %d",x,y,z)
#define PFL3(x,y,z) printf("%I64d %I64d %I64d",x,y,z)


#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define inf 2000000007
#define pi  acos(-1.0)
#define MAX 200007
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
int nx8[]={1,1,-1,-1,2,2,-2,-2};int ny8[]={2,-2,2,-2,1,-1,1,-1};//8 direction-knight
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
///-------------------Algos-------------------///
/*

*/

/******************* Code Starts here *******************/

//LCA using sparse table technique
//Complexity: O(NlgN,lgN) -- NlgN for sparse table.. logn for each query
#define MX 100002
int L[MX]; //Level
int T[MX]; //immediate parent
int P[MX][22];
vector<int>edges[MX];

void dfs(int from,int u,int dep)
{
    T[u]=from;
    L[u]=dep;
    for(int i=0;i<(int)edges[u].size();i++)
    {
        int v=edges[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}

int lca_query(int N, int p, int q) //N=total node
  {
      int tmp,log,i;
      if (L[p]<L[q])
          tmp=p,p=q,q=tmp;

      log=1;
      while(1)
      {
        int next=log+1;
        if((1<<next)>L[p])break; //EKDOM koto powe porjnto jete pari
        log++;
      }
      //cout<<log,pfn;
      for (i=log;i>=0;i--)
      if (L[p]-(1<<i)>=L[q])
          p=P[p][i];

      if (p==q)  //already done?
          return p;
 //pfn;pfn;
      for(i=log;i>=0;i--)
      {
          //cout<<i<<" "<<log<<" "<<p<<" "<<P[p][i]<<" "<<P[q][i]<<" "<<q ,pfn;;
          if(P[p][i]!=-1 && P[p][i]!=P[q][i])
              {
                 // cout<<p<<" "<<i<<" "<<q,pfn;
                  p=P[p][i],q=P[q][i];
              }
      }

      return T[p];
  }

void lca_init(int N)
  {
      memset (P,-1,sizeof(P)); //first all parent are -1
      int i,j;
       for (i=0;i<N;i++) //1-N
          P[i][0]=T[i];

      for (j=1;1<<j < N;j++)
         for (i=0;i<N;i++) //1-N
             if (P[i][j-1]!=-1)
                 P[i][j]=P[P[i][j-1]][j-1];
 }

int main()
{
    ///zero based index
//	edges[0].pb(1);
//	edges[0].pb(2);
//	edges[2].pb(3);
//	edges[2].pb(4);
edges[0].pb(1);
edges[1].pb(2);
edges[2].pb(3);
edges[3].pb(4);
edges[4].pb(5);
edges[5].pb(6);
edges[5].pb(7);
edges[6].pb(8);
edges[7].pb(9);
	dfs(-1,0,0);//-1,1,0//jehetu root node er parent hbe -1
	lca_init(10);//10=Total node
	printf("%d\n",lca_query(10,8,9)); // total nodes(n),nodes
	return 0;
}
