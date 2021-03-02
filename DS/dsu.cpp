class dsuClass {
    public:

    int n;
    vector<int> parent;
    vector<int> size;

    int sccCount;

    void init(int n) {
        this->n = n;
        parent.resize(n);
        size.resize(n);
        reset();
    }

    void reset() {
        sccCount = n;
        for(int i = 0;i <= n;i++) parent[i] = i;
        for(int i = 0;i <= n;i++) size[i] = 1;
    }

    int find_par(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find_par(parent[a]);
    }

    void join(int a, int b) {
        a = find_par(a);
        b = find_par(b);
        if (size[b] > size[a]) swap(a, b);
        if (a == b) return;

        size[a] += size[b];

        parent[b] = a;
        sccCount--;
    }

    bool isMaster(int v) {
        return parent[v] == v;
    }

    void updateAll() {
        for(int i = 0;i <= n;i++) find_par(i);
    }
};