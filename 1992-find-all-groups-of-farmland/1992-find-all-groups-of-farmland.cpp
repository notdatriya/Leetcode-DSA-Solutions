class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        int n = land.size();
        int m = land[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(land[i][j] == 1 && !visited[i][j]) {
                    int small_x = i, small_y = j;
                    int largest_x = i, largest_y = j;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    
                    while(!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        
                        visited[r][c] = true;
                        
                        for(int k = 0; k < 4; k++) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            
                            if(nr >= 0 && nr < n && nc >= 0 && nc < m && land[nr][nc] == 1 && !visited[nr][nc]) {
                                q.push({nr, nc});
                                visited[nr][nc] = true;
                                small_x = min(small_x, nr);
                                small_y = min(small_y, nc);
                                largest_x = max(largest_x, nr);
                                largest_y = max(largest_y, nc);
                            }
                        }
                    }
                    result.push_back({small_x, small_y, largest_x, largest_y});
                }
            }
        }
        
        return result;
    }
};
