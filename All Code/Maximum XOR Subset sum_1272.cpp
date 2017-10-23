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
int t,n,co;
u64 a[100005],res;

bool cmp(u64 a, u64 b)
{
    return a>b;
}

bool valid(u64 a, int pos)
{
    return (a & (1LL<<pos));
}

int main()
{
   /// https://myprogrammingdesk.wordpress.com/2015/01/31/gaussian-elimination-technique/
   // fout("1272.txt");
   // S(t);
   // while(t--)
    {
        S(n);
        repc(i,1,n) sc("%llu",&a[i]);
        sort(a+1,a+n+1,cmp);

        int pos=63;

        for(int i=63;i>=0;i--)
        if(valid(a[1],i))
            {
              pos=i; break;
            }

        if(n<(pos+1)) {for(int i=n+1;i<=(pos+1);i++) a[i]=0; n=pos+1;}
       //repc(i,1,n) pf("%llu\n",a[i]);
       //pfn;

        res=0;
        for(int i=pos,r=1;i>=0;i--)
        {
            int id=-1;
           // pf("-- %d %llu\n",r,a[r]);
//            for(int j=63;j>=0;j--)
//             if(valid(a[r],j)) pf("1");
//
//            else pf("0");
            if(valid(a[r],i))//a[r] er i tomo position e 1 ache ki?
            {
              id=r;
            }
            if(id==-1)
            {
                for(int j=r+1;j<=n;j++)
                {
                    if(valid(a[j],i))
                    {
                        id=j; break;
                    }
                }
            }
            if(id==-1) continue; //ei element ke baad deya jabena
            //ei khetre kdi ei index er uporer 1 thake tahole thakteo pare. bt niche nei. amra niche ache kina dekhe kaj kori
            u64 tmp;
            {
              swap(a[id],a[r]);
              tmp=a[r];
            }
//            cout<<tmp,pfn;

            for(int j=1;j<=n;j++)
            {
                if(j!=r)
                if(valid(a[j],i)==true) a[j]=a[j]^tmp;
            }

//            for(int k=1;k<=n;k++)
//              {
//                   for(int j=63;j>=0;j--)
//                    if(valid(a[k],j)) pf("1");
//                    else pf("0");
//                    pfn;
//              }

//            pf("%lld\n",a[r]);
//           for(int j=1;j<=n;j++) pf("%llu ",a[j]);
//           pfn;
             r++; // goto next element
        }
        u64 res=0;
      for(int i=1;i<=n;i++) if(res^a[i]>=res) res^=a[i];
      pf("%llu\n",res);
    }

    return 0;
}
