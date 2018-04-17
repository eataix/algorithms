#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  public:
    vector<int> anagramMappings(vector<int> &A, vector<int> &B)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < B.size(); ++i)
        {
            m[B[i]] = i;
        }
        vector<int> res(A.size());
        for (int i = 0; i < A.size(); ++i)
        {
            res[i] = m[A[i]];
            cout << res[i] << endl;
        }
        return res;
    }
};

#ifdef DEBUG
int main()
{
    Solution sol;
    vector<int> v1{12, 28, 46, 32, 50};
    vector<int> v2{50, 12, 32, 46, 28};
    sol.anagramMappings(v1, v2);
}
#endif
