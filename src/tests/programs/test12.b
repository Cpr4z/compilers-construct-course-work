main()
{
    auto arr[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    auto i;
    auto j;
    auto tmp1;
    auto tmp2;

    i = 0;
    j = 4;

    auto tmpCounter;
    tmpCounter = 0;

    while (tmpCounter < 5)
    {
        print(arr[tmpCounter]);
        ++tmpCounter;
    }

    while (i < j)
    {
        tmp1 = arr[i];
        tmp2 = arr[j];
        arr[i] = tmp2;
        arr[i] = arr[j];
        arr[j] = tmp1;
        ++i;
        --j;
    }

    print(" ");

    tmpCounter = 0;
    while (tmpCounter < 5)
    {
        print(arr[tmpCounter]);
        ++tmpCounter;
    }
}