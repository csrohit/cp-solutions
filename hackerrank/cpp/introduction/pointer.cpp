#include <stdio.h>

void update(int *a,int *b) {
    int sum = *a + *b;
    if(*a < *b){
        *b -= *a;
    }else{
        *b = *a - *b;
    }
    *a = sum;
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
