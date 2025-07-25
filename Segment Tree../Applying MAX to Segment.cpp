#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
#define int long long 
int  a[N];
  #define lc (n << 1)
  #define rc ((n << 1) + 1)
  long long t[4 * N], lazy[4 * N];

  inline void push(int n, int b, int e) { // change this
    if (lazy[n] == 0) return;
    t[n] = max(t[n], lazy[n]);
    if (b != e) {
      lazy[lc] = max(lazy[lc] , lazy[n]);
      lazy[rc] = max(lazy[rc] , lazy[n]);
    }
    lazy[n] = 0;
  }
  inline long long combine(long long a,long long b) { // change this
    return max(a , b);
  }
  inline void pull(int n) { // change this
    t[n] = max(t[lc] ,t[rc]);
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
    if (i > e || b > j) return 0; //return null
    if (b == e and i == b) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
int32_t main() {
  int n, q; cin >> n >> q;
  
  while(q--) {
    int i; cin >> i;
    if(i == 1) {
        int l, r, val; cin >> l >> r >> val;
        l++;
        upd(1, 1, n, l, r, val);
    }
    else {
        int k; cin >> k;
        ++k;
        cout << query(1, 1, n, k, k) << endl;
    }
  }
}
