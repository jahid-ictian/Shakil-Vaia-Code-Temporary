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

const int MAXN = 105000;

struct node {
	int next[26];
	int len; // ei node er palindrome length
	int sufflink; // ei node er suffix link
	int num;  //ei node e kotota palindrome ache
};

int len;
char s[MAXN];
node tree[MAXN];
int num; 			// node 1 - root with len -1, node 2 - root with len 0
int suff; 			// max suffix palindrome
long long ans;

bool addLetter(int pos) {
	int cur = suff, curlen = 0;
	int let = s[pos] - 'a';
	while (true) {
		curlen = tree[cur].len;
		if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
			break;
		cur = tree[cur].sufflink;
	}

	if (tree[cur].next[let]) {
		suff = tree[cur].next[let];
		return false;
	}

	num++; // adding new node
	suff = num;
	tree[num].len = tree[cur].len + 2;
	tree[cur].next[let] = num;
	if (tree[num].len == 1) {
		tree[num].sufflink = 2;
		tree[num].num = 1;
		return true;
	}

	while (true) {
		cur = tree[cur].sufflink;
		curlen = tree[cur].len;
		if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
			tree[num].sufflink = tree[cur].next[let];
			break;
		}
	}

	tree[num].num = 1 + tree[tree[num].sufflink].num;

	return true;
}

void initTree() {
	num = 2; suff = 2;
	tree[1].len = -1; tree[1].sufflink = 1;
	tree[2].len = 0; tree[2].sufflink = 1;
}

int main() {

	gets(s);
	len = strlen(s);
	initTree();
	for (int i = 0; i < len; i++) {
		addLetter(i);
		ans += tree[suff].num;
	}

	cout << ans << endl;

	return 0;
}
