#include <bits/stdc++.h>
using namespace std;
/*support: +(two non-negative int)
- (two non-negative int and first int is bigger than second one)
* (two non-negative int)
/ (two positive int and divisor MUST could be represented by a 32bit int)
*/
struct BIGINT
{
    // separate the each digit of the number into array nums and reverse it
    int nums[1024], len;
    // traditional print function without reloading ostream
    void print()
    {
        reverse(nums, nums + len);
        int start = 0;
        while (start < len - 1 && !nums[start])
            start++;
        for (int i = start; i < len; i++)
            cout << nums[i];
        reverse(nums, nums + len);
    }
    // default construct function with a void value
    BIGINT()
    {
        memset(nums, 0, sizeof(nums));
        len = 0;
    }
    // initial the struct by passing a string
    BIGINT(string s)
    {
        memset(nums, 0, sizeof(nums));
        len = s.length();
        for (int i = 0; i < s.length(); i++)
            nums[i] = s[s.length() - 1 - i] - '0';
    }

    bool operator<(BIGINT b)
    {
        int start1 = 0, start2 = 0;
        while (start1 < len - 1 && !nums[start1])
            start1++;
        while (start2 < b.len - 1 && !b.nums[start2])
            start2++;
        if (len - start1 != b.len - start2)
            return len - start1 < b.len - start2;
        else
        {
            for (int i = start1, j = start2; i < len; i++, j++)
            {
                return nums[i] < b.nums[j];
            }
        }
    }
};

BIGINT operator+(BIGINT a, BIGINT b)
{
    BIGINT ans;
    ans.len = max(a.len, b.len);
    int carry = 0;
    for (int i = 0; i < ans.len; i++)
    {
        ans.nums[i] += a.nums[i] + b.nums[i] + carry;
        carry = ans.nums[i] / 10;
        ans.nums[i] %= 10;
    }
    if (carry)
        ans.nums[ans.len++] += carry;
    return ans;
}

BIGINT operator-(BIGINT a, BIGINT b)
{
    BIGINT ans;
    ans.len = max(a.len, b.len);
    for (int i = 0; i < ans.len; i++)
    {
        ans.nums[i] = a.nums[i] - b.nums[i];
        if (ans.nums[i] < 0)
        {
            ans.nums[i] += 10;
            a.nums[i + 1]--;
        }
    }
    /*add adtional function to cut the leading zero when print function doesn't do that
    while (ans.len > 1 && ans.nums[ans.len - 1] == 0)
        ans.len--;
    */
    return ans;
}

BIGINT operator*(BIGINT a, BIGINT b)
{
    BIGINT ans;
    ans.len = a.len + b.len;
    for (int i = 0; i < a.len; i++)
    {
        for (int j = 0; j < b.len; j++)
        {
            ans.nums[i + j] += a.nums[i] * b.nums[j];
        }
    }
    int carry = 0;
    for (int i = 0; i < ans.len; i++)
    {
        ans.nums[i] += carry;
        carry = ans.nums[i] / 10;
        ans.nums[i] %= 10;
    }
    while (ans.nums[ans.len])
        ans.len++;
    return ans;
}

BIGINT operator/(BIGINT a, int b)
{
    BIGINT ans;
    ans.len = a.len;
    reverse(a.nums, a.nums + a.len);
    int x = 0;
    for (int i = 0; i < a.len; i++)
    {
        x = x * 10 + a.nums[i];
        ans.nums[i] = x / b;
        x %= b;
    }
    reverse(ans.nums, ans.nums + ans.len);
    return ans;
}
int main()
{

    return 0;
}
