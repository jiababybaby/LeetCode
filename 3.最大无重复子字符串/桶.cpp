class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        vector<int> vec(128, -1);
        while (end < sSize)
        {
            char tmpChar = s[end];
            //仅当s[start,end) 中存在s[end]时更新start
            if (vec[int(tmpChar)] >= start)
            {
                start = vec[int(tmpChar)] + 1;
                length = end - start;
            }
            vec[int(tmpChar)] = end;

            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
};