# include <vector>
using namespace std;
#define LL long long
#define INF (LL)(1e18)

typedef struct FenwickTree {
  vector<LL> bit;
  int n;
  const LL val = INF;
  FenwickTree(int n) {
    this->n = n;
    bit.assign(n + 1, val);
  }
  FenwickTree(vector<LL> arr) {
    int sz = arr.size();
    this->n = sz;
    bit.assign(sz + 1, 0);
    for (int i = 0; i < sz; i++) {
      update(i + 1, arr[i]);
    }
  }
  void update(int indx, LL val) {
    for (; indx <= n; indx += (indx & (-indx))) {
      bit[indx] += val;
    }
  }
  LL query(int indx) {
    LL ans = 0;
    for (; indx > 0; indx -= (indx & (-indx))) {
      ans += bit[indx];
    }
    return ans;
  }
} FenwickTree;
