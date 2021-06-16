#include <iostream>
#include <vector>

int main() {
    int N, K, L;
    std::cin >> N >> L >> K;

    std::vector<int> A(N);
    for (int& a : A) std::cin >> a;
    A.push_back(L);

    int ng = L, ok = 1;
    while (ng > ok + 1) {
        int mid = (ng + ok) / 2;
        int len = 0, cnt = 0;
        int pre = 0;
        for (int a : A) {
            len += a - pre;
            pre = a;
            if (len >= mid) {
                len = 0;
                cnt += 1;
            }
        }
        if (cnt >= K + 1)
            ok = mid;
        else
            ng = mid;
    }

    std::cout << ok << '\n';
}