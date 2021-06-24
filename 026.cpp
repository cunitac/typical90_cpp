#include <iostream>
#include <stack>
#include <vector>

template <class T>
using Vec = std::vector<T>;

int main() {
    int N;
    std::cin >> N;

    Vec<Vec<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        std::cin >> A >> B;
        A--, B--;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    Vec<int> color(N, 0);
    color[0] = 1;
    std::stack<int> stack({0});
    while (!stack.empty()) {
        int x = stack.top();
        stack.pop();

        for (int y : adj[x]) {
            if (color[y] != 0) continue;
            color[y] = 3 - color[x];
            stack.push(y);
        }
    }

    int cnt1 = 0;
    for (int col : color)
        if (col == 1) cnt1++;

    int col = cnt1 >= N / 2 ? 1 : 2;
    int done = 0;
    for (int i = 0; i < N && done < N / 2; i++)
        if (color[i] == col) {
            std::cout << (done == 0 ? "" : " ") << (i + 1);
            done++;
        }
    std::cout << '\n';
}