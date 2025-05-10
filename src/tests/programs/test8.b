main() {
    someFunc(1982, 3);
    someFunc(0, 0);
}

someFunc(a, b) {
    if ((a + b) > 0) {
        print("a + b > 0");
    }
    else {
        print("a + b <= 0");
    }
}