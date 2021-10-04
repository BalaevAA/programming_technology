#include<bits/stdc++.h>

using namespace std;

class segments_tree {
public:
	segments_tree() = default;
	segments_tree(int cap);
	void build(vector<int> a, int current, int start, int end);
	int sum(int current, int start, int end, int left, int right);
private:
	int size = 0;
	int* tree = nullptr;
};

segments_tree::segments_tree(int cap) {
	tree = new int[cap * 4];
	size = cap;
}

void segments_tree::build(vector<int> a, int current, int start, int end) {
	if(start == end) {
		tree[current] = a[start];
	} else {
		int mid = (start + end) / 2;
		build(a, 2 * current, start, mid);
		build(a, 2 * current + 1, mid + 1, end);
		tree[current] = tree[current * 2] + tree[current * 2 + 1];
	}
}
int segments_tree::sum(int current, int start, int end, int left, int right) {
	if(left > right) {
		return 0;
	}
	if(left == start && right == end) {
		return tree[current];
	}
	int mid = (start + end) / 2;
	return sum(2*current, start, mid, left, std::min(right,mid)) + sum(2* current + 1, mid + 1, end, std::max(left, mid + 1), right);
}

int main() {
	segments_tree t(9);
	vector<int> a = {1,2,3,4,5,7,8,15,42};
	t.build(a, 1, 0, 8);
	std::cout << t.sum(1, 0, 8, 1, 4) << "\n";
	return 0;
}
