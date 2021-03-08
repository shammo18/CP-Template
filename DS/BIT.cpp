/******************************************************************/
/*
    *0-based index
    *Fenwick(int n,T a[]) builds fenwick tree in O(n) from a[]
    *query(int r) for range [0,r)
    *query(int l,int r) for range [l,r)
*/
template<class T> struct Fenwick {
    int n;
    T* d;
    Fenwick() : n(0), d(NULL) {}
    Fenwick(int n) : n(n) {
        d = new T[n]();
    }
    Fenwick(const Fenwick &y) : n(y.n) {
        d = new T[n];
        memcpy(d, y.d, sizeof (T) * n);
    }
    Fenwick(int n, T a[]) : n(n){
        d = new T[n]();
        for(int i=0; i<n; i++){
            d[i] += a[i];
            if( (i|(i+1)) < n)
                d[i | (i + 1)] += d[i];
        }
    }
    ~Fenwick() {
        delete[] d; d = NULL;
        n = 0;
    }
    inline void update(int i, const T &x) {
        for (; i<n; i|=i+1) d[i] += x;
    }
    inline T query(int r) {
        T s = T();
        for (; r; r&=r-1) s += d[r-1];
        return s;
    }
    T query(int l, int r) {
        return query(r) - query(l);
    }
};

/// into main function
/// # of distinct number in a range l.....r (offline solution with BIT)
    int q;
    cin >> q;

    for(int i = 0;i < q;i++){
        int l , r;
        cin >> l >> r;
        l--; r--;
        qr[r].pb({l , i});
    }

    int sz = arr.size();
    Fenwick<int> bit(sz + 1);
    vector<int> last_vis(ptr + 10 , -1);
    vector<int> ans(q + 5);

    for(int i = 0;i < sz;i++){
        if(last_vis[arr[i]] != -1) {
            bit.update(last_vis[arr[i]] , -1);
        }
        last_vis[arr[i]] = i;
        bit.update(i , 1);
        for(auto u : qr[i]) ans[u.yy] = bit.query(u.xx , i + 1);
    }

    for(int i = 0;i < q;i++) cout << ans[i] << endl;
