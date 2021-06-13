// The modular multiplicative inverse is an integer ‘x’ such that: a x ≅ 1 (mod m)

// The multiplicative inverse of “a modulo m” exists - 
// if and only if a and m are relatively prime i.e. gcd(a, m) = 1


// IDEA:
// Use Extended Euclidean Algorithm, that takes 2 integer 'a' & 'b', find their gcd
// and also the value of 'a' & 'b'
// ax + by = gcd(a, b)

// As we know, gcd(a, m) = 1, put b = m. So,
// ax + my = 1
// => ax + my ≅ 1 (mod m)  [taking mod on both side]
// => ax ≅ 1 (mod m)   [remove 'my' on left side as ‘my (mod m)’ would always be 0]

// So the ‘x’ that we can find using Extended Euclid Algorithm is 
// the multiplicative inverse of ‘a’.

int mod_inverse(int a, int m) {
  int x, y;
  // here, b = m
  int gcd_val = euclidean_extended(a, m, x, y);
  if (gcd_val != 1) return -1;
  else return (x%m + m)%m;
}

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

// Using Fermet's little theorem:
// It states that if p is a prime number, then for any integer a, the
// number (a^p – a) is an integer multiple of p 
// i.e a^p = a(mod p)
// => a^(p-1) = 1(mod p)
// => a^(p-2) = a^(-1) (mod p)

// So, we can find inverse of a i.e a^(-1)  =  a^(p-2).