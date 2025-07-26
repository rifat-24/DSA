#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 9;

int a[N];
#define lc (n << 1)
#define rc ((n << 1) + 1)
long long t[4 * N], lazy[4 * N];

inline void push(int n, int b, int e) {
    if (lazy[n] == -1) return;
    t[n] =  lazy[n] * (e - b + 1);
    if (b != e) {
        lazy[lc] =  lazy[n];
        lazy[rc] =  lazy[n];
    }
    lazy[n] = -1;
}

inline long long combine(long long a, long long b) {
    return (a + b);
}

inline void pull(int n) {
    t[n] = (t[lc] + t[rc]);
}

void build(int n, int b, int e) {
    lazy[n] = -1;
    if (b == e) {
        t[n] = a[b];
        return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
}

void upd(int n, int b, int e, int i, int j, long long v) {
    push(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
        lazy[n] = v;
        push(n, b, e);
        return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
}

long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (i > e || b > j) return 0;
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //memset(lazy, -1, sizeof lazy);
    int n, q;
    cin >> n >> q;
    
    //for (int i = 1; i <= n; i++) a[i] = 1; // init to 1
    build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l++; // 0-based to 1-based
            upd(1, 1, n, l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            l++; // 0-based to 1-based
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
}
