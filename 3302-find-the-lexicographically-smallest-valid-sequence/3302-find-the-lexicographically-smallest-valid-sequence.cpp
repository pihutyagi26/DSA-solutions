
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);

        // Build last[]
        int i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                --j;
            }
            --i;
        }

        vector<int> ans;
        bool usedMismatch = false;
        j = 0;

        for (i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                ++j;
            }
            else if (!usedMismatch &&
                     (j == m - 1 || i < last[j + 1])) {
                usedMismatch = true;
                ans.push_back(i);
                ++j;
            }
        }

        return (j == m) ? ans : vector<int>();
    }
};