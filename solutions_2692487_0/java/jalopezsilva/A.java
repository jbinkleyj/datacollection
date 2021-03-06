package problems_round2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class A {

	public static void main(String[] args) throws Exception {

		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

		int numCases = Integer.parseInt(bf.readLine());

		for (int i = 1; i <= numCases; i++) {

			String[] pieces = bf.readLine().split(" ");
			int initialSize = Integer.parseInt(pieces[0]);
			int numMotes = Integer.parseInt(pieces[1]);
			int[] motes = new int[numMotes];

			String sizes = bf.readLine();

			String[] motes_string = sizes.split(" ");
			
			for (int j = 0; j < motes_string.length; j++) {
				motes[j] = Integer.parseInt(motes_string[j]);
			}

			System.out.println("Case #" + i + ": " + simulateOsmos(initialSize, motes));
		}
	}

	public static int simulateOsmos(int initialSize, int[] motes) {

		int response = 0;

		Arrays.sort(motes);

		int[] minimumMoves = new int[motes.length + 1];
				
		boolean possible = true;
		int maxState = minimumMoves.length;
		
		for (int i = 0; i < motes.length && possible ; i++) {

			int sumOperations = 0;
			while (initialSize <= motes[i] && possible) {
				sumOperations++;
				initialSize += initialSize - 1;
				
				if( initialSize == 1){
					possible = false;
					maxState = i + 1;
				}
			}

			minimumMoves[i+1] = (i > 0) ? minimumMoves[i] : 0;
			minimumMoves[i+1] += sumOperations;

			initialSize += motes[i];

		}
		

		int min = Integer.MAX_VALUE;

		for (int i = 0; i < minimumMoves.length && i < maxState; i++) {

			int current = minimumMoves[i] + motes.length - i;

			if (current < min) {
				min = current;
			}
		}

		return min;
	}

}
