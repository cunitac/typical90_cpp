#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

using point = std::pair<int, int>;

double to_rad(double a) { return a * 180 / M_PI; }
double angle(double a, double b) {
    double d = std::abs(a - b);
    return std::min(d, 360 - d);
}

int main() {
    int N;
    std::cin >> N;

    std::vector<point> P(N);
    for (point& p : P) std::cin >> p.first >> p.second;

    double ans = 0;
    for (point p : P) {
        std::vector<double> Q;
        for (point q : P) {
            if (q != p) {
                double arg = std::atan2(q.second - p.second, q.first - p.first);
                Q.push_back(to_rad(arg));
            }
        }
        assert(Q.size() == N - 1);
        std::sort(Q.begin(), Q.end());
        for (int i = 0, j = 1; i < Q.size() - 1; i++) {
            while (j + 1 < Q.size() && abs(Q[i] - Q[j + 1]) < 180) j += 1;
            ans = std::max(ans, angle(Q[i], Q[j]));
            if (j + 1 < Q.size()) ans = std::max(ans, angle(Q[i], Q[j + 1]));
        }
    }

    std::cout << std::setprecision(10) << ans << '\n';
}