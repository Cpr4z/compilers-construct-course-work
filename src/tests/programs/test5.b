auto main() {
    auto n = 5;
    while (n != 0) {
        print(n);
        n = n - 1;
    }
    f("hello", 42);
    return 0;
}

auto f(auto s, auto y) {
    print(s);
    print(y);
    return 0;
}