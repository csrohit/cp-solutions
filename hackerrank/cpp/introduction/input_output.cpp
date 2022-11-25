#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int sum = 0;
    for(int i=0; i<3; i++){
        int u = 0;
        scanf("%d",&u);
        sum += u;
    }
    printf("%d", sum);
    return 0;
}

