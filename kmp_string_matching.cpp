# include <vector>
# include <string>
# include <iostream>
using namespace std;

vector<int> lps;
string txt, pat;

void precompute(int sz) {
  int i = 0, j = 1;
  while (j < sz) {
    if (pat[i] == pat[j]) {
      i++;
      lps[j] = i;
      j++;
    } else {
      if (i != 0) {
        i = lps[i - 1]; // MVP line
      } else {
        lps[j] = 0;
        j++;
      }
    }
  }
}

int kmpSearch() {
  int n = txt.length();
  int m = pat.length();
  lps.assign(m, 0);
  precompute(m);
  int i = 0, j = 0;
  int count = 0;
  while (i < n) {
    if (txt[i] == pat[j]) i++, j++;
    if (j == m) {
      count++;
      j = lps[j - 1];
    } else if (i < n && txt[i] != pat[j]) {
      if (j != 0) j = lps[j - 1];
      else i++;
    }
  }
  return count;
}
