//https://codeforces.com/contest/163/problem/E   Tested
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

#define Gene template< class
#define Rics printer& operator,
Gene c > struct rge {c b, e;};
Gene c > rge<c> range(c i, c j) { return {i, j};}
struct printer {
    ~printer() {cerr << endl;}
    Gene c > Rics(c x) { cerr << boolalpha << x; return *this;}
    Rics(string x) {cerr << x; return *this;}
    Gene c, class d > Rics(pair<c, d> x) { return *this, "(", x.first, ", ", x.second, ")";}
    Gene ... d, Gene ... > class c > Rics(c<d...> x) { return *this, range(begin(x), end(x));}
    Gene c > Rics(rge<c> x) {*this, "["; for (auto it = x.b; it != x.e; ++it)*this, (it == x.b ? "" : ", "), *it; return *this, "]";
    }
};
#define debug() cerr<<"LINE "<<__LINE__<<" >> ", printer()
#define dbg(x) "[",#x,": ",(x),"] "

const int N = 1000005;
int tim = 1;
vector<int> startTime(N);
ll BIT[2][N];
int ens[N];

struct AC {
  int N, P;
  const int A = 26;
  vector <vector <int>> next;
  vector <int> link, out_link;
  vector <vector <int>> out , tr;   // tr reverse suffix tree 
  AC(): N(0), P(0) {node();}
  int node() {
    next.emplace_back(A, 0);
    link.emplace_back(0);
    out_link.emplace_back(0);
    tr.emplace_back(0);
    out.emplace_back(0);
    return N++;
  }
  inline int get (char c) {
    return c - 'a';
  }
  int add_pattern (const string T) {
    int u = 0;
    for (auto c : T) {
      if (!next[u][get(c)]) next[u][get(c)] = node();
      u = next[u][get(c)];
    }
    out[u].push_back(P);
    
    P++;
    // return P++;
    return u;
  }
  void compute() {
    queue <int> q;
    for (q.push(0); !q.empty();) {
      int u = q.front(); q.pop();
      for (int c = 0; c < A; ++c) {
        int v = next[u][c];
        if (!v) next[u][c] = next[link[u]][c];
        else {
          link[v] = u ? next[link[u]][c] : 0;
          tr[link[v]].push_back(v);
          out_link[v] = out[link[v]].empty() ? out_link[link[v]] : link[v];
          q.push(v);
        }
      }
    }
  }
  int advance (int u, char c) {
    while (u && !next[u][get(c)]) u = link[u];
    u = next[u][get(c)];
    return u;
  }
}aho;


vector<int> sub(N);

void dfsTime(int u, int p)
{
    sub[u] = 1;
    startTime[u] = tim++;
    for(auto v : aho.tr[u])
    {
        if(v == p)
            continue;
        dfsTime(v, u);
        sub[u] += sub[v];
    }
}


void update(int cs, int indx, ll val)
{
    while(indx < N)
    {
        BIT[cs][indx] += val;
        indx += (indx & -indx);
    }
}

ll sum(int cs, int indx)
{
    ll ans = 0;
    while(indx != 0)
    {
        ans += BIT[cs][indx];
        indx -= (indx & -indx);
    }
    return ans;
}

void updateRange(int l, int r, ll val)
{
    update(0,l,val);
    update(0,r+1,-val);
    update(1,l,val*(l-1));
    update(1,r+1,-val*r);
}

ll sumRange(int indx)
{
    return sum(0,indx)*indx - sum(1,indx);
}
ll QueryRange(int l, int r)
{
    return sumRange(r)-sumRange(l-1);
}

void include_word(int v)
{
    if(ens[v] == 0)
    {
        updateRange(startTime[v], startTime[v] + sub[v] - 1, 1);
        ens[v] = 1;
    }
}

void exclude_word(int v)
{
    if(ens[v] == 1)
    {
        //debug() , dbg(startTime[v]) ,  dbg(endTime[v]);
        updateRange(startTime[v], startTime[v] + sub[v] - 1, -1);
        ens[v] = 0;
    }
}

int main()
{
    //IOS;

    int n, k;
    cin >> n >> k;

    vector<int> words;
    for(int i = 0; i < k; i++)
    {
        string w;
        cin >> w;
        int cur = aho.add_pattern(w);
        words.push_back(cur);
    }
    aho.compute();
    dfsTime(0, -1);

    for(int i = 0; i < k; i++)
    {
        include_word(words[i]);
    }

   // debug() ,dbg(words);
    //cout << tot << endl;
   // for(int i = 1;i <= 20;i++)
  //  debug() , dbg(tr[i]) , i;



    while(n--)
    {
        char ch;
        string s;
        int lol;
        cin >> ch;
        if(ch == '?')
        {
            cin >> s;
            int cur = 0;
            ll ans = 0;
            for(int i = 0; i < (int) s.size(); i++)
            {
                cur = aho.advance(cur, s[i]);
                ans += QueryRange(startTime[cur], startTime[cur]);
            }
            cout << ans << endl;
        }
        else if(ch == '+')
        {
            cin >> lol;
            include_word(words[lol - 1]);
        }
        else if(ch == '-')
        {
            cin >> lol;
           // debug() , dbg(words[lol - 1]);
            exclude_word(words[lol - 1]);
        }

    }


return 0;

}


