main() {
    auto a;
    auto b;
    a = 6;
    b = 1981;

    auto tmp;
    tmp = max(a, b);
    print(max(a, b));
}

max(a, b) {
    if (a > 0) {
        print(1);
    }
    a = 3;
    auto result;
    result = a;
    print(result);
    print(a);
    return (result);
}