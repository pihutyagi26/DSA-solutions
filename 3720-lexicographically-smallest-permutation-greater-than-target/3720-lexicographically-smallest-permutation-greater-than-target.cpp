
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);

        for (char c : s) cnt[c - 'a']++;

        string best = "";

        vector<int> rem = cnt;
        string prefix = "";

        int n = s.size();

        for (int i = 0; i < n; i++) {

            // Try making the first difference at position i
            for (int ch = (target[i] - 'a') + 1; ch < 26; ch++) {
                if (rem[ch] == 0) continue;

                vector<int> tmp = rem;
                tmp[ch]--;

                string candidate = prefix;
                candidate.push_back(char('a' + ch));

                for (int k = 0; k < 26; k++) {
                    candidate.append(tmp[k], char('a' + k));
                }

                if (best.empty() || candidate < best)
                    best = candidate;

                break; // smallest possible > target[i]
            }

            // Continue matching target[i]
            int cur = target[i] - 'a';
            if (rem[cur] == 0) break;

            rem[cur]--;
            prefix.push_back(target[i]);
        }

        return best;
    }
};