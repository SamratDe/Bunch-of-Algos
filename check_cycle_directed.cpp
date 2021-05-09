#include <vector>
using namespace std;

enum Markings {WHITE, GRAY, BLACK};
const int N = 100001;
vector<int> graph[N];
vector<int> color(N, WHITE);

bool checkCycle(int src) {
  color[src] = WHITE;
  for(int i = 0; i < graph[src].size(); i++) {
    int v = graph[src][i];
    if (color[v] == GRAY) return true;
    if (color[v] == WHITE && checkCycle(v)) return true;
  }
  color[src] = BLACK;
  return false;
}
