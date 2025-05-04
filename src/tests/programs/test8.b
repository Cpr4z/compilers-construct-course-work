auto f(x) {
    auto f = x;
    f = -x;
    f = !x;
    return f;
}

auto g(x, y) {
    auto g = x + y;
    g = x - y;
    g = x * y;

    if (y != 0) {
        g = x / y;
        g = x % y;
    }

    g = x & y;
    g = x | y;

    g = x == y;
    g = x != y;
    g = x > y;
    g = x >= y;
    g = x < y;
    g = x <= y;

    return g;
}

auto h(x, y) {
    auto h = (x + y) || (x - y);
    h = (x + y) && (x - y);

    h = (x == y) || (x != y);
    h = (x == y) && (x != y);

    h = (x > y) || (x < y);
    h = (x > y) && (x < y);

    return h;
}

auto main() {
    print(f(2));
    print(g(1, 1));
    print(h(3, 5));
    return 0;
}