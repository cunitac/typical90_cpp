#include <atcoder/dsu>
#include <iostream>
#include <vector>

template <class T>
using Vec = std::vector<T>;

int main() {
    int H, W, Q;
    std::cin >> H >> W >> Q;

    Vec<Vec<bool>> red(H, Vec<bool>(W, false));
    atcoder::dsu dsu(H * W);
    auto id = [W](int i, int j) { return i * W + j; };

    for (int iquery = 0; iquery < Q; iquery++) {
        int t;
        std::cin >> t;

        if (t == 1) {
            int r, c;
            std::cin >> r >> c;
            r--, c--;
            red[r][c] = true;
            if (r > 0 && red[r - 1][c]) dsu.merge(id(r, c), id(r - 1, c));
            if (c > 0 && red[r][c - 1]) dsu.merge(id(r, c), id(r, c - 1));
            if (r + 1 < H && red[r + 1][c]) dsu.merge(id(r, c), id(r + 1, c));
            if (c + 1 < W && red[r][c + 1]) dsu.merge(id(r, c), id(r, c + 1));
        } else {
            int ra, ca, rb, cb;
            std::cin >> ra >> ca >> rb >> cb;
            ra--, ca--, rb--, cb--;
            bool yes =
                red[ra][ca] && red[rb][cb] && dsu.same(id(ra, ca), id(rb, cb));
            std::cout << (yes ? "Yes\n" : "No\n");
        }
    }
}