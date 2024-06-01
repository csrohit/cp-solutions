#include "cstdio"
#include <vector>


double findMedian(const std::vector<int> &num1, const std::vector<int> & num2)
{
    if(num1.size() > num2.size())
    {
        return findMedian(num2, num1);
    }

    const int n1 = num1.size();
    const int n2 = num2.size();

    int l = 0;
    int r = n1;

    while (l <= r)
    {
        const int m1 = (l + r) / 2;
        const int m2 = (n1 + n2)/2 - m1;

        const int l1 = m1 == 0 ? INT_MIN :num1[m1 - 1];
        const int l2 = m2 == 0 ? INT_MIN :num2[m2 - 1];

        const int r1 = m1 == n1 ? INT_MAX : num1[m1];
        const int r2 = m2 == n2 ? INT_MAX : num2[m2];

        // properly deviced
        if (l1 <= r2 && l2 <= r1)
        {
            if ((n1+n2) % 2)
            {
                // odd case
                return std::min(r1, r2);
            }
            else
            {
                // even case
                return ((double)(std::max(l1 , l2) + std::min(r2 , r1)))/2;   
            }
        }
        else if (l1 > r2)
        {
            r = m1 - 1;
        }
        else
        {
            l = m1 + 1;
        }
    }
    
    return 0.0;
}

int main()
{
    std::vector<int> num2 {};
    std::vector<int> num1 {2};
    
    printf("Median: %.2lf\n", findMedian(num2, num1));
}
