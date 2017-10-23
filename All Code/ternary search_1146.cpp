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
#define PF(z) printf("%d",z)
#define PFL(z) printf("%I64d",z)
#define PF2(x,y) printf("%d %d",x,y)
#define PFL(z) printf("%I64d",z)
#define PFS(z) printf("%s",z)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define inf 100000007
#define pi  acos(-1.0)
#define MAX 200007
#define MOD 10056
#define eps 1e-11

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
int t,co,p;
double ax,ay,bx,by,cx,cy,dx,dy,mid1,mid2,res,lo,hi,ax1,ay1,bx1,by1,cx1,cy1,dx1,dy2;

double dist(double tm)
{
   ax1=ax+tm*(bx-ax);
   ay1=ay+tm*(by-ay);
   cx1=cx+tm*(dx-cx);
   cy1=cy+tm*(dy-cy);
   ax1-=cx1;
   ay1-=cy1;
   ax1*=ax1;ay1*=ay1;
   return (double)sqrt(ax1+ay1);
}

int main()
{
    S(t);
    while(t--)
    {
        sc("%lf %lf %lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
        res=0;
        p=50;//300 neya standard..ami accepted hobar po time komaichi
        lo=0.0;hi=1.0;
        //integer hle hi-lo>5 rakha vlo
        while(p--)
        {
          mid1=(2*lo+hi)/3;
          mid2=(lo+2*hi)/3;
          if(dist(mid1)<dist(mid2))
          {
              hi=mid2;
          }
          else
          {
              lo=mid1;
          }
        }
        res=dist(lo);
        pf("Case %d: %.10lf\n",++co,res+eps);
    }
    return 0;
}
