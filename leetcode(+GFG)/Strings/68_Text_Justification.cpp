// https://leetcode.com/problems/text-justification/description/

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int i = 0;
        int n = words.size();
        int cnt = 0;
        while (i < n)
        {
            int lenWords = 0, stLength = 0;
            int st = i;
            lenWords += words[i++].length();
            stLength = lenWords;
            while (i < n && (words[i].length() + 1) <= (maxWidth - stLength))
            {
                // cout << i << " in " << cnt << endl;
                lenWords += words[i].length();
                stLength += (words[i].length() + 1);
                i++;
            }
            int numWords = i - st;
            int numSpaces = maxWidth - lenWords;
            if (numWords == 1)
            {
                string s = words[st];
                int l = maxWidth - s.length();
                while (l--)
                {
                    s += " ";
                }
                ans.push_back(s);
            }

            else if (i == n)
            {
                string s = words[st];
                for (int l = st + 1; l < i; l++)
                {
                    s += (" " + words[l]);
                }
                int left = maxWidth - s.length();
                for (int k = 0; k < left; k++)
                {
                    s += " ";
                }
                ans.push_back(s);
            }

            else
            {
                string s = "";
                int numSpacesBetween = numSpaces / (numWords - 1);
                int cnt1 = numSpaces % (numWords - 1);

                string space = "";
                for (int l = 0; l < numSpacesBetween; l++)
                {
                    space += " ";
                }

                s += words[st];
                for (int l = st + 1; l < i; l++)
                {
                    s += space;
                    if (cnt1)
                    {
                        s += " ";
                        cnt1--;
                    }
                    s += words[l];
                }
                ans.push_back(s);
            }

            cnt++;
        }
        return ans;
    }
};
