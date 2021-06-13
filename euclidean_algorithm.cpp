// BASIC ALGO:
// If we subtract a smaller number from a larger, GCD doesn’t change.
// Now, instead of subtraction, if we divide the smaller number, the 
// algorithm stops when we find remainder 0.

int basic_euclidean(int a, int b) {
  if (a == 0) return b;
  return basic_euclidean(b%a, a);
}

// EXTENDED ALGO:
// Extended Euclidean algorithm also finds integer coefficients x and y such that:
// ax + by = gcd(a, b), along with the gcd.

int euclidean_extended(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0, y = 1;
    return b;
  }
  int x1, y1;
  int gcd_val = euclidean_extended(b%a, a, x1, y1);
  x = y1 - (b/a)*x1;
  y = x1;
  return gcd_val;
}
