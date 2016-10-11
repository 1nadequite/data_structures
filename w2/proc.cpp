// In this problem you will simulate a program that processes a list of jobs in parallel.
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const ll inf = 1e9;
int n, m;

template <typename T>
class priority_queue {
  public:
    priority_queue(size_t n) : max_size_(n), size_(0), data_(n) {
      for (int i = 0; i < n; ++i)
        data_[i] = {inf, {0, 0}};
    }

    size_t parent(size_t i) { return (i - 1) / 2; }
    size_t left_child(size_t i) { return 2 * i + 1; }
    size_t right_child(size_t i) { return 2 * i + 2; }
    void sift_up(size_t);
    void sift_down(size_t);
    void insert(T, size_t, size_t);
    ll extract_min();
    void remove(size_t);
    size_t size() { return size_; }
    bool full();
    bool empty();

  private:
    size_t max_size_;
    size_t size_;
    vector<pair<T, pair<size_t, size_t>>> data_;
};

template <typename T>
void priority_queue<T>::sift_up(size_t i) {
  while (i > 0 && data_[parent(i)].first > data_[i].first) {
    swap(data_[parent(i)], data_[i]);
    i = parent(i);
  }
}

template <typename T>
void priority_queue<T>::sift_down(size_t i) {
  size_t max_index = i, l = left_child(i);
  if (l <= size_ && data_[l].first < data_[max_index].first)
    max_index = l;
  size_t r = right_child(i);
  if (r <= size_ && data_[r].first < data_[max_index].first)
    max_index = r;
  if (i != max_index) {
    swap(data_[i], data_[max_index]);
    sift_down(max_index);
  }
}

template <typename T>
void priority_queue<T>::insert(T time, size_t base, size_t val) {
  if (size_ == max_size_) {
    cout << "Error: priority_queue is full." << endl;
    return;
  }
  data_[size_] = {time, {base, val}};
  sift_up(size_);
  size_++;
}

template <typename T>
ll priority_queue<T>::extract_min() {
  if (size_ == 0) {
    cout << "Error: priprity_queue is empty." << endl;
    return -1;
  }
  ll result = data_[0].second.second + data_[0].first;
  cout << data_[0].second.first << ' ' << data_[0].first << endl;
  data_[0] = data_[size_];
  size_--;
  sift_down(0);
  return result;
}

template <typename T>
void priority_queue<T>::remove(size_t i) {
  if (size_ == 0) {
    cout << "Error: priority_queue is empty." << endl;
    return;
  }
  data_[i] = {0, {0, 0}};
  sift_up(i);
  extract_min();
}

template <typename T>
bool priority_queue<T>::full() {
  if (size_ == max_size_) return true;
  else return false;
}

template <typename T>
bool priority_queue<T>::empty() {
  if (size_ == 0) return true;
  else return false;
}

int main() {
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; ++i) cin >> a[i];
  priority_queue<ll> q(n);

  ll time = 0;
  for (int i = 0; i < m; ++i) {
    if (!q.full()) {
      cout << "insert: " << time << ' ' << i % n << ' ' << a[i] << endl;
      q.insert(time, i % n, a[i]);
    } else {
      time = q.extract_min();
      cout << "insert: " << time << ' ' << i % n << ' ' << a[i] << endl;
      q.insert(time, i % n, a[i]);
    }
  }

  while (!q.empty()) time = q.extract_min();

  return 0;
}
