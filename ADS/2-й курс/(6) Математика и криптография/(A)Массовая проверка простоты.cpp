#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <ctime>
#include <fstream>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <stdio.h> 
#include <tuple>
using namespace std;

typedef long long LL;

const LL LONG_INF = 1e18;
const int INT_INF = 1e9 + 7;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	/*freopen("assignment.in", "r", stdin);
	freopen("assignment.out", "w", stdout);*/
#endif
	int n;
	const int maxN = 2 * 1e7 + 10;
	scanf("%d", &n);
	vector<bool> isPrime(maxN + 1, true);
	vector<int> arr(n);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= maxN; ++i) {
		if (isPrime[i]) {
			if (i * 1ll * i <= maxN) {
				for (int j = i * i; j <= maxN; j += i)
					isPrime[j] = false;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		if (isPrime[arr[i]]) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
close