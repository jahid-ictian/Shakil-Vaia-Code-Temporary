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
#define inf 2000000007
#define pi  acos(-1.0)
#define MAX 200007
#define MOD 1000000007LL
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

struct matrix
{
    unsigned int v[54][54];
};
int t,co,k,row,col;
i64 n;
unsigned int ncr[52][52],val[55],res;

void nCr()
{
    repc(i,0,51) ncr[i][0]=(unsigned int)1;
    repc(i,1,51)
    repc(j,1,i)
    ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j]);
}

matrix multiply(matrix  &a, matrix &b)
{
        matrix ret;
        unsigned sum=0,tmp;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                sum=(unsigned int)0;
                for(int k=0;k<col;k++)
                {
                   tmp=(a.v[i][k]*b.v[k][j]);
                   sum=(sum+tmp);
                }
                ret.v[i][j]=sum;
            }
        }
        return ret;
}

matrix pow(matrix &mat, i64 kk)
{
    if(kk==1LL) return mat;
    matrix ret=pow(mat,(i64)kk/2);
    ret=multiply(ret,ret);
    if(kk%2==0) return ret;
    return multiply(mat,ret);
}

int main()
{
    ///return type unsigned.. :1^k+2^k+3^k+....+n^k.. given . n and k
    //http://lbv-pc.blogspot.com/2012/05/summing-up-powers.html
    nCr();
    S(t);
    while(t--)
    {
        sc("%lld %d",&n,&k);
        if(n==1) res=1;
        else
        {
           matrix mat;
           row=k+3;
           col=k+3;
           for(int i=0;i<row;i++)
           {
               for(int j=0;j<row;j++) mat.v[i][j]=(unsigned)0;
           }
           mat.v[0][0]=(unsigned)1;
           for(int i=k;i>=0;i--)
           {
              mat.v[0][i+1]=ncr[k][i];
           }
           int u=1,g;
           for(int i=k;i>=0;i--)
           {
             g=k+1;
             for(int j=i;j>=0;j--)
             {
                mat.v[u][g]=ncr[i][j];
                g--;
             }
             ++u;
           }
           matrix ret=pow(mat,n-1);
           res=(unsigned int)0;
           for(int i=0;i<=k+1;i++)
           res=res+ret.v[0][i];
        }
        pf("Case %d: %u\n",++co,res);
    }
    return 0;
}
