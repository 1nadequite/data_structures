// Network packet processing simulation
#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;
deque<int> finish_time;
int s, n;

int main() {
  cin >> s >> n;
  for (int i = 0; i < n; ++i) {
    int a, p; cin >> a >> p;

    while (!finish_time.empty()) {
      int time = finish_time.push_back();
      if (time <= a) finish_time.pop_front();
      else break;
    }

    if (finish_time.size() < s) {
      int time = a;
      if (!finish_time.empty()) time = finish_time.back();
      cout << time << endl;
      finish_time.push(time + p);
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
