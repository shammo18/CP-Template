/// Problem : Frequency of substring of a query in a string using suffix automata

//Bismillahir Rahmanir Rahim

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define xx first
#define yy second
#define sci(n) scanf("%d",&n)
#define scii(n,m) scanf("%d%d",&n,&m)
#define sciii(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scl(n) scanf("%lld",&n)
#define scll(n,m) scanf("%lld%lld",&n,&m)
#define sclll(n,m,w) scanf("%lld%lld%lld",&n,&m,&w)
#define pf(a)   printf("%d\n",a)
#define CASE(a) printf("Case %d: ",a)
#define endl '\n'
#define READ  freopen("input.txt","r",stdin)
#define WRITE freopen("output.txt","w",stdout);
#define PI acos(-1)
#define mem(a,b) memset(a,b,sizeof(a))
#define SQR(a) (a)*(a)
#define all(v) v.begin(),v.end()
#define pb push_back
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define inf INT_MAX
#define eps 1e-9

using namespace __gnu_pbds;
using namespace std;

#define Gene template< class
#define Rics printer& operator,
Gene c> struct rge{c b, e;};
Gene c> rge<c> range(c i, c j){ return {i, j};}
struct printer{
    ~printer(){cerr<<endl;}
    Gene c >Rics(c x){ cerr<<boolalpha<<x; return *this;}
    Rics(string x){cerr<<x;return *this;}
    Gene c, class d >Rics(pair<c, d> x){ return *this,"(",x.first,", ",x.second,")";}
    Gene ... d, Gene ...> class c >Rics(c<d...> x){ return *this, range(begin(x), end(x));}
    Gene c >Rics(rge<c> x){
        *this,"["; for(auto it = x.b; it != x.e; ++it)
            *this,(it==x.b?"":", "),*it; return *this,"]";}
};
#define debug() cerr<<"LINE "<<__LINE__<<" >> ", printer()
#define dbg(x) "[",#x,": ",(x),"] "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r) (rng);
}

//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};

//ll ncr(ll n,ll r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}

// bit manipulations

//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask | (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}
//int bitno(int mask) {return (int)__builtin_popcount(mask);}

template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template <typename T> T Dis(T x1,T y1,T x2, T y2){return sqrt( SQR(x1-x2) + SQR(y1-y2) );}
template <typename T> T Angle(T x1,T y1,T x2, T y2){ return atan( double(y1-y2) / double(x1-x2));}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T> T euclide(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> void ia (T a[],int n){for (int i=0; i<n; i++) cin >> a[i];}
template <typename T> void pa (T a[],int n){for (int i=0; i<n-1; i++) cout << a[i] << " ";cout << a[n-1] << endl;}
template <typename T> ll isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);}

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

///********************************MY CODE STARTS HERE********************************///



struct state
{
    int len,link;
    //map<char,int>next;
    int next[27];
};

///Note that size of st array is 2*MAXLEN
const int MAXLEN = 400005;
state st[MAXLEN*2];
int sz,last;

ll dp[2 * MAXLEN];
bool vis[2 * MAXLEN];

vector<int> g[2 * MAXLEN];         // graph of link tree


void sa_init(int l)
{
    sz=last=0;
    st[0].len=0;
    st[0].link=-1;
    ++sz;
    l=2*l; ///there can be at most 2*l state node in the sa machine.
    for(int i=0;i<l;i++) for(int temp = 0;temp < 26;temp++)
        st[i].next[temp] = -1;

}

void sa_extend(char c)
{
    int cur=sz++;
    dp[cur] = 1;                          // only all prefix will contribute
    st[cur].len=st[last].len+1;
    int p;
    for(p=last; p!=-1 && st[p].next[c - 'a'] == -1; p=st[p].link)
        st[p].next[c - 'a']=cur;
    if(p==-1)
        st[cur].link=0;
    else
    {
        int q=st[p].next[c - 'a'];
        if(st[p].len+1==st[q].len)
            st[cur].link=q;
        else
        {
            int clone=sz++;
            st[clone].len=st[p].len+1;
            //st[clone].next=st[q].next;
            for(int temp = 0;temp < 26;temp++) st[clone].next[temp] = st[q].next[temp];
            st[clone].link=st[q].link;
            for( ; p!=-1 && st[p].next[c - 'a']==q; p=st[p].link)
                st[p].next[c - 'a']=clone;
            st[q].link=st[cur].link=clone;
        }
    }
    last=cur;
}




void dfs(int idx)
{

    vis[idx] = true;


    for(int v : g[idx])
    {


        if(vis[v] == false ){
            dfs(v);
            //dp[idx] += dp[st[idx].next[ch]];
        }
    }

    for(int v : g[idx])
    {


        dp[idx] += dp[v];

    }
}

int query(string p)              /// query to go a path to find a substring
{
    int cur = 0;

    for(int i = 0;i < p.size();i++){
        if(st[cur].next[p[i] - 'a'] != -1)
            cur = st[cur].next[p[i] - 'a'];
        else return 0;
    }
    return dp[cur];

}


int main(){
       IOS;

        string s;
        cin >> s;

        sa_init((int)s.size());
        for(int i = 0;i < s.size();i++) sa_extend(s[i]);
        for(int i = 1;i < sz;i++){
            g[st[i].link].pb(i);    /// reversing the link is link tree
           // debug()  ,dbg(st[i].link) , dbg(i);
        }
       // print_sa(0 , "");
       // for(int i = 0;i < 8;i++) cout << st[i].link <<" ";
       dfs(0);
        int q;
        cin >> q;
        while(q--){
            string p;
            cin >> p;

            cout << query(p) << endl;

        }





return 0;
}




