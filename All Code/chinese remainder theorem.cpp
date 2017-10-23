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
Articulation Point-Bridge, Bellman ford, BFS, DFS,
*/

/******************* Code Starts here *******************/
#define MAXN 100005
/*
suppose x=a1%m1; x=a2%m2; x=a[i]%m[i];
m=m1*m2*..*m[i];
Now, We need to find x where m[i] are the prime and a[i] are the remainders.
according to chinese remainder theorem,
x=a1*M1*y1+a2*M2*y2+...
m=m[1]*m[2]*m[3]....
where M[i]=m/m[i];
y[i]=inverse of M[i]%m[i]; M[i]*y[i]=1(mod m[i]);
i
now, vag na kore ami multiplicative inverse ber kore felbo extended euclid use kore;
jdi m[i] ta prime hoy tahole bigmod die e kora jay ar na hoy euclid proyojon.
*/
int main()
{
     int t,n,i,p[13],r[13],co=0;
     scanf("%d",&t);
     long long int tot,ret,mul;
     while(t--)
     {
         mul=1;
          tot=0;
         scanf("%d",&n);
         for(i=1;i<=n;i++){
         scanf("%d %d",&p[i],&r[i]); mul*=p[i];}
         for(i=1;i<=n;i++)
         {
             tot=tot+(r[i]*modinverse((i64)mul/p[i],(i64)p[i])*(mul/p[i]));
         }
         printf("Case %d: %lld\n",++co,tot%mul);
     }
    return 0;
}
