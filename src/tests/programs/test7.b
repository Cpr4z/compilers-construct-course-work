max(a, b) {
    auto result;
    result = a > b ? a : b;
    print(a);
    print(b);
    print(result);
}

main() {
    max(10, 20);
}