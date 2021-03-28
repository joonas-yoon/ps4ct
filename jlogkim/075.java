class Solution {
    public void rotate(int[][] matrix) {
        //(r,c) -> (c, n-1-r)
        int n = matrix.length;
        int tmp;
        for(int r=0;r<n/2;r++){
            for(int c=r;c<(n-1-r);c++){
                tmp=matrix[n-1-c][r];
                matrix[n-1-c][r]=matrix[n-1-r][n-1-c];
                matrix[n-1-r][n-1-c]=matrix[c][n-1-r];
                matrix[c][n-1-r]=matrix[r][c];
                matrix[r][c]=tmp;
            }
        }
    }
}