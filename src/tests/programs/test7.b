max(a, b) {
    auto result;
    result = a > b ? a : b;
    return (result);
}

main() {
    print(max(10, 20));
}