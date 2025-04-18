auto max(x, y) {
    if ((x + y) > 0) {
        print(1);
    }
    auto result = x > y ? x : y;
    print(x + y);
    return result;
}

auto main() {
    print(max(6, 1981));
    print(max(6, 1981));
    return 0;
}