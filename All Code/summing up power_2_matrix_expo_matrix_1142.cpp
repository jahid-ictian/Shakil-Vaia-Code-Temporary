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
int n,k,t,co;


struct in_mat
{
    int v[31][31];
};

struct matrix
{
    in_mat d[2][2];
};

in_mat A,I,Z;

in_mat mul(in_mat  &c, in_mat &e)
{
        in_mat ret;
        int sum=0,tmp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum=(int)0;
                for(int k=0;k<n;k++)
                {
                   tmp=(c.v[i][k]*e.v[k][j])%10;
                   sum=(sum+tmp)%10;
                }
                ret.v[i][j]=sum;
            }
        }
        return ret;
}
in_mat add(in_mat  &c, in_mat &e)
{
        in_mat ret;
        int sum=0,tmp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ret.v[i][j]=(c.v[i][j]+e.v[i][j])%10;
            }
        }
        return ret;
}

matrix multiply(matrix &a, matrix &b)
{
    matrix ret;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
          in_mat sum=Z,tmp;
          for(int k=0;k<2;k++)
          {
              tmp=mul(a.d[i][k],b.d[k][j]);
              sum=add(sum,tmp);
          }
          ret.d[i][j]=sum;
        }
    }
    return ret;
}

matrix pow(matrix mat, int k)
{
    if(k==1) return mat;
    matrix ret=pow(mat,k/2);
    ret=multiply(ret,ret);
    if(k%2==0) return ret;
    ret=multiply(mat,ret);
    return ret;
}

int main()
{
    S(t);
    matrix mat,res;
    while(t--)
    {
        S2(n,k);
        repc(i,0,n-1)
        repc(j,0,n-1)
        {
            S(A.v[i][j]);
            A.v[i][j]%=10;
        }
        pf("Case %d:\n",++co);
        if(k==1)
        {
            repc(i,0,n-1)
            {
            repc(j,0,n-1)
            pf("%d",A.v[i][j]);
            pfn;
            }
        }
        else
        {
            repc(i,0,n-1)
            repc(j,0,n-1)
            {
              I.v[i][j]=0;
              Z.v[i][j]=0;
              if(i==j)
                I.v[i][j]=1;
            }
            mat.d[0][0]=I;
            mat.d[0][1]=A;
            mat.d[1][0]=Z;
            mat.d[1][1]=A;
            res=pow(mat,k-1);
            in_mat tt,qq;
            tt=mul(res.d[0][0],A);
            qq=mul(res.d[0][1],A);
            tt=add(tt,qq);
            repc(i,0,n-1)
            {
            repc(j,0,n-1)
            pf("%d",tt.v[i][j]);
            pfn;
            }
        }
    }
    return 0;
}
