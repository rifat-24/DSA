#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 9;
const int B = 30;
int a[N];
struct node {
  int AND[B];
};

node t[4 * N];
int lazy[4 * N];

void push(int n, int b, int e) {
  if (lazy[n] == 0) {
    return;
  }
  for(int i = 0; i < B; ++i) {
    if((lazy[n] >> i) & 1) {
      t[n].AND[i] = 1;
    }
  }

  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  lazy[l] = lazy[l] | lazy[n];
  lazy[r] = lazy[r] | lazy[n];

  lazy[n] = 0;
  
}

node merge(node l, node r) {
  node ans;
  for (int k = 0; k < B; k++) {
    ans.AND[k] = l.AND[k] & r.AND[k];
  }
  return ans;
}

void build(int n, int b, int e) {
  lazy[n] = 0;
  if (b == e) {
    memset(t[n].AND, 0, sizeof t[n].AND);
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  build(l, b, mid);
  build(r, mid + 1, e);
  t[n] = merge(t[l], t[r]);
}

void upd(int n, int b, int e, int i, int j, int v) {
  push(n, b, e);
  if (e < i or j < b) return;
  if (b >= i and e <= j) {
    lazy[n] = v;
    push(n, b, e);
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  upd(l, b, mid, i, j, v);
  upd(r, mid + 1, e, i, j, v);
  t[n] = merge(t[l], t[r]);
}

node query(int n, int b, int e, int i, int j) {
  push(n, b, e);
  if (e < i or j < b) {
    node ans;
    fill(ans.AND, ans.AND + B, 1);
    return ans;
  }
  if (b >= i and e <= j) {
    return t[n];
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; ++i) a[i] = 0;
  build(1, 1, n);
  while (m--) {
    int ty; cin >> ty;
    if (ty == 1) {
      int l, r, v; cin >> l >> r >> v;
      l++;
      upd(1, 1, n, l, r, v);
    }
    else {
      int l, r; cin >> l >> r;
      l++;
      node ans = query(1, 1, n, l, r);
      int sum = 0;
      for(int i = 0; i < B; ++i) {
        if(ans.AND[i] == 1) {
            sum += (1 << i);
        }
      }
      cout << sum << endl;
 
    }
} 
}
