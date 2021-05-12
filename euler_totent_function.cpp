# include <vector>
using namespace std;
# define LL long long
# define MOD (LL)(1e9+7)

// for input n, count numbers in [1, n] that have GCD of 1 with n
int phiFunction(int n) {
  long double res = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      res *= (1.0 - (1.0/(long double)i));
    }
  }
  if (n > 1) res *= (1.0 - (1.0/(long double)n));
  return (int)res;
}

// summation of gcd(i, n), where i = [1, n]
LL gcdSumFunction(int n) {
  LL res = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      int div1 = i, div2 = n/i;
      res += div1 * phiFunction(n/div1);
      if (div1 != div2) {
        res += div2 * phiFunction(n/div2);
      }
    }
  }
  return res;
}


// PRECOMPUTING phi & gcdSum - for query problems
const int V = 5e5;
vector<LL> phi, F;

inline LL mod(LL x) {
  return (x%MOD + MOD)%MOD;
}

void phiFunction() {
  phi.assign(V + 1, 0);
  for (int i = 1; i <= V; i++) phi[i] = i;
  for (int i = 2; i <= V; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= V; j += i) {
        phi[j] -= phi[j]/i;
        phi[j] = mod(phi[j]);
      }
    }
  }
}

// F(x) = gcd(1, x) + gcd(2, x) + .... + gcd(x, x)
void gcdSum() {
  F.assign(V + 1, 0);
  for (int i = 1; i <= V; i++) {
    for (int j = i; j <= V; j += i) {
      F[j] += i * phi[j/i];
      F[j] = mod(F[j]);
    }
  }
}