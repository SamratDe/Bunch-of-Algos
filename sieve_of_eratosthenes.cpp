# include <vector>
using namespace std;

// Complexity: O(n * log(log(n)))

const int N = 100000;
vector<bool> prime(N + 1, true);
vector<int> pf(N + 1);

void sieve() {
  for (int i = 2; i * i <= N; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        prime[i] = false;
      }
    }
  }
}

// smallest prime factor
void spf() {
  for (int i = 0; i <= N; i++) pf[i] = i;
  for (int i = 2; i * i <= N; i++) {
    if (pf[i] == i) {
      for (int j = i * i; j <= N; j += i) {
        if (pf[j] == j) {
          pf[j] = i;
        }
      }
    }
  }
}
