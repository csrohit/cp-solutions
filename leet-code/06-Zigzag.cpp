#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convert(string s, int numRows)
{
    if (numRows < 2)
    {
        return s;
    }

    string ans;

    int num = (numRows - 1) * 2;
    for (int r = 0; r < numRows; ++r)
    {
        int increment = 2 * r; 
        for (int idx = r; idx < s.size();)
        {
            ans.push_back(s[idx]);
            
            if (increment == 0 || increment == num)
            {
                idx += num;
            }
            else
            {
                increment = num - increment;
                idx += increment;
            }
        }
    }


    return ans;
}


int main()
{
    cout << convert("P", 5) << endl;

}
