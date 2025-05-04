main() {
    auto a;
    auto b;
    a = 6;
    b = 1981;

    auto tmp;
    tmp = max(a, b);
    print(max(a, b));
    /* return (0); */
    /* print(max(6, 1981));
    print(max(6, 1981)); */
}

max(a, b) {
    /* if ((x + y) > 0) { */
    if (a > 0) {
        print(1);
    }
    a = 3;
    auto result;
    result = a;
    /* result = a > b ? a : b; */
    print(result);
    print(a);
    return (result);
}