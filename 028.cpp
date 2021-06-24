#include <iostream>
#include <vector>

template <class T>
using Vec = std::vector<T>;

int main() {
    int N;
    std::cin >> N;
    Vec<Vec<int>> cnt(1001, Vec<int>(1001, 0));
    for (int i = 0; i < N; i++) {
        int lx, ly, rx, ry;
        std::cin >> lx >> ly >> rx >> ry;
        cnt[lx][ly]++;
        cnt[rx][ry]++;
        cnt[lx][ry]--;
        cnt[rx][ly]--;
    }
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j < 1000; j++) cnt[i][j + 1] += cnt[i][j];
    for (int j = 0; j <= 1000; j++)
        for (int i = 0; i < 1000; i++) cnt[i + 1][j] += cnt[i][j];
    Vec<int> ans(N + 1, 0);
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++) ans[cnt[i][j]]++;
    for (int k = 1; k <= N; k++) std::cout << ans[k] << '\n';
}
