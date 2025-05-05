main() {
    auto n;
    n = 5;
    while (n != 0) {
        print(n);
        n = n - 1;
    }
    f("hello", 42);
    /* return 0; */
}

f(s, y) {
    print(s);
    print(y);
    /* return 0; */
}