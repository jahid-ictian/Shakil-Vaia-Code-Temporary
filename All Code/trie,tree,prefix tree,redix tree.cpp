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
#define S(a) scanf("%d",&a)
#define SC(a) scanf("%s",&a)
#define clr(a) a.clear()
#define sz(a) (int)a.size()
#define pfn printf("\n")
#define mem(a,b) memset(a,b,sizeof a)
#define erase(a) a.erase(a.begin(),a.end())

#define MI map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define SI set<int>
#define SMI multiset<int>
#define VI vector<int>
#define VI2 vector < vector < int > >
#define QU queue<int>
#define PQU priority_queue<int>
#define STK stack<int>
#define pb push_back

#define inf 2000000000
#define MAX 1000007
#define eps 1e-9

typedef int I;
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
%i64d

*/
struct node
{
    bool isword;
    node *next[27];
    node()
    {
       isword=false;
       for(int i=0;i<26;i++)
       next[i]=NULL;
    }
}*root;


void insertnode(char *s, int len)
{
    node *curr=root;
    repc(i,0,len)
    {
       I id=s[i]-'a';
       if(curr->next[id]==NULL)
            curr->next[id]=new node();
       curr=curr->next[id];
    }
    curr->isword=1;
}

bool Q(char *s,int len)
{
    node *curr=root;
    repc(i,0,len)
    {
        int id=s[i]-'a';
        if(curr->next[id]==NULL) return false;
        curr=curr->next[id];
    }
    return curr->isword;
}

void del(node* curr)
{
    printf("deleting\n");
    repc(i,0,25)
    if(curr->next[i]) del(curr->next[i]);
    delete(curr);
}

void print_trie(node *curr)
{
    repc(i,0,25)
    {
        if(curr->next[i])
        {
            printf("%c",97+i);
            print_trie(curr->next[i]);
            pfn;
        }
    }
}
int main()
{
    root=new node();
    int n;
    pf("How many words:");
    S(n);
    char s[100];
    repc(i,1,n)
    {
        SC(s);
        insertnode(s,strlen(s)-1);
    }
    pf("How many query?:");
    S(n);
    while(n--)
    {

        SC(s);
        bool res=Q(s,strlen(s)-1);
        if(res) pf("Got it!!!\n");
        else pf("Sorry\n");
    }
    print_trie(root);
    del(root);
    //delete(root);
    return 0;
}



