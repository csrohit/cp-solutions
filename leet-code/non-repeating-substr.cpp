#include <cstdio>
#include <string>

using namespace std;

int lengthLongestSubstring(string s){
    int m[128];

    fill_n(m, 128, -1);
    int start = -1, max_len = 0;

    for (uint8_t i = 0; i < s.length(); i++)
    {
        if(m[s[i]] > start){
            start = m[s[i]];
        }
        m[s[i]] = i;
        max_len = max(max_len, i - start);
    }
    return max_len;
}



int main(){

    string str = "abcabcbb";

    int res = lengthLongestSubstring(str);

    printf("Length of longest substring: %d\n", res);


    return 0;
}