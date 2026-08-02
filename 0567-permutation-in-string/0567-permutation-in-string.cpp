class Solution {
public:
bool isfreq(int freq[], int windfreq[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != windfreq[i])
        {
            return false;
        }
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
      int freq[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'a']++;
    }
    int windsize = s1.length();
    for (int i = 0; i < s2.length(); i++)
    {
        int mindidx = 0, idx = i;
        int windfreq[26] = {0};
        while (idx < s2.length() && mindidx < windsize)
        {
            windfreq[s2[idx] - 'a']++;
            mindidx++;
            idx++;
        }
        if (isfreq(freq, windfreq))
    {
        return true;
    }
    }

    
    return false;  
    }
};