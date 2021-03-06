﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
	class Program
	{
		static string solve121AA(IEnumerable<string> args)
		{
			//Console.WriteLine(">>");
			var input = args.Select(x => x.Split(new char[] { ' ' }));
			var a = int.Parse(input.ElementAt(0).ElementAt(0));
			var b = int.Parse(input.ElementAt(0).ElementAt(1));
			var pop = input.ElementAt(1).Select(x => double.Parse(x));

			var rightAllPop = pop.Aggregate((n, m) => n * m);

			
			var ans =  new List<double>();
			ans.Add(b + 2); // retry
			ans.Add((rightAllPop * (b - a + 1)) + ((1 - rightAllPop) * (b - a + b + 2))); // continue
			ans.Add(a + b + 1); // del all
			for (int i = 1; i < a; i++)
			{
				var rightCount = i + i + b - a + 1;
				var rightPop = pop.Take(a - i).Aggregate((n, m) => n * m);
				ans.Add((rightPop * rightCount) + ((1 - rightPop) * (rightCount + b + 1)));
			}

			//Console.WriteLine("<< {0}", ans.Min());
			return ans.Min().ToString();
		}

		static void Main(string[] args)
		{
			File.WriteAllLines("z.txt", File.ReadAllLines("z.in").Skip(1).Select((x, i) => new { Group = i / /**/2, x }).GroupBy(g => g.Group)
				.AsParallel().AsOrdered().Select((x, i) => "Case #" + (i + 1) + ": " + solve121AA(x.Select(y => y.x))));
			//Console.ReadKey();
		}
	}
}
