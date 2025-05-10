main() {
    auto x;
    x = 5;
    goTOfunc(0);
    x = -3;
    goTOfunc(4);
}

goTOfunc(y) {
    if (y > 0) {
        goto label1;
    }
    print(0);
    label1 : print(42);
}