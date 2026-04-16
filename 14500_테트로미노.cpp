    #include <algorithm>
    #include <iosfwd>
    #include <iostream>
    #include <list>
    #include <queue>
    #include <stdio.h>
    #include <vector>

    using namespace std;

    int board[501][501];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int n, m;
    int  draw(vector <vector <bool> > &poly)
    {
        int r, c;
        int sol  =0 ;
        
        for (int i = 0 ; i < 4 ; i++)
        {
            bool flag = true;
            for (int j = 0 ; j < 4 ; j++)
            {
                if (poly[i][j] )
                {
                    r = i;   
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        
        for (int i = 0 ; i < 4 ; i++)
        {
            bool flag = true;
            for (int j = 0 ; j < 4 ; j++)
            {
                if (poly[j][i] )
                {
                    c = i;
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }

        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < m ; j++)
            {
                int sum = 0;
                int count = 0;
                for (int k = r ; k < 4 ; k++)
                {
                    for (int l = c ; l < 4 ; l++)
                    {
                        if (poly[k][l])
                        {
                            int sum_r = i + k - r;
                            int sum_c = j + l - c;
                            
                            if (sum_r < 0 || sum_r >= n || sum_c < 0 || sum_c >= m) continue;
                            sum += board[i + k - r][j + l - c];

                            count++;
                        }
                    }
                }
                
                if (count == 4) sol = max(sol, sum);
            }
        }
        return sol;
    }
    void mirror1 (vector<vector<bool>> &poly)
    {
        vector<vector<bool>> temp(poly);
        for (int i = 0 ; i < 4 ; i++)
        {
            for (int j = 0 ; j < 4 ; j++)
            {
                poly[i][j] = temp[i][3 - j];
            }
        }
    }

void mirror2 (vector<vector<bool>> &poly)
    {
        vector<vector<bool>> temp(poly);
        for (int i = 0 ; i < 4 ; i++)
        {
            for (int j = 0 ; j < 4 ; j++)
            {
                poly[i][j] = temp[3 - i][j];
            }
        }
    }
    void lotate(vector<vector<bool>> &poly)
    {
        vector<vector<bool> > temp(poly);
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                poly[i][j] = temp[3 - j][i];
            }
        }
    }
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        
        vector<vector<bool>> poly1 = {{0, 0, 0, 1},
                            {0, 0, 0, 1},
                            {0, 0, 0, 1},
                            {0, 0, 0, 1}};
        vector<vector<bool>> poly2 = {{1, 1, 0, 0},
                            {1, 1, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0}};
        vector<vector<bool>> poly3 = {{1, 0, 0, 0},
                            {1, 0, 0, 0},
                            {1, 1, 0, 0},
                            {0, 0, 0, 0}};
        vector<vector<bool>> poly4= {{1, 0, 0, 0},
                            {1, 1, 0, 0},
                                {0, 1, 0, 0},
                            {0, 0, 0, 0}};
        vector<vector<bool>> poly5= {{1, 1, 1, 0},
                            {0, 1, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0 ,0}};
        
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> board[i][j];

        int sol = 0;

        for (int i = 0 ; i < 2 ; i++)
        {
            sol = max(sol, draw(poly1));
            lotate(poly1);
        }
        
        sol = max(sol, draw(poly2));
        
        for (int i = 0 ; i < 4 ; i++)
        {
            for (int j = 0 ; j < 2 ; j++)
            {
                sol = max(sol, draw(poly3));
                mirror1((poly3));
            }
            for (int j = 0 ; j < 2 ; j++)
            {
                sol = max(sol, draw(poly3));
                mirror2((poly3));
            }
            lotate(poly3);
            
        }
        
        for (int i = 0 ; i < 4 ; i++)
        {
            for (int j = 0 ; j < 2 ; j++)
            {
                sol = max(sol, draw(poly4));
                mirror1((poly4));
            }
            for (int j = 0 ; j < 2 ; j++)
            {
                sol = max(sol, draw(poly4));
                mirror2((poly4));
            }
            lotate(poly4);
        }
        
        for (int i = 0 ; i < 4 ; i++)
        {
            for (int j = 0 ; j < 2 ; j++)
            {
                sol = max(sol, draw(poly5));
                mirror1((poly5));
            }
            for (int j = 0 ; j < 2 ; j++)
            {
                sol = max(sol, draw(poly5));
                mirror2((poly5));
            }
            lotate(poly5);
        }

        cout << sol << "\n";
        
    }
            