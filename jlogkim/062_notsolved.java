import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.*;

import java.io.BufferedInputStream;

/*
3 3
101
010
101
* */
class Pair{
    int r,c;
    public Pair(int r,int c){this.r=r; this.c=c;}
}
public class Main {
    public static int way[][] = {{1,0},{-1,0},{0,1},{0,-1}};
    public static void main(String args[]) {
        try {
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
            String splitted[];
            splitted = bf.readLine().split(" ");
            int n = Integer.parseInt(splitted[0]);
            int m = Integer.parseInt(splitted[1]);
            int map[][] = new int[n][m];
            String line;
            for (int r = 0; r < n; r++) {
                line = bf.readLine();
                for (int c = 0; c < m; c++) {
                    map[r][c] = line.charAt(c) - '0'; //map is with only 1 and 0
                }
            }
            Map<Integer,Integer> team = new HashMap<>();

            Stack<Pair> dfs = new Stack<>();
            Set<Pair> walls = new HashSet<>();

            int teamnumb = 2;

            Pair p;
            int nc, nr;
            int numb;
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    if (map[r][c] == 0) {
                        dfs.add(new Pair(r, c));
                        map[r][c] = teamnumb;
                        numb=1;
                        team.put(teamnumb,numb);
                        numb++;
                        while (!dfs.isEmpty()) {
                            p = dfs.pop();
                            for (int i = 0; i < 4; i++) {
                                nr = p.r + way[i][0];
                                nc = p.c + way[i][1];
                                if (nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] == 0) {
                                    map[nr][nc] = teamnumb;
                                    team.replace(teamnumb,numb);
                                    numb++;
                                    dfs.add(new Pair(nr, nc));
                                }
                            }
                        }
                        teamnumb++;
                    } else if (map[r][c] == 1) {
                        walls.add(new Pair(r, c));
                    }
                }
            }

            int ans;
            int ansmap[][] = new int[n][m];

            Set<Integer> teamset = new HashSet<>();

            for (Pair wall : walls) {
                ans = 1;
                teamset.clear();
                for (int i = 0; i < 4; i++) {
                    nr = wall.r + way[i][0];
                    nc = wall.c + way[i][1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] >= 2) {
                        teamset.add(map[nr][nc]);
                    }
                }
                for (int s : teamset) {
                    ans += team.get(s);
                }
                ansmap[wall.r][wall.c] = ans % 10;
            }

            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    System.out.print(ansmap[r][c]);
                }
                System.out.println();
            }
        }catch(IOException e){
            System.out.println(e.toString());
        }
    }
}
