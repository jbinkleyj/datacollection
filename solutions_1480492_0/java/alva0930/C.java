import java.io.*;
import java.util.*;
import java.math.*;

class Car implements Comparable
{
	public final int speed;
	public final int position;

	public Car(int s, int p) {speed= s; position = p;}
	public int compareTo(Object o) {Car c = (Car)o; return (0 != (position - c.position)) ? (position - c.position) : (speed - c.speed);}
	public String toString() {return "(" + speed + "," + position + ")";}
}

class C
{
	private static final boolean DEBUG_ON = true;
	private static final boolean ECHO_ON = true;

	private static BufferedReader input;
	private static BufferedWriter output;

	private static final BigInteger BIG0 = BigInteger.valueOf(0);
	private static final BigInteger BIG1 = BigInteger.valueOf(1);
	private static final BigInteger BIG2 = BigInteger.valueOf(2);
	private static final BigInteger BIG3 = BigInteger.valueOf(3);
	private static final BigInteger BIG4 = BigInteger.valueOf(4);
	private static final BigInteger BIG5 = BigInteger.valueOf(5);
	private static final BigInteger BIG6 = BigInteger.valueOf(6);
	private static final BigInteger BIG7 = BigInteger.valueOf(7);
	private static final BigInteger BIG8 = BigInteger.valueOf(8);
	private static final BigInteger BIG9 = BigInteger.valueOf(9);
	private static final BigInteger BIG10 = BigInteger.valueOf(10);

	private static final int INF = Integer.MAX_VALUE / 2;
	private static final int MOD = 10007;

