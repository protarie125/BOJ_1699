#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

vi memo;
int solve(int n) {
	if (memo[n] < 0) {
		memo[n] = n;
		for (int i = 1; i * i <= n; ++i) {
			if (n == i * i) {
				memo[n] = 1;
				break;
			}

			const auto& v = solve(n - i * i);
			if (v + 1 < memo[n]) {
				memo[n] = v + 1;
			}
		}
	}

	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	memo = vi(n + 1, -1);
	memo[0] = 0;
	memo[1] = 1;

	cout << solve(n);

	return 0;
}