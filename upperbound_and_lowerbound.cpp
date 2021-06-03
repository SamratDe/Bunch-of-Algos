# include <vector>
using namespace std;

// when the target is present
// 'ans' returns 0-based index position

int lowerBound(vector<int> &arr, int target) {
  int ans = 0;
  int n = arr.size();
  // binary search
  int l = 0, h = n - 1;
  while (l <= h) {
    int mid = l + (h - l)/2;
    if (arr[mid] == target) {
      ans = mid;
      h = mid - 1;
    } else if (arr[mid] > target) h = mid - 1;
    else l = mid + 1;
  }
  return ans;
}

int upperBound(vector<int> &arr, int target) {
  int ans = 0;
  int n = arr.size();
  int l = 0, h = n - 1;
  while (l <= h) {
    int mid = l + (h - l)/2;
    if (arr[mid] == target) {
      ans = mid;
      l = mid + 1;
    } else if (arr[mid] > target) h = mid - 1;
    else l = mid + 1;
  }
  return ans;
}


// find closest element to target, when target is not present
int findClosest(vector<int> &arr, int target) {
  int n = arr.size();

  // corner cases
  if (target <= arr[0]) return 0;
  if (target >= arr[n - 1]) return (n - 1);

  // main logic
  int l = 0, h = arr.size() - 1;
  int mid = 0;
  while (l < h) {
    mid = l + (h - l)/2;
    if (arr[mid] == target) return mid;
    if (target < arr[mid]) {
      if (mid > 0 && target > arr[mid - 1]) {
        return (getClosest(arr[mid - 1], arr[mid], target) == arr[mid - 1] ? (mid - 1) : mid);
      }
      h = mid;
    } else {
      if (mid < n - 1 && target < arr[mid + 1]) {
        return (getClosest(arr[mid], arr[mid + 1], target) == arr[mid] ? mid : (mid + 1));
      }
      l = mid + 1;
    }
  }
  return mid;
}

int getClosest(int val1, int val2, int target) {
  if (abs(val1 - target) >= abs(val2 - target)) return val2;
  return val1;
}