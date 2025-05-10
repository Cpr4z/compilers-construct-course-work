extrn print;

main() {
    auto x;
    auto y;
    auto max;

    x = 10;
    y = 20;

    max = x > y ? x : y;

    print(max);
}