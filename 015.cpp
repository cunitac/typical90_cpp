#include <atcoder/modint>
#include <iostream>
#include <vector>

using M = atcoder::modint1000000007;

int main() {
    int N;
    std::cin >> N;

    std::vector<M> fact(2 * N + 1);
    fact[0] = fact[1] = M(1);
    for (int i = 2; i <= 2 * N; i++) fact[i] = fact[i - 1] * M(i);

    for (int k = 1; k <= N; k++) {
        M ans(0);
        int n = N + k - 1;
        for (int c = 1; c <= n / k; c++) {
            int m = n - c * (k - 1);
            ans += fact[m] / fact[c] / fact[m - c];
        }
        std::cout << ans.val() << '\n';
    }
}