import java.io.IOException;
import java.util.Locale;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "input.txt";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("a.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    private String removeDupl(String arg, int[]countDupl) {
        StringBuilder sb = new StringBuilder();
        char prev = (char)-1;
        int i=-1;
        for(Character c:arg.toCharArray()) {
            if(c != prev) {
                ++i;
                countDupl[i]++;
                sb.append(c);
                prev = c;
            }
            else {
                countDupl[i]++;
            }
        }
        return sb.toString();
    }
    public void solve(int testNumber, InputReader in, PrintWriter out) {
             int N =in.nextInt();
        String[] S = new String[N];
        for(int i=0;i<N;i++) {
            S[i] = in.nextToken();
        }
        String [] nonDupl = new String[N];
        int countDupl[][] = new int[N][101];
        for(int i=0;i<N;i++) {
            nonDupl[i] = removeDupl(S[i],countDupl[i]);
        }

        for(int i=0;i<N;i++) {
            for(int j=i+1;j<N;j++) {
                if(!nonDupl[i].equals(nonDupl[j])) {
                    out.println("Case #"+testNumber+": Fegla Won");
                    return;
                }
            }
        }
        int bestCutSum = 0;
        for(int idx = 0;idx<nonDupl[0].length();idx++) {
            // find min possible
            int MinCut = Integer.MAX_VALUE;
            int MaxCut = Integer.MIN_VALUE;
            for(int i=0;i<N;i++) {
                if(countDupl[i][idx]<MinCut)
                     MinCut =  countDupl[i][idx];
            }
            for(int i=0;i<N;i++) {
                if(countDupl[i][idx]>MaxCut)
                    MaxCut =  countDupl[i][idx];
            }
            int bestCut = Integer.MAX_VALUE;
            for(int howMany = MinCut;howMany<=MaxCut;howMany++) {
                 int curCut = 0;
                for(int i=0;i<N;i++) {
                    curCut+= Math.abs(countDupl[i][idx]-howMany);
                }
                if(curCut<bestCut) {
                    bestCut = curCut;
                }
            }
            bestCutSum+=bestCut;
        }

        out.println("Case #"+testNumber+": "+bestCutSum);

    }
}

class InputReader {

    private InputStream stream;
    int curCharIndex = 0;
    int charsInBuf = 0;
     byte buf[] = new byte[16*1024];

    public InputReader(InputStream stream) {
        this.stream = stream;
    }


    public int readChar() {

        if (curCharIndex >= charsInBuf) {
            curCharIndex = 0;
            try {
                charsInBuf = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (charsInBuf <= 0)
                return -1;
        }
        return buf[curCharIndex++];
    }


    public int nextInt() {

        int c;
        do {
            c = readChar();
        }while(isWhitespace(c));

        int sign = 1;
        if (c == '-') {
            c = readChar();
            sign = -1;

        }
        int res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = readChar();
        } while (!isWhitespace(c) && c!=-1);
        return sign * res;
    }


    public String nextToken() {
        int c;
        do {
            c = readChar();
        }while(isWhitespace(c));

        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = readChar();
        } while (!isWhitespace(c) && c!=-1);
        return res.toString();
    }

    /*
    * For the purpose of compatibilty with Chelper Chrome extension
     */

    public String next() {
        return nextToken();
    }


    private boolean isWhitespace(int c) {
        return  c==' ' || c=='\n'|| c=='\r' || c=='\t';
    }
}


