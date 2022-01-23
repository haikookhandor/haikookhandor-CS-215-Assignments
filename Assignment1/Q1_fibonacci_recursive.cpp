#include <iostream>
#include <ctime>

using namespace std;
__int128 fibonacci_recursion(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    __int128 smallNumber = fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
    return smallNumber;
}

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
    for (int i = 1; i < n + 1; i++)
    {
        cout << fibonacci_recursion(i) << " ";
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    __int128 nanoseconds = end.tv_nsec - start.tv_nsec;
    cout << "\nTime taken: " << nanoseconds * (1e-6) << " miliseconds\n";
    return 0;
}
