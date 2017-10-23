/*
Md. Jahidul Hasan, ICT,
Comilla University, Comilla.
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<utility>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<iterator>

using namespace std;

#define sc scanf
#define pf printf
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
#define rep(i,n) for(__typeof(n) i=1; i<=(n); i++)
#define repc(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)
#define S(z) scanf("%d",&z)
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
#define pi acos(-1.0)
#define M   1000007
#define MAX 1000007
#define eps 1e-9


typedef unsigned int UI;
typedef unsigned long long int u64;
typedef long long int i64;

// Remarks abt prob:
//***** Code Starts here *****//

/*
//.in-> .txt
char ch;
    while(scanf("%c",&ch)==1)
        printf("%c",ch);

pf("%s",string.c_str())

struct data
{
    int a,b,c;
    bool operator < (const data &p)
    const
    {
        return a<p.a; // ascending
    }
};
data ar[];
*/
int tree[100005],n;
void make_tree(int n)
{
    for(int i=1;i<=n;i++)
    {
        int p=i,idx=i;
        while(idx<=n)
        {
            tree[idx]+=i;
            idx+=(idx & -idx);
        }
    }
}

int query(int n)
{
    int res=0,idx=n;
    while(idx>0)
    {
        res+=tree[idx];
        idx=idx-(idx & -idx);
    }
    return res;
}
void update_tree(int upd, int idx)
{
    while(idx<=n)
    {
        tree[idx]+=upd;
        idx+=(idx & -idx);
    }
}


int minimum_idx(int num)
{
    int low=1,high=n,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        int q=query(mid);
        if(q==num) return mid;
        if(q<num) low=mid+1;
        else high=mid-1;
    }
    if(low>n) return 0;
    else return low;

}
int main()
{
    //fin("C5_8.in");
    //fout("C5_8.txt");
    int t,low,high,index,update,num;
    printf("Enter the max number:");
    scanf("%d",&n);
    make_tree(n);  //making BIT
    printf("How many query:");
    scanf("%d",&t);
    while(t--)
    {
        printf("Enter  the ranges: ");
        scanf("%d %d",&low,&high);
        printf("%d\n",query(high)-query(low-1));
    }
    /// updating part;
    printf("Enter the number to update and index:");
    scanf("%d %d",&update,&index);
    update_tree(update,index);
    printf("How many query:");
    scanf("%d",&t);
    while(t--)
    {
        printf("Enter  the ranges: ");
        scanf("%d %d",&low,&high);
        printf("%d\n",query(high)-query(low-1));
    }
    /// Search part:
    scanf("%d",&t);
    while(t--)
    {
    printf("Enter the summation to get its minimum index:");
    scanf("%d",&num);
    int idx=0;
    if(num>0) idx=minimum_idx(num);
    if(idx==0) printf("Not found.\n");
    else printf("At %d\n",idx);
    }
    return 0;
}



