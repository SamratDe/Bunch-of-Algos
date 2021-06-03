#include <vector>
using namespace std;

enum Markings {WHITE, GREY, BLACK};
const int N = 100001;
vector<int> graph[N];
vector<int> color(N, WHITE);

bool checkCycle(int u) {
  color[u] = GREY;
  for (int v : graph[u]) {
    if (color[v] == GREY) return true;
    if (color[v] == WHITE && checkCycle(v)) return true;
  }
  color[u] = BLACK;
  return false;
}
