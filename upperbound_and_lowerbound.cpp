# include <vector>
using namespace std;

// when the element is present
// 'ans' returns 0-based index position

int lowerBound(vector<int> arr, int target) {
  int ans = 0;
  int n = arr.size();
  // binary search
  int l = 0, h = n - 1;
  while (l <= h) {
    if (arr[mid] == target) {
      ans = mid;
      h = mid - 1;
    } else if (arr[mid] > target) h = mid - 1;
    else l = mid + 1;
  }
  return ans;
}

int upperBound(vector<int> arr, int target) {
  int ans = 0;
  int n = arr.size();
  int l = 0, h = n - 1;
  while (l <= h) {
    if (arr[mid] == target) {
      ans = mid;
      l = mid + 1;
    } else if (arr[mid] > target) h = mid - 1;
    else l = mid + 1;
  }
  return ans;
}
