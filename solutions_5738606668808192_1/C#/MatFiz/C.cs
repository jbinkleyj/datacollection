﻿using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Numerics;
using System.Text.RegularExpressions;

namespace CodeJam2016
{
    static class Program
    {
        static BigInteger GetValue(uint bits, int numberBase)
        {
            var result = BigInteger.Zero;
            var digit = BigInteger.One;

            while (bits != 0)
            {
                if ((bits & 1) == 1)
                    result += digit;

                digit *= numberBase;
                bits = bits >> 1;
            }

            return result;
        }

        class PrimeInfo
        {
            public readonly BigInteger Value;
            public readonly bool? IsPrime;
            public readonly int? Divider;

            PrimeInfo(BigInteger value, bool? isPrime, int? divider)
            {
                Value = value;
                IsPrime = isPrime;
                Divider = divider;
            }

            public static PrimeInfo Prime(BigInteger value)
            {
                return new PrimeInfo(value, true, null);
            }

            public static PrimeInfo NotPrime(BigInteger value, int firstDivider)
            {
                return new PrimeInfo(value, false, firstDivider);
            }

            public static PrimeInfo Unknown(BigInteger value)
            {
                return new PrimeInfo(value, null, null);
            }
        }

        static PrimeInfo GetPrimeInfo(BigInteger value)
        {
            for (var i = 0; i < _primes.Count; i++)
            {
                var p = _primes[i];

                if (value == p)
                    return PrimeInfo.Prime(value);

                if (value % p == 0)
                    return PrimeInfo.NotPrime(value, p);

                if (value / p <= p)
                    return PrimeInfo.Prime(value);
            }

            return PrimeInfo.Unknown(value);
        }

        static List<int> _primes;

        class CoinInfo
        {
            public readonly uint Coin;
            public readonly bool IsSurelyValid;
            public IReadOnlyCollection<int> Dividers;

            public string CoinBits => Convert.ToString(Coin, 2);

            public CoinInfo(uint coin, bool isSurelyValid, IReadOnlyCollection<int> dividers)
            {
                Coin = coin;
                IsSurelyValid = isSurelyValid;
                Dividers = dividers;
            }

            public static CoinInfo FromBits(string bits)
            {
                var info = FromCoin(Convert.ToUInt32(bits, 2));
                Debug.Assert(info.CoinBits == bits);
                return info;
            }

            public static CoinInfo FromCoin(uint coin)
            {
                if (coin % 2 != 1)
                    throw new ArgumentOutOfRangeException(nameof(coin), "JamCoin must end with 1");

                var dividers = new int[9];
                var isSurelyValidCoin = true;
                for (var b = 2; b <= 10; b++)
                {
                    var n = GetValue(coin, b);
                    var d = GetPrimeInfo(n);

                    if (d.IsPrime == false)
                        dividers[b - 2] = d.Divider.Value;
                    else
                    {
                        isSurelyValidCoin = false;
                        break;
                    }
                }

                var info = new CoinInfo(coin, isSurelyValidCoin, dividers);

                return info;
            }
        }

        static void Main(string[] args)
        {
            uint template = 0x80000001;
            var required = 500;
            //uint template = 0x8001;
            //var required = 50;

            Debug.Assert(Regex.IsMatch(Convert.ToString(template, 2), "^10+1$"));
            var max = GetValue(template - 3 + template, 10);
            _primes = Eratosthenes(10);

            Debug.Assert(CoinInfo.FromBits("101").IsSurelyValid == false);

            var c1001 = CoinInfo.FromBits("1001");
            Debug.Assert(c1001.IsSurelyValid == true);
            Debug.Assert(c1001.Dividers.SequenceEqual(new[] { 3, 2, 5, 2, 7, 2, 3, 2, 7 }));

            Console.WriteLine("Case #1:");
            var found = 0;

            for (uint i = 0; ; i += 2)
            {
                var coin = template + i;
                if (coin > max)
                    break;

                var coinInfo = CoinInfo.FromCoin(coin);

                if (coinInfo.IsSurelyValid)
                {
                    Console.WriteLine("{0} {1}", Convert.ToString(coin, 2), string.Join(" ", coinInfo.Dividers));
                    found++;
                    if (found == required)
                        break;
                }
            }

            if (found < required)
                throw new ApplicationException($"Could only find {found} coins");

            //Console.WriteLine("Found {0} coins", found);
        }

        public static List<int> Eratosthenes(int max)
        {
            var firstPrime = new int[max + 1];
            var primes = new List<int>();

            for (var i = 2; i <= max; i++)
                if (firstPrime[i] == 0)
                {
                    primes.Add(i);
                    for (var j = i * (long)i; j <= max; j += i)
                        firstPrime[j] = i;
                }

            return primes;
        }
    }
}