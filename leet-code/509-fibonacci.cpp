#include <iostream>

int fibonacci(int n)
{
    /*
     * 0 = 0
     * 1 = 1
     * 2 = 1
     * 3 = 2
     * 4 = 3
     */
    
    if(n < 2)
    {
        return n;
    }

    int prev = 0;
    int curr = 1;

    for(int i = 2; i <= n; ++i)
    {
        curr += prev;
        prev = curr - prev;
    }
    return curr;
}


int main()
{
    std::cout << "Fibonacci number: " << fibonacci(4) << std::endl;
    return (0);
}
