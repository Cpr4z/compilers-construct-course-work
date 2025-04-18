auto Print1() {
    print("Hi!");
    return;
}

auto Print2(x) {
    print(x);
    return;
}

auto Print3(x, y) {
    print(x);
    print(y);
    return;
}

auto main() {
    Print1();
    Print2(3.1415);
    Print3(777, "Ok!");
    return 0;
}