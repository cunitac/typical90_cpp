#include <iostream>
#include <string>

using std::string;

void dfs(int N, int open, string parens) {
    if (parens.size() == N) {
        if (open == 0) std::cout << parens << '\n';
        return;
    }

    dfs(N, open + 1, parens + "(");
    if (open > 0) dfs(N, open - 1, parens + ")");
}

int main() {
    int N;
    std::cin >> N;

    dfs(N, 0, "");
}