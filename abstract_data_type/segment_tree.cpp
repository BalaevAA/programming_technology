#include<iostream>


const int MAX_N = 1e5+2;
int a[MAX_N], tree[MAX_N * 4];

void build(int a[],int current, int start, int end) {
    if(start == end) {
        tree[current] = a[start];
    } else {
        int mid = (start + end) / 2;
        build(a, 2*current, start, mid);
        build(a, 2*current + 1, mid + 1, end);
        tree[current] = tree[current*2] + tree[2*current+1];
    }
}

int sum(int current, int start, int end, int left, int right) {
    if(left > right) {
        return 0;
    }
    if(left == start && right == end) {
        return tree[current];
    }
    int mid = (start + end) / 2;
    return sum(2*current, start, mid, left, std::min(right, mid)) + sum(2*current + 1, mid + 1, end, std::max(left, mid + 1), right);
}

int main() {
    int n = 9;
    int a[n]{1,2,3,4,5,7,8,15,42};
    build(a, 1, 0, n-1);
    std::cout << sum(1, 0, n-1, 1, 4) << "\n";
    return 0;
}


