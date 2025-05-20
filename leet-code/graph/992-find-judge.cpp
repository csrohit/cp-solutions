#include <cstdio>
#include <vector>


using std::vector;

int findJudge(int n, vector<vector<int>>& trust)
{
    vector<int> trustedBy(n+1, 0);

    for (const auto& relation: trust)
    {
        trustedBy[relation[0]]--;
        trustedBy[relation[1]]++;
    }

    for(const int person: trustedBy)
    {
        if (person == (n - 1))
        {
            return true;
        }
    }


    return -1;
}


int main()
{
    



    return 0;
}
