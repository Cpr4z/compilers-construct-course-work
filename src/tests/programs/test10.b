main() {
    auto x;
    x = 5;

    goTOfunc(x);

    x = -3;

    goTOfunc(x);
}

goTOfunc(y) {
    print(y);
    if (y > 0) {
        goto label1;
    }
    print(0);
    label1 : print(42);
}