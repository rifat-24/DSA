#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int N = 3e5 + 9;

 int ts = 0;
 int a[N];
  struct node{
    int first_ele, last_ele;
    int first_ele_cnt, last_ele_cnt;
    int mx_size_com;
  };
  node t[N * 4];
  void ST() {
    memset(t, 0, sizeof t);
  }
  node marge(node l, node r) {
    if(l.first_ele == -1) {
        return r;
    }
    if(r.first_ele == -1) {
        return l;
    }
    node ans;
    ans.first_ele = l.first_ele;
    ans.first_ele_cnt = l.first_ele_cnt;
    if(l.first_ele == r.first_ele) ans.first_ele_cnt += r.first_ele_cnt;

    ans.last_ele = r.last_ele;
    ans.last_ele_cnt = r.last_ele_cnt;
    if(r.last_ele == l.last_ele) ans.last_ele_cnt += l.last_ele_cnt;

    ans.mx_size_com = max(l.mx_size_com, r.mx_size_com);
    if(l.last_ele == r.first_ele) {
        ans.mx_size_com = max(ans.mx_size_com, l.last_ele_cnt + r.first_ele_cnt);
    }

    return ans;

  }
  void build(int n, int b, int e) {
    if (b == e) {
      t[n].first_ele = t[n].last_ele = a[b];
      t[n].first_ele_cnt = t[n].last_ele_cnt = 1;
      t[n].mx_size_com = 1;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = marge(t[l], t[r]); // change this
  }
//   void upd(int n, int b, int e, int i, int x) {
//     if (b > i || e < i) return;
//     if (b == e && b == i) {
//       t[n].mn = x; // update
//       t[n].cnt = 1;
//       return;
//     }
//     int mid = (b + e) >> 1, l = n << 1, r = l | 1;
//     upd(l, b, mid, i, x);
//     upd(r, mid + 1, e, i, x);
//     t[n] = marge(t[l], t[r]); // change this
//   }
  node query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return {-1, -1, -1, -1, -1}; // return appropriate value
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    return marge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j)); // change this
  }

 void solve() {
    ST();
  int n, c, q; cin >> n >> c >> q;
  for (int i = 1; i <= n; i++) {
   cin >> a[i];
  }
  build(1, 1, n); // building the segment tree
  cout <<  "Case " <<  ++ts << ": " << endl;
  while(q--) {
    int l, r; cin >> l >> r;
    node ans = query(1, 1, n, l , r);
    cout  << ans.mx_size_com << endl;
  }
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}
