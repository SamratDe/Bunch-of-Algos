# include <vector>
using namespace std;

# define LL long long
# define MOD (LL)(1e9+7)

// Using Fermet's little theorem

const int N = 1000001;
vector<LL> fact(N);

void calc_fact() {
  fact[0] = 1;
  for (int i = 0; i < N; i++) fact[i] = (fact[i - 1] * i)%MOD;
}

LL POWER(LL x, LL y) {
  LL res = 1;
  x = x%MOD;
  if (x == 0) return 0;
  while (y > 0) {
    if (y&1) res = (res * x)%MOD;
    y >>= 1; x = (x * x)%MOD;
  }
  return res;
}

LL mod_inverse(LL n, LL p) {
  return POWER(n, p - 2);
}

LL nCrMODp(LL n, LL r , LL p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  LL res = (fact[n] * mod_inverse(fact[r], p))%MOD;
  res = (res * mod_inverse(fact[n - r], p))%MOD;
  return res;
}