	public static void main(String[] args)
	{
		try
		{
			input = new BufferedReader(new FileReader(args[0]  + ".in"));
			output = new BufferedWriter(new FileWriter(args[0] + ".out"));

			String line = input.readLine();
			int testcases = getInt(line, 0);

			for (int testcase = 1; testcase <= testcases; testcase++)
			{
				line = input.readLine();
				int N = getInt(line, 0);

				Car[] car = new Car[N];
				for (int i = 0; i < N; i++)
				{
					line = input.readLine();
					car[i] = new Car(getInt(line, 1), getInt(line, 2));
				}
				Arrays.sort(car);

				double time = Double.POSITIVE_INFINITY;

				for (int i = 0; i < N; i++) for (int j = 0; j < N && j != i; j++) for (int k = 0; k < N && k != i && k != j; k++)
				{
					Car c1 = car[i];
					Car c2 = car[j];
					Car c3 = car[k];

					if (c2.position >= (c1.position + 5) && c2.speed >= c1.speed) {continue;}
					if (c2.position <= (c1.position - 5) && c2.speed <= c1.speed) {continue;}
					if (c3.position >= (c1.position + 5) && c3.speed >= c1.speed) {continue;}
					if (c3.position <= (c1.position - 5) && c3.speed <= c1.speed) {continue;}

					double time2b = Double.POSITIVE_INFINITY;
					double time2e = Double.POSITIVE_INFINITY;
					double time3b = Double.POSITIVE_INFINITY;
					double time3e = Double.POSITIVE_INFINITY;
					double c2position = c2.position - c1.position;
					double c3position = c3.position - c1.position;

					if (c2.speed == c1.speed)
					{
						if (Math.abs(c2position) < 5) {time2b = 0;}
					}
					else if (c2.speed > c1.speed)
					{
						time2b = Math.max(0, (-5 - c2position) / (c2.speed - c1.speed));
						time2e = Math.max(0, (5 - c2position) / (c2.speed - c1.speed));
					}
					else
					{
						time2b = Math.max(0, (5 - c2position) / (c2.speed - c1.speed));
						time2e = Math.max(0, (-5 - c2position) / (c2.speed - c1.speed));
					}

					if (c3.speed == c1.speed)
					{
						if (Math.abs(c3position) < 5) {time3b = 0;}
					}
					else if (c3.speed > c1.speed)
					{
						time3b = Math.max(0, (-5 - c3position) / (c3.speed - c1.speed));
						time3e = Math.max(0, (5 - c3position) / (c3.speed - c1.speed));
					}
					else
					{
						time3b = Math.max(0, (5 - c3position) / (c3.speed - c1.speed));
						time3e = Math.max(0, (-5 - c3position) / (c3.speed - c1.speed));
					}

					if (time3b >= time2e || time2b >= time3e) {continue;}
					else
					{
						if (c3.speed > c2.speed)
						{
							double p23 = c2.position - c3.position;
							double s32 = c3.speed - c2.speed;
							double hit = Math.max(0, (p23 - 5) / s32);
							time = Math.min(time, hit);
						}
						if (c3.speed < c2.speed)
						{
							double p32 = c3.position - c2.position;
							double s23 = c2.speed - c3.speed;
							double hit = Math.max(0, (p32 - 5) / s23);
							time = Math.min(time, hit);
						}
					}
				}

				String result = "Case #" + testcase + ": " + ((Double.POSITIVE_INFINITY == time) ? "Possible" : time);
				output(result);
			}

			input.close();
			output.close();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}

	public static int getInt(String line, int index) {return Integer.parseInt(getString(line, index));}
	public static long getLong(String line, int index) {return Long.parseLong(getString(line, index));}
	public static double getDouble(String line, int index) {return Double.parseDouble(getString(line, index));}
	public static String getString(String line, int index)
	{
		line = line.trim();
		while (index > 0) {line = line.substring(line.indexOf(' ') + 1); index--;}

		if ((-1) == line.indexOf(' ')) {return line;}
		else {return line.substring(0, line.indexOf(' '));}
	}

	public static int[] getIntArray(String line)
	{
		String[] strings = getStringArray(line);
		int[] numbers = new int[strings.length];
		for (int i = 0; i < strings.length; i++) {numbers[i] = Integer.parseInt(strings[i]);}
		return numbers;
	}
	public static long[] getLongArray(String line)
	{
		String[] strings = getStringArray(line);
		long[] numbers = new long[strings.length];
		for (int i = 0; i < strings.length; i++) {numbers[i] = Long.parseLong(strings[i]);}
		return numbers;
	}
	public static double[] getDoubleArray(String line)
	{
		String[] strings = getStringArray(line);
		double[] numbers = new double[strings.length];
		for (int i = 0; i < strings.length; i++) {numbers[i] = Double.parseDouble(strings[i]);}
		return numbers;
	}
	public static String[] getStringArray(String line) {return line.trim().split("(\\s)+", 0);}

	public static int[] getIntArray(String line, int begin, int end)
	{
		String[] strings = getStringArray(line, begin, end);
		int[] numbers = new int[end - begin];
		for (int i = begin; i < end; i++) {numbers[i - begin] = Integer.parseInt(strings[i - begin]);}
		return numbers;
	}
	public static long[] getLongArray(String line, int begin, int end)
	{
		String[] strings = getStringArray(line, begin, end);
		long[] numbers = new long[end - begin];
		for (int i = begin; i < end; i++) {numbers[i - begin] = Long.parseLong(strings[i - begin]);}
		return numbers;
	}
	public static double[] getDoubleArray(String line, int begin, int end)
	{
		String[] strings = getStringArray(line, begin, end);
		double[] numbers = new double[end - begin];
		for (int i = begin; i < end; i++) {numbers[i - begin] = Double.parseDouble(strings[i - begin]);}
		return numbers;
	}
	public static String[] getStringArray(String line, int begin, int end)
	{
		String[] lines = line.trim().split("(\\s)+", 0);
		String[] results = new String[end - begin];
		for (int i = begin; i < end; i++) {results[i - begin] = lines[i];}
		return results;
	}

	public static String[] getStringArray(BufferedReader input, int N) throws Exception
	{
		String[] results = new String[N];
		for (int i = 0; i < N; i++) {results[i] = input.readLine();}
		return results;
	}
	public static char[][] getCharMatrix(BufferedReader input, int N) throws Exception {return getCharMatrix(input, N, N);}
	public static char[][] getCharMatrix(BufferedReader input, int R, int C) throws Exception
	{
		char[][] matrix = new char[R][C];
		for (int i = 0; i < R; i++)
		{
			String line = input.readLine();
			for (int j = 0; j < C; j++) {matrix[i][j] = line.charAt(j);}
		}
		return matrix;
	}
	public static int[][] getIntMatrix(BufferedReader input, int N) throws Exception {return getIntMatrix(input, N, N);}
	public static int[][] getIntMatrix(BufferedReader input, int R, int C) throws Exception
	{
		int[][] matrix = new int[R][C];
		for (int i = 0; i < R; i++)
		{
			String line = input.readLine();
			for (int j = 0; j < C; j++) {matrix[i][j] = getInt(line, j);}
		}
		return matrix;
	}

	public static boolean[][] newBooleanMatrix(int R, int C, boolean value)
	{
		boolean[][] matrix = new boolean[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}
	public static char[][] newCharMatrix(int R, int C, char value)
	{
		char[][] matrix = new char[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}
	public static int[][] newIntMatrix(int R, int C, int value)
	{
		int[][] matrix = new int[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}
	public static long[][] newLongMatrix(int R, int C, long value)
	{
		long[][] matrix = new long[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}
	public static double[][] newDoubleMatrix(int R, int C, double value)
	{
		double[][] matrix = new double[R][C];
		for (int i = 0; i < R; i++) for(int j = 0; j < C; j++) {matrix[i][j] = value;}
		return matrix;
	}

	public static void swap(boolean[] a, int i, int j) {boolean temp = a[i]; a[i] = a[j]; a[j] = temp;}
	public static void swap(char[] a, int i, int j) {char temp = a[i]; a[i] = a[j]; a[j] = temp;}
	public static void swap(int[] a, int i, int j) {int temp = a[i]; a[i] = a[j]; a[j] = temp;}
	public static void swap(long[] a, int i, int j) {long temp = a[i]; a[i] = a[j]; a[j] = temp;}
	public static void swap(double[] a, int i, int j) {double temp = a[i]; a[i] = a[j]; a[j] = temp;}

	public static void output(String s) throws Exception
	{
		if (ECHO_ON) {System.out.println(s);}
		output.write(s);
		output.newLine();
	}
	public static void output(char[][] array, String separator) throws Exception
	{
		for (int i = 0; i < array.length; i++)
		{
			StringBuffer buffer = new StringBuffer();

			for (int j = 0; j < array[0].length - 1; j++)
			{
				buffer.append(array[i][j] + separator);
			}

			buffer.append(array[i][array[0].length - 1]);

			output(buffer.toString());
		}
	}
	public static void output(int[][] array, String separator) throws Exception
	{
		for (int i = 0; i < array.length; i++)
		{
			StringBuffer buffer = new StringBuffer();

			for (int j = 0; j < array[0].length - 1; j++)
			{
				buffer.append(array[i][j] + separator);
			}

			buffer.append(array[i][array[0].length - 1]);

			output(buffer.toString());
		}
	}

	public static String toKey(boolean[] array)
	{
		StringBuffer buffer = new StringBuffer(array.length + ",");
		for (int i = 0; i < array.length / 16; i++)
		{
			char c = 0;
			for (int j = 0; j < 16; j++)
			{
				c <<= 1; if (array[i * 16 + j]) {c += 1;}
			}
			buffer.append(c + "");
		}
		char c = 0;
		for (int j = 0; j < (array.length % 16); j++)
		{
			c <<= 1; if (array[(array.length / 16) * 16 + j]) {c += 1;}
		}
		buffer.append(c + "");
		return buffer.toString();
	}
	public static String toKey(int[] array, int bit)
	{
		StringBuffer buffer = new StringBuffer(array.length + ",");
		if (bit > 16)
		{
			for (int i = 0; i < array.length; i++)
			{
				char c1 = (char)(array[i] >> 16);
				char c2 = (char)(array[i] & 0xFFFF);
				buffer.append("" + c1 + c2);
			}
		}
		else
		{
			int n = 16 / bit;
			for (int i = 0; i < array.length / n; i++)
			{
				char c = 0;
				for (int j = 0; j < n; j++)
				{
					c <<= bit; c += array[i * n + j];
				}
				buffer.append(c + "");
			}
			char c = 0;
			for (int j = 0; j < (array.length % n); j++)
			{
				c <<= bit; c += array[(array.length / n) * n + j];
			}
			buffer.append(c + "");
		}
		return buffer.toString();
	}

	public static void debug(String s)
	{if (DEBUG_ON) {System.out.println(s);}}
	public static void debug(String s0, double l0)
	{if (DEBUG_ON) {System.out.println(s0+" = "+l0);}}
	public static void debug(String s0, double l0, String s1, double l1)
	{if (DEBUG_ON) {System.out.println(s0+" = "+l0+"; "+s1+" = "+l1);}}
	public static void debug(String s0, double l0, String s1, double l1, String s2, double l2)
	{if (DEBUG_ON) {	System.out.println(s0+" = "+l0+"; "+s1+" = "+l1+"; "+s2+" = "+l2);}}
	public static void debug(String s0, double l0, String s1, double l1, String s2, double l2, String s3, double l3)
	{if (DEBUG_ON) {System.out.println(s0+" = "+l0+"; "+s1+" = "+l1+"; "+s2+" = "+l2+"; "+s3+" = "+l3);}}
	public static void debug(String s0, double l0, String s1, double l1, String s2, double l2, String s3, double l3, String s4, double l4)
	{if (DEBUG_ON) {System.out.println(s0+" = "+l0+"; "+s1+" = "+l1+"; "+s2+" = "+l2+"; "+s3+" = "+l3+"; "+s4+" = "+l4);}}

	public static void debug(boolean[] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(boolean[] array, String separator)
	{
		if (DEBUG_ON)
		{
			StringBuffer buffer = new StringBuffer();
			for (int i = 0; i < array.length - 1; i++) {buffer.append((array[i] == true ? "1" : "0") + separator);}
			buffer.append((array[array.length - 1] == true) ? "1" : "0");
			System.out.println(buffer.toString());
		}
	}
	public static void debug(boolean[][] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(boolean[][] array, String separator)
	{if (DEBUG_ON) {for (int i = 0; i < array.length; i++) {debug(array[i], separator);}}}

	public static void debug(char[] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(char[] array, String separator)
	{
		if (DEBUG_ON)
		{
			StringBuffer buffer = new StringBuffer();
			for (int i = 0; i < array.length - 1; i++) {buffer.append(array[i] + separator);}
			buffer.append(array[array.length - 1]);
			System.out.println(buffer.toString());
		}
	}
	public static void debug(char[][] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(char[][] array, String separator)
	{if (DEBUG_ON) {for (int i = 0; i < array.length; i++) {debug(array[i], separator);}}}

	public static void debug(int[] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(int[] array, String separator)
	{
		if (DEBUG_ON)
		{
			StringBuffer buffer = new StringBuffer();
			for (int i = 0; i < array.length - 1; i++) {buffer.append(array[i] + separator);}
			buffer.append(array[array.length - 1]);
			System.out.println(buffer.toString());
		}
	}
	public static void debug(int[][] array) {if (DEBUG_ON) {debug(array, " ");}}
	public static void debug(int[][] array, String separator)
	{if (DEBUG_ON) {for (int i = 0; i < array.length; i++) {debug(array[i], separator);}}}
}
