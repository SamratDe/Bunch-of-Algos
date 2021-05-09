#include <vector>
using namespace std;

const int N = 100001;
vector<int> par(N), rnk(N);

void init() {
  for (int i = 0; i < N; i++) {
    par[i] = i;
    rnk[i] = 1;
  }
}

int find(int x) {
  if (par[x] != x) par[x] = find(par[x]);
  return par[x];
}

void merge(int x, int y) {
  int xr = find(x), yr = find(y);
  if (xr == yr) return;
  if (rnk[xr] > rnk[yr]) {
    par[yr] = xr;
  } else if (rnk[yr] > rnk[xr]) {
    par[xr] = yr;
  } else {
    par[yr] = xr;
    rnk[xr] += 1;
  }
}
