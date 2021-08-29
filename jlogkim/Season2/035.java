class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int max_col[] = new int[grid.length];
        int max_row[] = new int[grid[0].length];
        
        int sum=0;
        for(int r=0;r<grid.length;r++){
            for(int c=0;c<grid[0].length;c++){
                if(grid[r][c]>max_col[c])max_col[c]=grid[r][c];
                if(grid[r][c]>max_row[r])max_row[r]=grid[r][c];
            }
        }
        int min;
        for(int r=0;r<grid.length;r++){
            for(int c=0;c<grid[0].length;c++){
                min=Math.min(max_col[c],max_row[r]);
                if(min>grid[r][c])sum+=(min-grid[r][c]);
            }
        }
        return sum;
    }
}