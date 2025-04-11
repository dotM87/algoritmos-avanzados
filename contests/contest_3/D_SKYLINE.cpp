#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

const int MAX_COORD = 100000;

struct Node {
    int l, r;
    int mn, mx;
    int lazy;
};

vector<Node> segtree;

void build(int idx, int l, int r) {
    segtree[idx].l = l;
    segtree[idx].r = r;
    segtree[idx].lazy = -1;
    if(l == r) {
        segtree[idx].mn = segtree[idx].mx = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    segtree[idx].mn = 0;
    segtree[idx].mx = 0;
}

void pushDown(int idx) {
    if(segtree[idx].lazy != -1) {
        int lazyVal = segtree[idx].lazy;
        int left = 2 * idx, right = 2 * idx + 1;
        segtree[left].lazy = lazyVal;
        segtree[right].lazy = lazyVal;
        segtree[left].mn = segtree[left].mx = lazyVal;
        segtree[right].mn = segtree[right].mx = lazyVal;
        segtree[idx].lazy = -1;
    }
}

void update(int idx, int ql, int qr, int val) {
    int l = segtree[idx].l, r = segtree[idx].r;
    if(qr < l || r < ql) return;
    if(ql <= l && r <= qr) {
        if(segtree[idx].mn >= val) return;
        if(segtree[idx].mx < val) {
            segtree[idx].mn = segtree[idx].mx = val;
            segtree[idx].lazy = val;
            return;
        }
    }
    pushDown(idx);
    update(2 * idx, ql, qr, val);
    update(2 * idx + 1, ql, qr, val);
    segtree[idx].mn = min(segtree[2 * idx].mn, segtree[2 * idx + 1].mn);
    segtree[idx].mx = max(segtree[2 * idx].mx, segtree[2 * idx + 1].mx);
}

int query(int idx, int ql, int qr, int threshold) {
    int l = segtree[idx].l, r = segtree[idx].r;
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) {
        if(segtree[idx].mx <= threshold)
            return r - l + 1;
        if(segtree[idx].mn > threshold)
            return 0;
    }
    pushDown(idx);
    int leftRes = query(2 * idx, ql, qr, threshold);
    int rightRes = query(2 * idx + 1, ql, qr, threshold);
    return leftRes + rightRes;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    while(c--){
        int n;
        cin >> n;
        segtree.assign(4 * (MAX_COORD + 1), Node());
        build(1, 1, MAX_COORD);

        long long totalOverlap = 0;
        vector<tuple<int, int, int>> buildings(n);
        for (int i = 0; i < n; i++){
            int li, ri, hi;
            cin >> li >> ri >> hi;
            buildings[i] = make_tuple(li, ri, hi);
        }

        for(auto &b : buildings){
            int li, ri, hi;
            tie(li, ri, hi) = b;
            int len = query(1, li, ri - 1, hi);
            totalOverlap += len;
            update(1, li, ri - 1, hi);
        }

        cout << totalOverlap << "\n";
    }

    return 0;
}