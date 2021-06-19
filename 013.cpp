#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using std::cin, std::cout;
template <class T>
using Vec = std::vector<T>;
using KV = std::pair<int, int>;

Vec<int> dists(int start, int N, Vec<Vec<KV>>& adj) {
    Vec<int> dist(N, INT_MAX);
    std::priority_queue<KV, Vec<KV>, std::greater<KV>> heap;

    dist[start] = 0;
    heap.push(KV(0, start));
    while (!heap.empty()) {
        auto [dv, v] = heap.top();
        heap.pop();

        if (dist[v] != dv) continue;
        for (auto [u, c] : adj[v]) {
            int du = dv + c;
            if (du >= dist[u]) continue;
            dist[u] = du;
            heap.push(KV(du, u));
        }
    }

    return dist;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    Vec<Vec<KV>> adj(N);
    for (int i = 0; i < M; i++) {
        int A, B, C;
        std::cin >> A >> B >> C;
        A--, B--;
        adj[A].push_back(KV(B, C));
        adj[B].push_back(KV(A, C));
    }

    Vec<int> dist0 = dists(0, N, adj), dist1 = dists(N - 1, N, adj);
    for (int i = 0; i < N; i++) {
        std::cout << dist0[i] + dist1[i] << '\n';
    }
}