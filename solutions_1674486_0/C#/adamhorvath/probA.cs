﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Program
    {
        public class Node
        {
            public List<int> inheritfrom = new List<int>();
            public int reached;
        }

        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());

            for (int i = 1; i <= N; i++)
            {
                var nodescount = int.Parse(Console.ReadLine());
                var nodes = new Node[nodescount];
                for (int j = 0; j < nodes.Length; j++)
                {
                    nodes[j] = new Node();
                    var incoming = Console.ReadLine().Split(' ');
                    var incount = int.Parse(incoming[0]);

                    for (int k = 0; k < incount; k++)
                    {
                        nodes[j].inheritfrom.Add(int.Parse(incoming[k + 1]) - 1);
                    }
                }

                bool found = false;

                for (int j = 0; j < nodes.Length; j++)
                {
                    clearReached(nodes);
                    if (walk(nodes, j))
                    {
                        found = true;
                        break;
                    }

                }
                if (!found)
                    Console.WriteLine("Case #" + i + ": " + "No");
                else
                    Console.WriteLine("Case #" + i + ": " + "Yes");
            }
        }

        private static bool walk(Node[] nodes, int j)
        {
            Stack<int> stack = new Stack<int>();

            stack.Push(j);

            while (stack.Count != 0)
            {
                Node c = nodes[stack.Pop()];

                if (c.reached > 1)
                    return true;

                for (int i = 0; i < c.inheritfrom.Count; i++)
                {
                    nodes[c.inheritfrom[i]].reached++;
                    stack.Push(c.inheritfrom[i]);
                }
            }

            return false;
        }

        private static void clearReached(Node[] nodes)
        {
            for (int i = 0; i < nodes.Length; i++)
            {
                nodes[i].reached = 0;
            }
        }
    }

}
