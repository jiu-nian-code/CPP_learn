class Solution
{
public:
    int firstUniqChar(string s)
    {
        int arr[200] = { 0 };
        for (auto& e : s) arr[e]++;
        for (int i = 0; i < s.size(); ++i)
            if (arr[s[i]] == 1) return i;
        return -1;
    }
};

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int arr[200] = { 0 };
        for (auto& e : s) arr[e]++;
        for (int i = 0; i < s.size(); ++i)
            if (arr[s[i]] == 1) return i;
        return -1;
    }
};