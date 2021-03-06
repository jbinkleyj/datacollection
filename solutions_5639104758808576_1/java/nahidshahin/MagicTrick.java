import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.BufferedOutputStream;
import java.io.FileOutputStream;


public class MagicTrick {
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		//System.setIn(new FileInputStream("A-large-attempt0.in"));
		//System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream("MagicTrick_Large.out")), true));
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int totalCaseNumber = Integer.parseInt( reader.readLine() );
		for(int caseNo=1 ; caseNo<=totalCaseNumber ; caseNo++ ) {
			String line = reader.readLine();
			String[] part = line.split(" ");
			char[] chrs = part[1].toCharArray();
			int audCount = 0;
			int extraNeed = 0;
			int i = 0;
			for( char ch : chrs ) {
				int audNo = ch - '0';
				if( audNo > 0 ) {
					if( i > audCount ) {
						int diff = i - audCount;
						extraNeed += diff;
						audCount += diff + audNo ;
					} else {
						audCount += audNo;
					}
				}
				i++;
			}
			
			System.out.println("Case #" + caseNo + ": " + extraNeed);
		}
		reader.close();
	}
}
