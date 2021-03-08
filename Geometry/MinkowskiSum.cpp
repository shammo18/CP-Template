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


#define mxn 200005

typedef ll T;
typedef complex<T> point;
#define X real()
#define Y imag()

#define dot(p, q) ((conj(p)*(q)).X)
#define cross(p, q) ((conj(p)*(q)).Y)
#define orient(p, q, r) cross((q)-(p), (r)-(p))

bool operator==(point p, point q){
    return (p.X == q.X) && (p.Y == q.Y);
}

bool lexcomp(const point &p, const point &q){	//lexicographical comparator
    return make_pair(p.X, p.Y) < make_pair(q.X, q.Y);
}


point origin, ray;

inline bool half(point p){
    return cross(ray, p) < 0 || (cross(ray, p) == 0 && dot(ray, p) > 0);
}

bool polarComp(point p, point q){
	p -= origin;
	q -= origin;
    return make_tuple(half(p), 0) < make_tuple(half(q), cross(p, q));
}

//A+B = C;  A, B have bottom-left at index 0
void MinkowskiSum(vector<point> &A, vector<point> &B, vector<point> &C){
    int n = A.size(), m = B.size();
    vector<point> P(n), Q(m);

    for(int i = 0; i+1<n; i++) P[i] = A[i+1] - A[i];
    P[n-1] = A[0] - A[n-1];

    for(int i = 0; i+1<m; i++) Q[i] = B[i+1] - B[i];
    Q[m-1] = B[0] - B[m-1];

    origin = point(0, 0), ray = point(0, -1);
    C.resize(n+m+1);
    merge(P.begin(), P.end(), Q.begin(), Q.end(), C.begin()+1, polarComp);

    C[0] = A[0] + B[0];

//    for(auto p: C) debug(p);
    for(int i = 1; i < C.size(); i++) C[i] += C[i-1];
    assert(C[0] == C.back());
    C.pop_back();
}

ll PointInPoly(point p, vector<point> &poly, int top){
    if(lexcomp(p, poly[0]) || lexcomp(poly[top], p)) return -1;

    auto o = orient(poly[0], poly[top], p);
    if(o == 0){
        return (p == poly[0] || p == poly[top] ||
           top == 1 || top+1 == poly.size())? 0 : 1;
    }
    else if(o < 0){
        auto it = lower_bound(poly.begin(), poly.begin()+top, p, lexcomp);
        return orient(it[-1], it[0], p);
    }
    else{
        auto it = upper_bound(poly.rbegin(), poly.rend()-top-1, p, lexcomp);
        return orient(p, it[0], (it == poly.rbegin())? poly[0] : it[-1]);
    }
}
//0 = on, +ve = inside, -ve = outside

vector<point> poly[3], sum;
int main(){
      IOS;

    for(int i = 0; i<3; i++){
        int n;
        cin>>n;
        poly[i].resize(n);

        for(int j = 0; j<n; j++)
        {
            ll x, y;
            cin>>x>>y;
            poly[i][j] = point(x, y);
        }

        auto it = min_element(poly[i].begin(), poly[i].end(), lexcomp);
        rotate(poly[i].begin(), it, poly[i].end());

    }

    MinkowskiSum(poly[0], poly[1], sum);

    MinkowskiSum(sum, poly[2], sum);

    int top = max_element(sum.begin(), sum.end(), lexcomp) - sum.begin();

    int m;
    cin>>m;
    for(int i = 0; i<m; i++)
    {
        ll x, y;
        cin>>x>>y;
        point p(x, y);
        p *= 3;
        if(PointInPoly(p, sum, top) < 0) cout<<"NO\n";
        else cout<<"YES\n";
    }

}
