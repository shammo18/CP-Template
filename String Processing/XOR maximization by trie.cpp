// Problem : https://codeforces.com/contest/282/problem/E

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
#define WRITE freopen("output.txt","w",stdout)
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

bool checkbit(ll mask,ll bit){return mask & (1LL<<bit);}
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


#define mxn 200005

struct node
{
    int cnt;
    node *next[2];
    node()
    {
        cnt=0;
        for(int i=0;i<2;i++) next[i]=NULL;
    }
};

node *root;
// node *root[mxn];

void update(string str)
{
    node *cur=root;
    for(int i=0;i < str.size();i++)
    {
        int id=str[i]-'0';             // lowercase English character
        if(cur->next[id]==NULL)
            cur->next[id]=new node();
        cur=cur->next[id];
    }
      //  cur->cnt+=n; // do something on End node of a string
}

ll query(string str)
{
    node *cur=root;
    ll ret = 0;
    for(ll i=0;i < str.size();i++)
    {
        int id=str[i]-'0';
        if(id == 0) {
           if(cur->next[1] != NULL){
             ret += (1LL<<(49LL - i));
             cur = cur->next[1];
           }else if(cur->next[0] != NULL){
             cur = cur->next[0];
           }else return ret;

        }else{
           if(cur->next[0] != NULL){
             ret += (1LL<<(49LL - i));
             cur = cur->next[0];
           }else if(cur->next[1] != NULL){
             cur = cur->next[1];
           }else return ret;
        }

    }
    return ret;
}


void del(node *cur)
{
    for(int i=0;i<2;i++)
    {
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete(cur);
}

ll soja[mxn] , ulta[mxn] , arr[mxn];

void solve(){
    root = new node();
    ll n;
    cin >> n;

    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        soja[i] = soja[i - 1]^arr[i];
    }

    for(int i = n;i >= 1;i--){
        ulta[i] = ulta[i + 1]^arr[i];
    }
    ll mx = 0;
    update("00000000000000000000000000000000000000000000000000");
    for(int i = n;i >= 0;i--){
        string s , t;
        for(int j = 0;j < 50;j++){
            if(checkbit(soja[i] , j)){
                s.pb('1');
            }else s.pb('0');

            if(checkbit(ulta[i] , j)){
                t.pb('1');
            }else t.pb('0');
        }

        reverse(all(s));
        reverse(all(t));

        ll ans = query(s);
        mx = max(ans , mx);
        update(t);

    }

    cout << mx << endl;
    del(root);




}


int main(){
       IOS;

	   int T = 1;
	   //cin >> T;

	   while(T--){
		   solve();
	   }



return 0;
}

