
#include<string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int map_s[128] = {0};
        int map_t[128] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            if (map_s[s[i]] == 0 && map_t[t[i]] == 0)
            {
                map_s[s[i]] = t[i];
                map_t[t[i]] = s[i];

            }else{
                if(map_s[s[i]] != t[i] || map_t[t[i]] != s[i])
                    return false;
            }
            
        }
        return true;
        
        
    }
};


int main(){
    Solution sol;
    sol.isIsomorphic("badc", "baba");

}