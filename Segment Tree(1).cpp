int arr[100005];
int segment[400020];

void build(int low, int high, int num) {
	if (low == high) {
		segment[num] = arr[low];
		return;
	}
	int mid = (low + high) / 2;
	build(low, mid, 2 * num);
	build(mid + 1, high, 2 * num + 1);
	segment[num] = min(segment[2 * num], segment[2 * num + 1]);
}

void update(int low, int high, int indx, int val, int num) {
	if (low == high) {
		arr[indx] = val;
		segment[num] = val;
	} else {
		int mid = (low + high) / 2;
		if (indx >= low && indx <= mid) {
			update(low, mid, indx, val, 2 * num);
		} else {
			update(mid + 1, high, indx, val, 2 * num + 1);
		}
		segment[num] = min(segment[2 * num], segment[2 * num + 1]);
	}
}

int query(int low, int high, int l, int r, int num) {
	if (l <= low && r >= high) {
		return segment[num];
	}
	int mid = (low + high) / 2;
	if (mid >= r) {
		return query(low, mid, l, r, 2 * num);
	} else if (mid < l) {
		return query(mid + 1, high, l, r, 2 * num + 1);
	}
	int m = query(low, mid, l, r, 2 * num);
	int n = query(mid + 1, high, l, r, 2 * num + 1);
	return min(m, n);
}

// size of tree -> N=2*pow(2,ceil(log2(n)))      n is the size of arr[]
// or take N = 4*n  :p XD
