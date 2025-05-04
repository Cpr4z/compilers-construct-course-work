main() {
    auto a;
    auto b;
    a = 6;
    b = 1981;

    print(max(a, b));
    /* print(max(6, 1981));
    print(max(6, 1981)); */
}

max(a, b) {
    /* if ((x + y) > 0) { */
    if (a > 0) {
        print(1);
    }
    auto result;
    result = a > b ? a : b;
    print(a + b);
    return (result);
}