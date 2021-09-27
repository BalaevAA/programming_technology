#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
int a[N], tree[4*N];

void build (int a[], int v, int left, int right) {
	if (left == right)
		tree[v] = a[left];
	else {
		int mid = (left + right) / 2;
		build (a, v*2, left, mid);
		build (a, v*2+1, mid + 1, right);
		tree[v] = tree[v*2] + tree[v*2+1];
	}
}

int sum (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return tree[v];
	int tm = (tl + tr) / 2;
	return sum(v*2, tl, tm, l, min(r,tm)) + sum(v*2+1, tm+1, tr, max(l,tm+1), r);
}

void update (int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr)
		tree[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (v*2, tl, tm, pos, new_val);
		else
			update (v*2+1, tm+1, tr, pos, new_val);
		tree[v] = tree[v*2] + tree[v*2+1];
	}
}


int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(a,1,0,n);

    cout << endl;
    cout << sum(1, 0, n, 1, 4) << endl;

    //for(int i = 1; i < 24; ++i) {
    //    cout << tree[i] << endl;
    //}
    return 0;
}

