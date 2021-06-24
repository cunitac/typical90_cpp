#include <iostream>
#include <vector>

template <class T>
using Vec = std::vector<T>;

int main() {
    int K;
    std::cin >> K;
    if (K % 9 != 0) {
        std::cout << "0\n";
        return 0;
    }
    Vec<int> dp(K + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= K; i++)
        for (int j = 1; j <= 9 && i >= j; j++)
            dp[i] = (dp[i] + dp[i - j]) % 1'000'000'007;
    std::cout << dp[K] << '\n';
}