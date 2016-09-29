#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const int inf = 1e9;

template <typename T>
class priority_queue {
  public:
    priority_queue(size_t n) : max_size_(n + 1), size_(1), data_(n + 1) {}

    int parent(size_t i) { return i / 2; }
    int left_child(size_t i) { return 2 * i; }
    int right_child(size_t i) { return 2 * i + 1; }
    void sift_up(size_t);
    void sift_down(size_t);
    void insert(T);
    T extract_max();
    void remove(size_t);
    void change_priority(size_t, T);

  private:
    size_t max_size_;
    size_t size_;
    vector<T> data_;
};

template <typename T>
void priority_queue<T>::sift_up(size_t i) {
  while (i > 1 && data_[parent(i)] < data_[i]) {
    swap(data_[parent(i)], data_[i]);
    i = parent(i);
  }
}

template <typename T>
void priority_queue<T>::sift_down(size_t i) {
  size_t max_index = i, l = left_child(i);
  if (l <= size_ && data_[l] > data_[max_index])
    max_index = l;
  size_t r = right_child(i);
  if (r <= size_ && data_[r] > data_[max_index])
    max_index = r;
  if (i != max_index) {
    swap(data_[i], data_[max_index]);
    sift_down(max_index);
  }
}

template <typename T>
void priority_queue<T>::insert(T val) {
  if (size_ == max_size_) {
    cout << "Error: priority_queue is full." << endl;
    return;
  }
  size_++;
  data_[size_] = val;
  sift_up(size_);
}

template <typename T>
T priority_queue<T>::extract_max() {
  T result = data_[1];
  data_[1] = data_[size_];
  size_--;
  sift_down(1);
  return result;
}

template <typename T>
void priority_queue<T>::remove(size_t i) {
  data_[i] = inf;
  sift_up(i);
  extract_max();
}

template <typename T>
void priority_queue<T>::change_priority(size_t i, T val) {
  T old_val = data_[i];
  data_[i] = val;
  if (val > old_val) sift_up(i);
  else sift_down(i);
}

int main() {
  priority_queue<int> q(20);
  q.insert(6);
  q.insert(8);
  q.insert(3);
  q.insert(9);
  cout << "extract max: " << q.extract_max() << endl;
  q.remove(1);
  cout << "extract max: " << q.extract_max() << endl;
  q.insert(10);
  q.change_priority(1, 12);
  cout << "extract max: " << q.extract_max() << endl;

  return 0;
}
