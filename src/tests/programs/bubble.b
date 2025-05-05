main() {
    auto n;
    n = 10;
    auto i;
    i = 0;
    auto j;
    j = 0;
    auto temp;
    temp = 0;

    auto arr;
    arr = [2, 1, 3, 0, 1, 5, 4, 6, 2, 1];

    while (i < n) {
        j = 0;
        while (j < n - i - 1) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j = j + 1;
        }
        i = i + 1;
    }

    i = 0;
    while (i < n) {
        print(arr[i]);
        i = i + 1;
    }
}