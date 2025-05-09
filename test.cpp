#include <cstdio>

int main() {
    constexpr int a = 10;
    constexpr int b = 3;
    constexpr float c = static_cast<float>(a) / static_cast<float>(b);
    printf("%.2f\n", c);
}