class Solution
{
    int arr[26] = { 0 };
public:
    int characterReplacement(string s, int k)
    {
        vector<int> count(26, 0);
        int left = 0;
        int maxCount = 0;
        int result = 0;
        for (int right = 0; right < s.size(); ++right)
        {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);
            while (right - left + 1 - maxCount > k) // 恢复到记录的最大长度，搏下一个能更新maxcount
            {
                count[s[left++] - 'A']--;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        std::priority_queue<int> pq;
        for (auto& e : nums)
            pq.push(e);
        int i = pq.top();
        pq.pop();
        int j = pq.top();
        return (i - 1) * (j - 1);
    }
};