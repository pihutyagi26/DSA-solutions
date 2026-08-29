
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> v; // {value, original_index}
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        vector<int> ans(n);

        int i = 0;
        while (i < n) {
            vector<int> indices;
            vector<int> values;

            int j = i;

            // Form one connected group
            while (j + 1 < n && v[j + 1].first - v[j].first <= limit) {
                j++;
            }

            // Collect indices and values of this group
            for (int k = i; k <= j; k++) {
                values.push_back(v[k].first);
                indices.push_back(v[k].second);
            }

            sort(indices.begin(), indices.end());

            // Assign smallest values to smallest indices
            for (int k = 0; k < values.size(); k++) {
                ans[indices[k]] = values[k];
            }

            i = j + 1;
        }

        return ans;
    }
};