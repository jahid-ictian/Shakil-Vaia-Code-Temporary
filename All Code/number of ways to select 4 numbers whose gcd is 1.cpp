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

int dx4[]={0,-1,0,1};
int dy4[]={-1,0,1,0}; //4 Direction
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
int t,n,a[10005],co,mx,cnt[5005],dn[10005],c;
bool tok[10005];
i64 res,tmp[10005],ncr[10005],tt[105];
vector<int>divi[10005];

int main()
{
    /*
    prothome sobgular theke 4 ta kotovabe neya jay.
    then segular jotogula combination er gcd >1 tader ke subtract korte hbe, kheyal rakhte hbe jate
    duibar baad na jay.
    tai ami aage proti number er jnne way gula ber kochi
    then now 2 diye jehetu 6 ke vaag jay tai 6 er jotogula way ache segula 2 er o thakte baddho.
    tai ami segula 2 theke baad dibo. sobgular jnne.
    */
    for(i64 i=4;i<=10000;i++)
    {
        ncr[i]=((i-1)*(i-2)*(i)*(i-3))/24LL;//nC4=((n)*(n-1)*(n-2)*(n-3))/4!;
       // pf("%lld %lld\n",i,ncr[i]);
    }

    for(int i=2;i<=5000;i++)
        for(int j=i+i;j<=5000;j+=i)
        divi[j].pb(i); // j ke kongula dhara vag jay

    S(t);
    while(t--)
    {
        S(n);
        mx=0;
        repc(i,1,n)
        {
           S(a[i]);
           mx=max(mx,a[i]);
        }
        mem(tok,false);
        mem(tmp,0);
        mem(cnt,0);
        for(int i=100;i>=1;i--) // 100*100=10000(maximum number)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j]%i==0)
                {
                    cnt[i]++;
                    if(a[j]/i>100) cnt[a[j]/i]++;
                }
            }
        }

        res=ncr[n];
        for(int i=10000;i>=2;i--) {if(cnt[i]>=4) tmp[i]=ncr[cnt[i]];}

        for(int i=10000;i>=2;i--)
        {
            if(tmp[i]>0)
            {
                for(int j=0;j<divi[i].size();j++)
                {
                    tmp[divi[i][j]]-=tmp[i];
                }
            }
            res-=tmp[i];
        }
        pf("Case %d: %lld\n",++co,res);
    }
    repc(i,1,10000) divi[i].clear();
    return 0;
}
