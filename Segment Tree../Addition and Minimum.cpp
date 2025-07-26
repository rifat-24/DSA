#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 9;
#define int long long
const int inf = 1e18 + 7;
int a[N];
#define lc (n << 1)
#define rc ((n << 1) + 1)
long long t[4 * N], lazy[4 * N];
// ST()
// {
//     memset(t, 0, sizeof t);
//     memset(lazy, 0, sizeof lazy);
// }
inline void push(int n, int b, int e)
{ // change this
    if (lazy[n] == 0)
        return;
    t[n] = t[n] + lazy[n];
    if (b != e)
    {
        lazy[lc] = lazy[lc] + lazy[n];
        lazy[rc] = lazy[rc] + lazy[n];
    }
    lazy[n] = 0;
}
inline long long combine(long long a, long long b)
{ // change this
    return min(a , b);
}
inline void pull(int n)
{ // change this
    t[n] = min(t[lc] , t[rc]);
}
void build(int n, int b, int e)
{
    lazy[n] = 0; // change this
    if (b == e)
    {
        t[n] = a[b];
        return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
}
void upd(int n, int b, int e, int i, int j, long long v)
{
    push(n, b, e);
    if (j < b || e < i)
        return;
    if (i <= b && e <= j)
    {
        lazy[n] = v; // set lazy
        push(n, b, e);
        return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
}
long long query(int n, int b, int e, int i, int j)
{
    push(n, b, e);
    if (i > e || b > j)
        return inf; // return null
    if (i <= b && e <= j)
        return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
}

int32_t main()
{
    int n, q;
    cin >> n >> q;
    //memset(lazy, -1, sizeof lazy);
    build(1, 1, n); // building the segment tree
    while (q--)
    {
        int i;
        cin >> i;
        if (i == 1)
        {
            int l, r, val;
            cin >> l >> r >> val;
            l++;
            upd(1, 1, n, l, r, val); // adding 10 to the segment [2, 3]
        }
        else
        {
            int l , r; cin >> l >> r;
            l++;
           cout << query(1, 1, n, l, r) << '\n'; // range sum query on the segment [1, 5]
        }
    }
}
