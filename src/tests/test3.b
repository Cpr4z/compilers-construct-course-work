auto main() {
    auto i = 0;
    while (i <= 10) {
        print(i * i);
        i = i + 2;
    }

    auto j = 0;
    while (j <= 10) {
        print(j * j * j);
        j = j + 1;
    }

    auto k = 0;
    while (k <= 10) {
        break;
    }
    return 0;
}