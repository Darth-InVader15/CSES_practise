#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ull unsigned long long
#define ll long long 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int mod = 1e9 + 7;
const int INF = 1e9;

vector<int> tree;

void build(int ind, int l, int r, vector<int> &arr) {
    if (l == r) {
        tree[ind] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * ind + 1, l, mid, arr);
    build(2 * ind + 2, mid + 1, r, arr);
    tree[ind] = min(tree[2 * ind + 1], tree[2 * ind + 2]); // minima
}

void update(int ind, int l, int r, int pos, int val) {
    if (l == r) {
        if(r == pos) tree[ind] = val; // values updated
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(2 * ind + 1, l, mid, pos, val);
    } else {
        update(2 * ind + 2, mid + 1, r, pos, val);
    }
    tree[ind] = min(tree[2 * ind + 1], tree[2 * ind + 2]);
}

int query(int ind, int l, int r, int lq, int rq) {
    if (lq > r || rq < l) return INF; // no overlap
    if (lq <= l && r <= rq) return tree[ind]; // complete overlap 
    int mid = (l + r) / 2;
    int lt = query(2 * ind + 1, l, mid, lq, rq);
    int rt = query(2 * ind + 2, mid + 1, r, lq, rq);
    return min(lt, rt);
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> arr(n);
    forn(i, n) cin >> arr[i];

    tree.resize(4 * n);
    build(0, 0, n - 1, arr);

    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            update(0, 0, n - 1, x - 1, y);
        } else {
            cout << query(0, 0, n - 1, x - 1, y - 1) << endl;
        }
    }
}

int32_t main() {
    fast_cin();
    solve();
    return 0;
}
