auto IsPrime(n) {
    if (n <= 2) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    } else {
        auto k = 1 + sqrt(n);
        while ((n % k != 0) && (k > 2)) {
            k = k - 1;
        }
        return k != 2;
    }
}

auto main() {
    auto e0 = IsPrime(17);
    print(e0);

    auto e1 = IsPrime(16);
    print(e1);

    return 0;
}