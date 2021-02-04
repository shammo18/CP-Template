/// Problem :
/*
A certain substring s [ l..r ] of the parent string s is defined as its "characteristic substring"
if and only if the substring appears only once in s .
Now give the mother string s of length n .
Find the length of the shortest characteristic substring of each prefix of the mother string s respectively .
• 1 ≤ n ≤ 10^6 ,  | Σ | = 26;
*/

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
    int len, mn_len , vis , node_no;
    state *next[26] , *link;
    state()
    {
        len = 0;
        mn_len = 1e9;
        link = NULL;
        node_no = 0;
        vis = 0;
        for(int i=0;i<26;i++) next[i]=NULL;
    }

   // bool operator < ( state *a)  {
   //     return mn_len > a->mn_len;
   // }
};

///Note that size of st array is 2*MAXLEN
const int MAXLEN = 1000005;
int sz = 0;

state *root , *last;


void sa_extend(char c)
{
    state *cur =  new state();
   /// st[cur].len=st[last].len+1;
     cur -> len = last -> len + 1;
     cur -> node_no = sz++;
     state *p = last;

    for(p=last; p != NULL && p->next[c - 'a'] == NULL; p= p->link){

        p->next[c - 'a'] = cur;


    }

    if(p==NULL)
        cur -> link = root;
    else
    {
        state *q=p -> next[c - 'a'];
        if(p->len+1==q->len)
            cur->link=q;
        else
        {

            state *clone = new state();

            clone->len=p->len+1;
            clone->node_no = sz++;

            for(int temp = 0;temp < 26;temp++) clone->next[temp] = q->next[temp];
            clone->link = q->link;
            for( ; p!=NULL && p->next[c - 'a'] == q; p = p->link)
                p->next[c - 'a'] = clone;
            q->link=cur->link=clone;
        }
    }
    last=cur;

}




void bfs()
{


    queue<state*> q;
    q.push(root);

    root-> mn_len = 0;

    while(!q.empty()){
        state *u = q.front();
        q.pop();
    for(char ch='a'; ch<='z'; ch++)
    {
        if( u->next[ch - 'a'] != NULL && ( u->next[ch - 'a']) ->mn_len == 1e9 ){
            ( u->next[ch - 'a']) ->mn_len =  u ->mn_len + 1;
            q.push(u->next[ch - 'a']);

            //dp[idx] += dp[st[idx].next[ch]];
        }
    }

    }

}


//priority_queue<state*> pq;



char buffer[MAXLEN];

int main(){
      // IOS;
        int n;
        sci(n);
        scanf("%s" , buffer);
        string s = buffer;

        //sa_init((int)s.size());
         sz = 1;
         root = new state();
         last = root;


        for(int i = 0;i < s.size();i++) sa_extend(s[i]);
        bfs();

       // cout <<sz << endl;
       // print_sa(0 , "");
       // for(int i = 0;i < 8;i++) cout << st[i].link <<" ";

    //  debug()  ,dbg(st[1].mn_len) , dbg(st[2].mn_len) , dbg(st[1].link);

    vector<int> ans;
    //int cur = 0;
    state *cur = root;

  auto cmp = [] (state* lhs, state* rhs) noexcept -> bool {
    return lhs->mn_len > rhs->mn_len;
  };

  root ->mn_len = 1e9;
  std::priority_queue<state *, std::vector<state *>, decltype(cmp)> pq(cmp);

    for(int i = 0;i < s.size();i++){
       cur =  cur->next[s[i] - 'a'];
       //debug() , dbg(cur->node_no);

       state *p = cur;
       for(;p != NULL && p->vis < 2;p = p->link){
          p->vis++;
          if(p->vis < 2){
            pq.push(p);
          }
       }

       while(!pq.empty() && pq.top()->vis >= 2 ){
            //invalid[pq.top().node_no] = true;
        pq.pop();
       }

       // debug() , dbg(pq.top()->node_no);


       ans.pb(pq.top()->mn_len);

    }

    for(auto u : ans) pf(u);







return 0;
}

