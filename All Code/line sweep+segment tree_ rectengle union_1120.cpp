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
struct T
{
    int x,y1,y2,active;
    bool operator<(const T& p)
    const {return x<p.x;}
}edges[60005];
int t,co,yt,ryt,tot,n,a,b,c,d,rycrd[4*30005],ycrd[4*30005];
i64 tree[16*30005],oc[16*30005];
i64 res=0;

void update(int node, int b, int e, int y1, int y2, int actv)
{
    if(ycrd[b]>y2 || ycrd[e]<y1) return ;
    int mid=(b+e)/2;
    int left=2*node;
    int rigt=left+1;
    if(ycrd[b]>=y1 && ycrd[e]<=y2)
    {
        oc[node]+=(actv==1)?1:-1;
        if(oc[node]>0) tree[node]=ycrd[e]-ycrd[b];
        //overlap hole ami jdi ekta ke rmv kore dei then no problem
        //cz oc not zero jotokhon sobgula not remvd.
        else tree[node]=tree[left]+tree[rigt];
        return;
    }
    if(b+1>=e) return;//3==3 er kono drkr nei krar
    update(left,b,mid,y1,y2,actv);
    update(rigt,mid,e,y1,y2,actv);
    if(oc[node]>0) tree[node]=ycrd[e]-ycrd[b];//recursion er vitor kothao hteo pare
    else tree[node]=tree[left]+tree[rigt];
    return;
}
int main()
{
    /*
    ekahne ami line sweep + segment tree use korechi.
    ami top-down line seep korechi.
    ekhane array er value er somotullo niyechi y coordinates ke.
    then prothome same x axis er jnne update. then porer axis
    e value add res er sathe. jdi eta kono rect er shes pranto hoy tahole
    -1 diye ei edge ke tree er sum theke minus.
    */
    S(t);
    while(t--)
    {
        S(n);
        tot=0;
        ryt=0;
        repc(i,1,n)
        {
            S2(a,b); S2(c,d);
            edges[++tot].x=a;edges[tot].y1=b;edges[tot].y2=d; edges[tot].active=1;
            edges[++tot].x=c;edges[tot].y1=b;edges[tot].y2=d; edges[tot].active=-1;
            rycrd[++ryt]=b;
            rycrd[++ryt]=d;
        }
        yt=1;
        sort(rycrd+1,rycrd+ryt+1);
        ycrd[1]=rycrd[1];
        for(int i=2;i<=ryt;i++)
        {
          if(ycrd[yt]!=rycrd[i]) ycrd[++yt]=rycrd[i];
        }
        sort(edges+1,edges+tot+1);
        res=0;
        mem(tree,0);
        mem(oc,0);
        update(1,1,yt,edges[0].y1,edges[0].y2,edges[0].active);
        for(int i=1;i<=tot;i++)
        {
            res+=((edges[i].x-edges[i-1].x)*tree[1]);
            update(1,1,yt,edges[i].y1,edges[i].y2,edges[i].active);
        }
        pf("Case %d: %lld\n",++co,res);
    }
    return 0;
}
