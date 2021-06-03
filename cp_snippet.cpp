# include <iostream>
# include <utility>
# include <iterator>
# include <string>
# include <stdio.h>
# include <map>
# include <unordered_map>
# include <algorithm>
# include <queue>
# include <vector>
# include <climits>
# include <cstring>
# include <set>
# include <unordered_set>
# include <sstream>
# include <deque>
# include <bitset>
# include <functional>
# include <numeric>
# include <stack>
# include <limits>
# include <time.h>
# include <math.h>
# include <stdlib.h>
# include <assert.h>

using namespace std;

# define SAMRAT ios::sync_with_stdio(0);cin.tie(0);
# define LL long long
# define LD long double
# define FOR(i,x,y) for(LL i=x;i<y;i++)
# define RFOR(i,x,y) for(LL i=x;i>=y;i--)
# define DEBUG_1D(x,a,b) FOR(i,a,b){cout<<x[i]<<" ";}cout<<endl;
# define DEBUG_2D(x,a1,b1,a2,b2) FOR(i,a1,b1){FOR(j,a2,b2){cout<<x[i][j]<<" ";}cout<<endl;}
# define ALL(x) x.begin(), x.end()
# define MOD (LL)(1e9+7)
# define INF8 (LL)(1e17+5)
# define endl '\n'

typedef vector<LL> VI;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<LL, LL> PI;
typedef pair<LL, PI> PPI;
typedef vector<PI> VP;
typedef vector<PPI> VPP;

inline LL mod(LL x) {
  return (x%MOD + MOD)%MOD;
}

LL POWER(LL x, LL y) {
  LL res = 1;
  x = x%MOD;
  if (x == 0) return 0;
  while (y > 0) {
    if (y&1) res = mod(res * x);
    y >>= 1; x = mod(x * x);
  }
  return res;
}

LL nCr(int n, int r) {
  r = min(r, n - r);
  if (!r) return 1;
  LL num = 1, deno = 1;
  while (r) {
    num *= n;
    deno *= r;
    LL div = gcd(num, deno); // only works on C++17
    num /= div;
    deno /= div;
    n--, r--;
  }
  return num;
}

int main() {

  SAMRAT

  int t = 1;
  // cin >> t;
  while (t--) {
    
  }
  
  return 0;
}
