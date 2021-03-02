// Given a tree where each node have a number.
// Query(u) : How many distinct number in the subtree u.
// O(n * log^2(n))

set<int> S[N];
int buck[N];

void dfs(int u , int p){

    S[u].insert(w[u]);
    buck[u] = u;

    for(auto v : g[u]){
        if(v == p) continue;
        dfs(v , u);
        if(S[buck[u]].size() < S[buck[v]].size()) swap(buck[u] , buck[v]);
        // current small set = buck[v] , current large set = buck[u]
        for(auto it : S[buck[v]]) S[buck[u]].insert(it);
    }
}


