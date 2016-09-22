// You are given a description of a rooted tree. Your task is to compute and output its height. Recall
// that the height of a (rooted) tree is the maximum depth of a node, or the maximum distance from a
// leaf to the root. You are given an arbitrary tree, not necessarily a binary tree.
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 1e5;
vector<int> tree(maxn);
int n;

void height(int node, int& max_height) {
  int mx = 1;
  while (node != - 1) {
    node = tree[node];
    mx++;
  }
  max_height = max(max_height, mx);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> tree[i];

  int max_height = 0;
  for (int i = 0; i < n; ++i)
    height(tree[i], max_height);
  cout << max_height << endl;

  return 0;
}
