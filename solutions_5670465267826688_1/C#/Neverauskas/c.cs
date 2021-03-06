﻿using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "C-large";

		private static void Main()
		{
			Console.SetIn(new StreamReader(string.Format(@"C:\GoogleCodeJam\{0}.in", fileName)));
			Console.SetOut(new StreamWriter(string.Format(@"C:\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
			var t = cin.NextInt();
			var sw = Stopwatch.StartNew();
			for (var c = 1; c <= t; c++)
			{
				Console.Write("Case #{0}: ", c);
				Solve();
				Debug.WriteLine("{0} {1}", c, sw.Elapsed);
			}
		}

		// 1 = 1
		// i = 2
		// j = 3
		// k = 4
		private static readonly int[][] mult =
		{
			new int[5],
			new[] {0, 1, 2, 3, 4},
			new[] {0, 2, -1, 4, -3},
			new[] {0, 3, -4, -1, 2},
			new[] {0, 4, 3, -2, -1}
		};

		private static int[][] map = new int[10][];

		private static readonly int[] vals = new int[200];

		private static void Solve()
		{
			for (var i = 0; i < 10; i++)
			{
				map[i] = new int[10];
				for (var j = 0; j < map[i].Length; j++)
				{
					map[i][j] = int.MaxValue;
				}
			}

			vals['i'] = 2;
			vals['j'] = 3;
			vals['k'] = 4;

			var l = cin.NextLong();
			var x = cin.NextLong();
			var str = cin.NextString();
			//Debug.WriteLine(str);
			//if (str == "ji")
			//{
			//	var z = 5;
			//}
			//if (x * l < 3)
			//{
			//	Console.WriteLine("NO");
			//	return;
			//}
			var arr = new int[str.Length];
			for (var i = 0; i < str.Length; i++)
			{
				arr[i] = vals[str[i]];
			}
			//if (arr.Distinct().Count() == 1)
			//{
			//	Console.WriteLine("NO");
			//	return;
			//}

			var isSingle = false;
			var front = new List<int>();
			var countL = (int)(Math.Ceiling(5000.0/l) + 0.5);
			var middleCnt = 0L;
			if (countL*2 > x)
			{
				// take all
				for (var i = 0; i < x; i++)
				{
					for (var j = 0; j < arr.Length; j++)
					{
						front.Add(arr[j]);
					}
				}
				isSingle = true;
			}
			else
			{
				// take partly
				for (var i = 0; i < countL; i++)
				{
					for (var j = 0; j < arr.Length; j++)
					{
						front.Add(arr[j]);
					}
				}
				middleCnt = x - countL*2;
			}

			//var n = x;
			//var arr2 = new int[arr.Length * n];
			//for (var i = 0; i < n; i++)
			//{
			//	for (var j = 0; j < arr.Length; j++)
			//	{
			//		arr2[i * arr.Length + j] = arr[j];
			//	}
			//}
			var value = Eval(arr, 0, arr.Length);
			//var multValue = value;
			//if (x > 1)
			//{
			//	multValue = Mult(value, value);
			//	if (x%2 != 0)
			//	{
			//		multValue = Mult(multValue, value);
			//	}
			//}
			//if (multValue != -1)
			//{
			//	Console.WriteLine("NO");
			//	return;
			//}

			var val = 1;
			for (var i = 0; i < front.Count; i++)
			{
				val = Mult(val, front[i]);
				if (val != 2)
				{
					continue;
				}
				var val2 = 1;
				for (var k = front.Count - 1; k > i + 1; k--)
				{
					val2 = Mult(front[k], val2);
					if (val2 != 4)
					{
						continue;
					}
					// check mid
					if (isSingle)
					{
						var val3 = 1;
						for (var j = i + 1; j < k; j++)
						{
							val3 = Mult(val3, front[j]);
						}
						if (val3 == 3)
						{
							Console.WriteLine("YES");
							return;
						}
					}
					else
					{
						var val3 = 1;
						for (var j = i + 1; j < front.Count; j++)
						{
							val3 = Mult(val3, front[j]);
						}
						if (middleCnt > 0)
						{
							var values = new List<int>();
							var val4 = 1;
							values.Add(val4);
							for (var m = 0; m < 9; m++)
							{
								val4 = Mult(val4, value);
								values.Add(val4);
							}
							var take = middleCnt%4;
							var ss = values[(int)take];

							//var multValue = value;
							//if (middleCnt > 1)
							//{
							//	multValue = Mult(value, value);
							//	if (middleCnt % 2 != 0)
							//	{
							//		multValue = Mult(multValue, value);
							//	}
							//}
							val3 = Mult(val3, ss);
						}
						for (var j = 0; j < k; j++)
						{
							val3 = Mult(val3, front[j]);
						}
						if (val3 == 3)
						{
							Console.WriteLine("YES");
							return;
						}
					}
					break;
				}
				break;
			}

			//var kk = new int[arr2.Length];
			//var valK = 1;
			//for (var i = arr2.Length - 1; i >= 0; i--)
			//{
			//	valK = Mult(arr2[i], valK);
			//	kk[i] = valK;
			//}

			//var valI = 1;
			//for (var i = 0; i < arr2.Length - 2; i++)
			//{
			//	valI = Mult(valI, arr2[i]);
			//	if (valI != 2)
			//	{
			//		continue;
			//	}
			//	var valJ = 1;
			//	for (var j = arr2.Length - 2; j > i; j--)
			//	{
			//		valJ = Mult(valJ, arr2[j]);
			//		if (valJ == 3 && kk[j + 1] == 4)
			//		{
			//			//Debug.WriteLine(l + " " + i/l + "   " + (arr2.Length - j - 1)/l);
			//			Console.WriteLine("YES");
			//			return;
			//		}
			//	}
			//}

			Console.WriteLine("NO");
		}

		private static int Eval(int[] list, int start, int end)
		{
			var val = 1;
			for (var i = start; i < end; i++)
			{
				val = Mult(val, list[i]);
			}
			return val;
		}

		private static int Mult(int x, int y)
		{
			if (map[5 - x][5 - y] != int.MaxValue)
			{
				return map[5 - x][5 - y];
			}
			var sign = 1;
			if (x < 0) sign *= -1;
			if (y < 0) sign *= -1;
			var result = mult[Math.Abs(x)][Math.Abs(y)] * sign;
			map[5 - x][5 - y] = result;
			return result;
		}
	}

	internal class Scanner
	{
		private string[] s = new string[0];
		private int i;
		private readonly char[] cs = { ' ' };

		public string NextString()
		{
			if (i < s.Length) return s[i++];
			var line = Console.ReadLine() ?? string.Empty;
			if (line == string.Empty)
			{
				return NextString();
			}
			s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
			i = 1;
			return s.First();
		}

		public double NextDouble()
		{
			return double.Parse(NextString());
		}

		public int NextInt()
		{
			return int.Parse(NextString());
		}

		public long NextLong()
		{
			return long.Parse(NextString());
		}
	}
}