#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
#define int long long 
const int inf = 1e18 + 7;
int  a[N];
  #define lc (n << 1)
  #define rc ((n << 1) + 1)
  long long t[4 * N], lazy[4 * N];

  inline void push(int n, int b, int e) { // change this
    if (lazy[n] == 0) return;
    t[n] = t[n] + lazy[n];
    if (b != e) {
      lazy[lc] = (lazy[lc] + lazy[n]);
      lazy[rc] = (lazy[rc] + lazy[n]);
    }
    lazy[n] = 0;
  }
  inline long long combine(long long a,long long b) { // change this
    return min(a , b);
  }
  inline void pull(int n) { // change this
    t[n] = min(t[lc], t[rc]);
  }
  void build(int n, int b, int e) {
    lazy[n] = 0; // change this
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
      lazy[n] = v; //set lazy
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
    if (i > e || b > j) return inf; //return null
    if (i <= b and e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
int32_t main() {
  int n; cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  int q; cin >> q;
  build(1, 1, n);
 //cout  << t[n] << endl;
 cin.ignore();
  while(q--) {
     string line;
     getline(cin, line);
     stringstream ss(line);
     int l, r, v;
     ss >> l >> r;
     l++, r++;
    if(ss >> v) {
        if(l <= r)
            upd(1, 1, n, l, r, v);

        else {
            upd(1,1, n, l, n, v);
            upd(1,1, n, 1, r, v);
        }
    }
    else {
        if(l <= r)
            cout << query(1, 1, n, l, r) << endl;

        else {
            cout << min(query(1,1, n, l, n), query(1, 1, n, 1, r)) << endl;
        }
    }
  }
}
