import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


public class SolutionC {
	
	// For example, "B-small"
	private static final String FILENAME = "Clarge1";
	
	private void solveCase(int caseNumber, BufferedReader rd, PrintWriter wr) throws Exception {
		String line = rd.readLine();
		String[] data = line.split(" ");
		long A = Long.parseLong(data[0]);
		long B = Long.parseLong(data[1]);
		
		long count = 0;
		for(long i = 0; i <= 10000000; i++) {
			long square = i * i;
			if(square < A) continue;
			if(square > B) break;
			if(isPalindrome(i) && isPalindrome(square)) {
				count++;
			}
		}
		
		System.out.println("Case #" + caseNumber + ": " + count);
		wr.println("Case #" + caseNumber + ": " + count);
	}
	
	public SolutionC() {
		BufferedReader rd = null;
		PrintWriter wr = null;
		int numCases = 0;
		try {
			rd = new BufferedReader(new FileReader(FILENAME + ".in"));
			wr = new PrintWriter(new FileWriter(FILENAME + ".out"));
			numCases = Integer.parseInt(rd.readLine());
		} catch (Exception e) {
			System.out.println("Error reading file");
			e.printStackTrace();
			return;
		}
		
		for(int i = 1; i <= numCases; i++) {
			try {
				solveCase(i, rd, wr);
			} catch (Exception e) {
				System.out.println("Exception in Case " + i + ". Stack trace:");
				e.printStackTrace();
				break;
			}
		}
		
		try {
			rd.close();
			wr.close();
		} catch (Exception e) {
			System.out.println("Error closing file");
			e.printStackTrace();
			return;
		}
	}
	
	public static void main(String[] args) {
		new SolutionC();
	}
	
	private static boolean isPalindrome(long num) {
		String str = Long.toString(num);
		int length = str.length();
		int halfLength = length / 2;
		for(int i = 0; i < halfLength; i++) {
			if(str.charAt(i) != str.charAt(length - i - 1)) return false;
		}
		return true;
	}
}
