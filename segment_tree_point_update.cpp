# include <vector>
using namespace std;

// segment tree structure
typedef struct node {
  int prefix, suffix, total, ans;
  void leaf(int x) {
    prefix = suffix = total = ans = x;
  }
  void merge(node x, node y) {
    prefix = max(x.prefix, x.total + y.prefix);
    suffix = max(y.suffix, x.suffix + y.total);
    total = x.total + y.total;
    ans = max(prefix, max(suffix, max(total, max(x.ans, max(y.ans, x.suffix + y.prefix)))));
  }
} node;

vector<int> arr;

// build segment tree
void buildSegTree(node segment[], int l, int r, int num) {
  if (l == r) {
    segment[num].leaf(arr[l]);
    return;
  }
  int mid = l + (r - l)/2;
  buildSegTree(segment, l, mid, 2 * num);
  buildSegTree(segment, mid + 1, r, 2 * num + 1);
  segment[num].merge(segment[2 * num], segment[2 * num + 1]);
}

// point update
void update(node segment[], int l, int r, int indx, int val, int num) {
  if (l == r) {
    arr[indx] = val;
    segment[num].leaf(val);
    return;
  }
  int mid = (l + r) / 2;
  if (indx >= l && indx <= mid) update(segment, l, mid, indx, val, 2 * num);
  else update(segment, mid + 1, r, indx, val, 2 * num + 1);
  segment[num].merge(segment[2 * num], segment[2 * num + 1]);
}

// query for [inputL, inputR]
node query(node segment[], int l, int r, int inputL, int inputR, int num) {
  if (l >= inputL && r <= inputR) return segment[num];
  int mid = l + (r - l)/2;
  if (mid >= inputR) return query(segment, l, mid, inputL, inputR, 2 * num);
  else if (mid < inputL) return query(segment, mid + 1, r, inputL, inputR, 2 * num + 1);
  node leftNode = query(segment, l, mid, inputL, inputR, 2 * num);
  node rightNode = query(segment, mid + 1, r, inputL, inputR, 2 * num + 1);
  node res;
  res.merge(leftNode, rightNode);
  return res;
}


int main() {
  int n = 10000;
  arr.assign(n, 0);
  // intialise
  int sz = 2 * pow(2, ceil(log2(n))) + 1;
  node segment[sz];
  // build
  buildSegTree(segment, 0, n - 1, 1);
}