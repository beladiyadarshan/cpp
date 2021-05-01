import java.util.*;
public class GFG {

    // Funtion to selct m elements
    // having maximum sum
    public static long
    mElementsWithMaxSum(long[][] matrix,
                        int M, int block,
                        long[][] dp)
    {
        // Base case
        if (block == matrix.length)
            return 0;

        // If precomputed subproblem occurred
        if (dp[block][M] != -1)
            return dp[block][M];

        // Either skip the current row
        long ans
            = mElementsWithMaxSum(matrix, M,
                                  block + 1, dp);

        // Iterate through all the possible
        // segments of current row
        for (int i = 0;
             i < matrix[block].length; i++) {
            for (int j = i;
                 j < matrix[block].length; j++) {

                // Check if it is possible to select
                // elements from i to j
                if (j - i + 1 <= M) {

                    // Compuete the sum of i to j as
                    // calculated
                    ans = Math.max(
                        ans,
                        matrix[block][j]
                            - ((i - 1) >= 0
                                   ? matrix[block][i - 1]
                                   : 0)
                            + mElementsWithMaxSum(
                                  matrix, M - j + i - 1,
                                  block + 1, dp));
                }
            }
        }

        // Store the computed answer and return
        return dp[block][M] = ans;
    }

    // Function to precompute the prefix sum
    // for every row of the matrix
    public static void
    preComputing(long[][] matrix, int N)
    {
        // Preprocessing to calculate sum from i to j
        for (int i = 0;
             i < N; i++) {
            for (int j = 0;
                 j < matrix[i].length; j++) {
                matrix[i][j]
                    = (j > 0
                           ? matrix[i][j - 1]
                           : 0)
                      + matrix[i][j];
            }
        }
    }

    // Utility function to selct m elements having
    // maximum sum
    public static void
    mElementsWithMaxSumUtil(long[][] matrix,
                            int M, int N)
    {
        // Preprocessing step
        preComputing(matrix, N);

        // Initialize dp array with -1
        long dp[][] = new long[N + 5][M + 5];
        for (long i[] : dp)
            Arrays.fill(i, -1);

        // Stores maximum sum of M elements
        long sum = mElementsWithMaxSum(matrix, M,
                                       0, dp);

        // Print the sum
        System.out.print(sum);
    }

    // Driver Code
    public static void main(String args[])
    {
        // Given N
        int N = 3;

        // Given M
        int M = 4;

        // Given matrix
        long[][] matrix
            = { { 2, 3, 5 }, { -1, 7 }, { 8, 10 } };

        // Function Call
        mElementsWithMaxSumUtil(matrix, M, N);
    }
}