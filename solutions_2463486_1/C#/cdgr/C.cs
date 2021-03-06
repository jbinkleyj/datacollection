﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace RAVE
{
	class TestCase
	{
		// Little John likes palindromes, and thinks them to be fair (which is a fancy word for nice).
		// A palindrome is just a number that reads the same backwards and forwards - so 6, 11 and 121 are all palindromes,
		// while 10, 12, 223 and 2244 are not (even though 010=10, we don't consider leading zeroes when determining whether
		// a number is a palindrome).

		// He recently became interested in squares as well, and formed the definition of a fair and square number
		// - it is a number that is a palindrome and the square of a palindrome at the same time.
		// For instance, 1, 9 and 121 are fair and square (being palindromes and squares, respectively, of 1, 3 and 11),
		// while 16, 22 and 676 are not fair and square: 16 is not a palindrome, 22 is not a square, and while 676 is a
		// palindrome and a square number, it is the square of 26, which is not a palindrome.

		// Now he wants to search for bigger fair and square numbers.
		// Your task is, given an interval Little John is searching through, to tell him how many fair and square numbers
		// are there in the interval, so he knows when he has found them all.

		// Usually, Google Code Jam problems have 1 Small input and 1 Large input.
		// This problem has 1 Small input and 2 Large inputs.
		// Once you have solved the Small input, you will be able to download any of the two Large inputs.
		// As usual, you will be able to retry the Small input (with a time penalty), while you will get only one chance
		// at each of the Large inputs.

		// Each test case contains two numbers, A and B - the endpoints of the interval Little John is looking at.

		// 100|10000|1000 test cases.
		long A, B; // 1 ≤ A ≤ B ≤ 1000|10^14|10^100

		static long[] FairAndSquare = GetPalindromes().Select(p => p * p).Where(p => IsPalindrome(p)).ToArray();

		private static IEnumerable<long> GetPalindromes()
		{
			return GetPalindromes(1, 0)
				.Concat(GetPalindromes(1, 1))
				.Concat(GetPalindromes(2, 1))
				.Concat(GetPalindromes(2, 2))
				.Concat(GetPalindromes(3, 2))
				.Concat(GetPalindromes(3, 3))
				.Concat(GetPalindromes(4, 3))
				.Concat(GetPalindromes(4, 4));
		}

		private static IEnumerable<long> GetPalindromes(int digits, int mirrored)
		{
			int first = Convert.ToInt32(Math.Pow(10, digits - 1));
			return Enumerable.Range(first, first * 10 - first).Select(i => Mirror(i, mirrored));
		}

		private static long Mirror(int i, int mirrored)
		{
			var s = i.ToString();
			return Convert.ToInt64(new string(Enumerable.Concat(s, s.Take(mirrored).Reverse()).ToArray()));
		}

		private static bool IsPalindrome(long p)
		{
			var s = p.ToString();
			int h = (s.Length) / 2;
			return s.Take(h).SequenceEqual(s.Reverse().Take(h));
		}

		public TestCase(TextReader input)
		{
			var x = input.ReadLongs();
			A = x[0]; B = x[1];
		}

		public long GetResult()
		{
			// Return the number of fair and square numbers greater or equal to A and smaller or equal than B.
			return FairAndSquare.Count(f => A <= f && f <= B);
		}
	}
}