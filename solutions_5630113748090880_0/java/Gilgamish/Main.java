import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int i = 1; i <= t; i++) {
            int length = scanner.nextInt();
            int[][] c = new int [2*length-1][length];
            int[] p = new int[2500];
            for (int j = 0; j < 2500; j++) {
                p[j] = 0;
            }
            for (int j = 0; j < 2*length-1; j++) {
                for (int k = 0; k < length; k++) {
                    c[j][k] = scanner.nextInt();
                    p[c[j][k]] ++;
                }
            }
            int[] pc = new int[length];
            int x = 0;
            for (int j = 0; j < 2500; j++) {
                if (p[j] %2 != 0) {
                    pc[x++] = j;
                }
            }
            Arrays.sort(pc);
            System.out.print("Case #" + i + ":");
            for (int j = 0; j < length; j++) {
                System.out.print(" " + pc[j]);
            }
            System.out.println("");
        }
    }

}

