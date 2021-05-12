# include <vector>
# include <utility>
using namespace std;
# define LL long long

void compressVector(vector<LL> &arr) {
  vector<pair<LL, LL> > compress;
  for (int i = 0; i < arr.size(); i++) compress.push_back({arr[i], i});
  sort(compress.begin(), compress.end());
  int val = 1;
  for (auto i : compress) arr[i.second] = val++;
}
