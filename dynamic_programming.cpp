#include <iostream>
#include <vector>
using namespace std;

/**
*   Describe:
*               Maximum continuous subsequence sum
*   State Transition Equation:
*               sum[i] = max{data[i], data[i] + sum[i - 1]}
*   input:      {-2, 11, -4, 13, -5, -2}
*   output:     {11, -4, 13} = 20
***/

int max_sequence(vector<int> data)
{
    if(data.size() == 0)
        return 0;
    int sum_temp = 0;
    int result = 0;
    for(int i = 0; i < data.size(); i++)
    {
        sum_temp = sum_temp + data[i];
        sum_temp = max(data[i], sum_temp);
        if(sum_temp > result)
            result = sum_temp;
    }
    return result;
}

/*int main()
{
    vector<int> data = {-2, 11, -4, 13, -5, -2};
    int result = max_sequence(data);
    cout<<result<<endl;
}
*/

/**
*   Describe:   longest common subsequence
*   Statue Transition Equation:
*               if a[i] = b[j];  result[i][j] = result[i-1][j-1] +1;
*               if a[i] != b[j], result[i][j] = max{result[i-1][j], result[i][j-1]};
*               if i = 0 || j = 0, result[i][j] = 0;
*   input:  a[] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'}, b[] = {'B', 'D', 'C', 'A', 'B', 'A'}
*   output: "BDAB", "BCAB", "BCBA"
**/

    void lcs(string a, string b, vector<string> result)
    {
        int len_a = a.size();
        int len_b = b.size();

    }
