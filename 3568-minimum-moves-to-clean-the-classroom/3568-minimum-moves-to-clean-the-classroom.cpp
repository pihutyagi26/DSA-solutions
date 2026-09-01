class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx = 0, sy = 0;
        int cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0) return 0;

        int target = (1 << cnt) - 1;

        vector<vector<vector<vector<bool>>>> vis(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        queue<array<int,4>> q;

        q.push({sx, sy, energy, 0});
        vis[sx][sy][energy][0] = true;

        int steps = 0;

        int dirs[5] = {-1, 0, 1, 0, -1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y, e, mask] = q.front();
                q.pop();

                if (mask == target) return steps;

                if (e == 0 && classroom[x][y] != 'R')
                    continue;

                if (e == 0)
                    e = energy;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dirs[k];
                    int ny = y + dirs[k + 1];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    if (classroom[nx][ny] == 'X')
                        continue;

                    int ne = e - 1;

                    int nmask = mask;

                    if (classroom[nx][ny] == 'R')
                        ne = energy;

                    if (id[nx][ny] != -1)
                        nmask |= (1 << id[nx][ny]);

                    if (!vis[nx][ny][ne][nmask]) {
                        vis[nx][ny][ne][nmask] = true;
                        q.push({nx, ny, ne, nmask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};