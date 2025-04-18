auto Gcd(auto x, auto y) {
    while (x * y != 0) {
        if (x > y) {
            x = x - y;
        } else {
            y = y - x;
        }
    }
    return x + y;
}

auto main() {
    print(Gcd(18, 192));
    return 0;
}