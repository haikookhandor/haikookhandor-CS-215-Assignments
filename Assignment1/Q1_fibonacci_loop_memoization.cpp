#include <iostream>
#include <ctime>

using namespace std;

std::ostream &
operator<<(std::ostream &dest, __int128_t value)
{
    std::ostream::sentry s(dest);
    if (s)
    {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[256];
        char *d = std::end(buffer);
        do
        {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0)
        {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len)
        {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

int main()
{
    timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    int n;
    cin >> n;
    __int128 array[101];
    array[0] = 0;
    array[1] = 1;
    for (int i = 2; i < n; i++)
    {
        array[i] = array[i - 1] + array[i - 2];
    }
    for (int j = 0; j < n; j++)
    {
        cout << array[j] << " ";
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    __int128 nanoseconds = end.tv_nsec - start.tv_nsec;
    cout << "\nTime taken: " << nanoseconds << " nanoseconds\n";

    return 0;
}
