#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

struct Job {
    long C, D, S;
    bool operator<(Job a) { return this->D < a.D; }
};

int main() {
    int N;
    std::cin >> N;

    std::vector<Job> jobs(N);
    for (Job& j : jobs) std::cin >> j.D >> j.C >> j.S;
    sort(jobs.begin(), jobs.end());

    std::vector<long> dp(5001, 0);
    for (Job j : jobs) {
        std::vector<long> nd(dp);
        for (int start = 0; start <= j.D - j.C; start++) {
            int d = start + j.C;
            nd[d] = std::max(nd[d], dp[start] + j.S);
        }
        for (int i = 1; i <= 5000; i++) {
            nd[i] = std::max(nd[i], nd[i - 1]);
        }
        std::swap(dp, nd);
    }

    std::cout << dp[5000] << '\n';
}