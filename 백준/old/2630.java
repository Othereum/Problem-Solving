import java.util.Scanner;

public class Main {
    static class Result {
        int white;
        int blue;

        public Result(int white, int blue) {
            this.white = white;
            this.blue = blue;
        }
    }

    static Scanner sc = new Scanner(System.in);
    static boolean[][] paper;

    public static void main(String[] args) {
        int n = sc.nextInt();
        paper = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                paper[i][j] = sc.nextInt() != 0;
            }
        }

        var result = solve(0, 0, n);
        System.out.println(result.white);
        System.out.println(result.blue);
    }

    static Result solve(int x, int y, int len) {
        if (len <= 0) return new Result(0, 0);
        if (len == 1) {
            var isBlue = paper[x][y];
            return new Result(isBlue ? 0 : 1, isBlue ? 1 : 0);
        }

        var half = len / 2;
        var r1 = solve(x, y, half);
        var r2 = solve(x + half, y, half);
        var r3 = solve(x, y + half, half);
        var r4 = solve(x + half, y + half, half);

        var result = new Result(
            r1.white + r2.white + r3.white + r4.white,
            r1.blue + r2.blue + r3.blue + r4.blue
        );

        if (result.white == 4 && result.blue == 0) {
            return new Result(1, 0);
        }
        if (result.white == 0 && result.blue == 4) {
            return new Result(0, 1);
        }

        return result;
    }
}
