// In this problem you will convert an array of integers into a heap.
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
vector<pair<int, int>> ans;
int n;

int left_child(int i) {
  return (2 * i + 1);
}

int right_child(int i) {
  return (2 * i + 2);
}

void sift_down(int i, vector<int>& a) {
  int max_ind = i;
  int l = left_child(i);
  if (l <= n && a[l] < a[max_ind])
    max_ind = l;
  int r = right_child(i);
  if (r <= n && a[r] < a[max_ind])
    max_ind = r;
  if (i != max_ind) {
    ans.push_back({i, max_ind});
    swap(a[i], a[max_ind]);
    sift_down(max_ind, a);
  }
}

void array_into_heap(vector<int>& a) {
  for (int i = n - 1; i >= 0; --i)
    sift_down(i, a);
}

int main() {
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  array_into_heap(a);

  for (int i = 0; i < n; ++i)
    cout << a[i] << ' ';
  cout << endl;
  cout << ans.size() << endl;
  for (auto& x: ans)
    cout << x.first << ' ' << x.second << endl;

  return 0;
}
