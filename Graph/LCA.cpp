#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
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
#define dbg(i) printf("yo %d\n", i)
#define endl '\n'
#define pi acos(-1)
#define mem(a,b) memset(a,b,sizeof(a))
#define SQR(a) (a)*(a)
#define all(v) v.begin(),v.end()
#define pb push_back
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define inf INT_MAX
#define eps 1e-9

using namespace std;

//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};

//ll ncr(ll n,ll r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}

// bit manipulations

//bool checkbit(int mask,int bit){return mask & (1<<bit);}
//int setbit(int mask,int bit){ return mask  (1<<bit) ; }
//int clearbit(int mask,int bit){return mask & ~(1<<bit);}
//int togglebit(int mask,int bit){return mask ^ (1<<bit);}

template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
template <typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template <typename T> T Bigmod(T b,T p,T m){ if(p==0) return 1; else if (!(p&1)) return SQR(Bigmod(b,p/2,m)) % m;else return ((b % m) * Bigmod(b,p-1,m)) % m;}
template <typename T> T Dis(T x1,T y1,T x2, T y2){return sqrt( SQR(x1-x2) + SQR(y1-y2) );}
template <typename T> T Angle(T x1,T y1,T x2, T y2){ return atan( double(y1-y2) / double(x1-x2));}
template <typename T> T DIFF(T a,T b) { T d = a-b;if(d<0)return -d;else return d;}
template <typename T> T ABS(T a) {if(a<0)return -a;else return a;}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T> T euclide(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> void ia (T a[],int n){for (int i=0; i<n; i++) cin >> a[i];}
template <typename T> void pa (T a[],int n){for (int i=0; i<n-1; i++) cout << a[i] << " ";cout << a[n-1] << endl;}
template <typename T> ll isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);}

#define mxn 100005

const int  LG = 20;
int lvl[mxn] , P[mxn][LG];
vector<int> g[mxn];


void dfs(int u, int par){
    lvl[u] = 1 + lvl[par];
    P[u][0] = par;
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}


// Finding LCA

int lca(int u, int v){
    int i, lg;
    if (lvl[u] < lvl[v]) swap(u, v);

    for(lg = 0; (1<<lg) <= lvl[u]; lg++);
    lg--;

    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= lvl[v])
            u = P[u][i];
    }

    if (u == v)
    	return u;

    for(i=lg; i>=0; i--){
        if (P[u][i] != -1 && P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    }

    return P[u][0];
}



//returns the distance between
//two nodes "u" and "v".
int dis(int u, int v){
    if (lvl[u] < lvl[v]) swap(u, v);
    int w = lca(u, v);
    //cout  << w <<" hi "<<endl;
    return lvl[u] + lvl[v] - 2*lvl[w];
}


// get the kth parent or the parent which is dis distance above from u

int get(int u, int dis){
    dis = lvl[u] - dis;
    int i, lg = 0;
    for(; (1<<lg) <= lvl[u]; lg++); lg--;
    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= dis)
            u = P[u][i];
    }
    return u;
}



int main(){


    int n ;
    sci(n);

    for(int i = 0;i < n - 1;i++){
        int u , v;
        scii(u , v);
        g[u].pb(v);
        g[v].pb(u);
    }


    for(int i = 0;i < LG;i++){
        for(int j = 0;j < n + 1;j++) P[j][i] = -1;
    }

    lvl[0] = -1;
    dfs(1,0);

    for(int  i = 1; i < LG; i++){           // Sparse Table part
        for(int j = 1;j < n + 1;j++)
            if (P[j][i-1] != -1)
                P[j][i] = P[P[j][i-1]][i-1];
  	}

    int q;
    sci(q);

    //cout << lvl[1] <<" " <<lvl[2] <<lvl[3] <<endl;

    while(q--){

        int x, y , a, b, k;
        scii(x,y);
        sciii(a,b,k);
        //cout << ( dis(y,b) + 1) << endl;
        if((dis(a,b) % 2 == k % 2 && dis(a,b) <= k) || ((dis(a,x) + dis(y,b) + 1) % 2 == k % 2 && (dis(a,x) + dis(y,b) + 1) <= k ) || ((dis(a,y) + dis(x,b) + 1) % 2 == k % 2 && (dis(a,y) + dis(x,b) + 1) <= k))
           printf("YES\n");

        else printf("NO\n");






    }







return 0;}

