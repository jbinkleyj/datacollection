﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;


namespace nonsava.gcj
{
	class Problem
	{
		#region Main

		static string RESULTFILE = @"..\..\..\__out.txt";

		static void Main( string[] args )
		{
			if( 0 < args.Length ) {
				CASEFILE = args[0];
			} else if( 1 < args.Length ) {
				MAXTHREADS = int.Parse( args[1] );
			}

			DateTime startTime = DateTime.Now;

			int count;
			Problem[] testcases;

			using( TextReader reader = new StreamReader( CASEFILE ) ) {
				string line = reader.ReadLine();
				count = int.Parse( line );
				testcases = new Problem[count];

				for( int i = 0; i < count; i++ )
					testcases[i] = new Problem( reader );
			}

			Initialize();

			Thread[] threadPool = new Thread[MAXTHREADS];
			for( int t = 0; t < MAXTHREADS; t++ )
				threadPool[t] = null;

			for( int next = 0;; ) {
				if( count <= next ) {
					bool finished = true;
					for( int t = 0; t < MAXTHREADS; t++ )
						if( threadPool[t] != null && threadPool[t].IsAlive ) {
							finished = false;
							break;
						}
					if( finished )
						break;
				}

				for( int t = 0; t < MAXTHREADS; t++ ) {
					if( threadPool[t] != null && !threadPool[t].IsAlive )
						threadPool[t] = null;

					if( threadPool[t] == null && next < count ) {
						Console.WriteLine( "----------------------------------------------------- {0}/{1} ({2:F3}[sec])", next + 1, count, ( DateTime.Now - startTime ).TotalSeconds );
						testcases[next].WriteParams();

						threadPool[t] = new Thread( new ThreadStart( testcases[next++].Solv ) );
						threadPool[t].Start();
					}
				}

				Thread.Sleep( 100 );
			}

			Console.WriteLine( "\n#############################################################################\n" );
			using( TextWriter writer = new StreamWriter( RESULTFILE ) ) {
				for( int i = 0; i < count; i++ )
					testcases[i].WriteResult( writer, i + 1 );
			}

			TimeSpan span = DateTime.Now - startTime;
			Console.WriteLine( "\n#############################################################################\n" );
			Console.WriteLine( "{0:F3}[sec] = {1:F3}[min]", span.TotalSeconds, span.TotalMinutes );
			if( BEEP )
				Console.Beep( 1000, 5000 );
			Console.ReadKey();
		}


		string Result;

		private void WriteResult( TextWriter writer, int number )
		{
			writer.WriteLine( "Case #{0}: {1}", number, Result );
			Console.WriteLine( "Case #{0}: {1}", number, Result );
		}

		#endregion


		////////////////////////////////
		//static string CASEFILE = @"..\..\..\__in_sample.txt";

//		static string CASEFILE = @"..\..\..\A-small-attempt0.in";
		static string CASEFILE = @"..\..\..\A-large.in";

		static int MAXTHREADS = 1;
		static bool BEEP = false;
		////////////////////////////////


		private static void Initialize()
		{
			////////////////////////////////
			////////////////////////////////
		}



		////////////////////////////////
		int N;
		int[] P;
		////////////////////////////////
		

		private Problem( TextReader reader )
		{
			////////////////////////////////
			string line = reader.ReadLine();
			N = int.Parse( line );
			P = new int[N];

			line = reader.ReadLine();
			string[] strs = line.Split( new char[] { ' ' } );
			for( int i = 0; i < N; i++ ) {
				P[i] = int.Parse(strs[i]);
			}
			////////////////////////////////

			Result = null;
		}


		private void WriteParams()
		{
			////////////////////////////////
			Console.WriteLine( "{0}", N );
			for( int i = 0; i < N; i++ )
				Console.Write( " {0}", P[i] );
			Console.WriteLine();
			////////////////////////////////
		}


		private void Solv()
		{
			////////////////////////////////
			int I1 = 0;
			int m = 0;
			for (int i = 0 ; i < N; i++) {
				if (m < P[i]) {
					I1 = i;
					m = P[i];
				}
			}

			int I2 = 0;
			m = 0;
			for (int i = 0 ; i < N; i++) {
				if (m < P[i] && i != I1) {
					I2 = i;
					m = P[i];
				}
			}

			Result = "";
			while (P[I1] != P[I2]) {
				Result += (char)('A' + I1);
				Result += ' ';
				P[I1]--;
			}

			for (int i = 0; i < N; i++) {
				if (i != I1 && i != I2) {
					while (P[i] > 0) {
						Result += (char)('A' + i);
						Result += ' ';
						P[i]--;
					}
				}
			}

			while (P[I1] > 0) {
				Result += (char)('A' + I1);
				Result += (char)('A' + I2);
				Result += ' ';
				P[I1]--;
			}
			


			////////////////////////////////

			Console.WriteLine( "Result: {0}", Result );
		}

	}
}
