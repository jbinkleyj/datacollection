﻿using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace CodeJam
{

    class Solver
    {
        string solveCase(int[][] input)
        {
            int c = input[0][0];
            int v = input[0][2];
            int[] coins = input[1];
            int add = 0;
            int currentIndex = 1;
            if (coins[0] != 1)
            {
                add++;
                currentIndex = 0;
            }
            int max = 1 * c;
            int lastVal = 1;
            while (max < v)
            {
                if (coins.Length > currentIndex)
                {
                    var currentCoin = coins[currentIndex];
                    if (currentCoin <= (max + 1))
                    {
                        lastVal = currentCoin;
                        max += currentCoin * c;
                        currentIndex++;
                        continue;
                    }
                }
                int addCoin = max + 1;
                lastVal = addCoin;
                max += addCoin * c;
                add++;
            }
            return add.ToString();
        }


        public string Solve(string input)
        {
            string[] lines = input.Trim().Split('\n').Select(l => l.TrimEnd('\r')).ToArray();

            StringBuilder sb = new StringBuilder();
            int nbCases = Convert.ToInt32(lines[0]);
            int iLine = 1;
            for (int i = 0; i < nbCases; i++)
            {
                //Console.WriteLine("Case: " + i);

                string[] lineParts = lines[iLine].Split(' ');
                int[] linePartsint = lineParts.Select(p => Convert.ToInt32(p)).ToArray();

                int caseLines = 1;
                int[][] caseInput = new int[caseLines + 1][];
                caseInput[0] = linePartsint;

                for (var caseLine = 0; caseLine < caseLines; caseLine++)
                {
                    iLine++;
                    lineParts = lines[iLine].Split(' ');
                    linePartsint = lineParts.Select(p => Convert.ToInt32(p)).ToArray();
                    caseInput[caseLine + 1] = linePartsint;
                }
                string result = solveCase(caseInput);
                sb.AppendLine("Case #" + (i + 1) + ": " + result);
                iLine++;
            }
            return sb.ToString();
        }
    }

}

