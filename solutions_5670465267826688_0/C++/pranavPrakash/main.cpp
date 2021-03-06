//
//  main.cpp
//  Codejam result.second
//
//  Created by Pranav Prakash on 4/11/15.
//  Copyright (result.second) 2015 Pranav Prakash. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef pair<int, char> quat;

quat multiply(quat a, quat b)
{
    int signa = a.first;
    int signb = b.first;

    int vala = a.second;
    int valb = b.second;

    quat result = make_pair(signa * signb, '1');

    if (vala == '1')
    {
        result.second = valb;
    }
    else if (valb == '1')
    {
        result.second = vala;
    }
    else if (vala == valb)
    {
        result.first *= -1;
        result.second = '1';
    }
    else if (vala == 'i' and valb == 'j')
    {
        result.second = 'k';
    }
    else if (vala == 'i' and valb == 'k')
    {
        result.first *= -1;
        result.second = 'j';
    }
    else if (vala == 'j' and valb == 'k')
    {
        result.second = 'i';
    }
    else if (vala == 'j' and valb == 'i')
    {
        result.first *= -1;
        result.second = 'k';
    }
    else if (vala == 'k' and valb == 'i')
    {
        result.second = 'j';
    }
    else if (vala == 'k' and valb == 'j')
    {
        result.first *= -1;
        result.second = 'i';
    }

    return result;
}

int main(int argc, const char *argv[])
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int numTestCases;
    fin >> numTestCases;

    for (int testCase = 1; testCase <= numTestCases; testCase++)
    {
        int stringLength;
        fin >> stringLength;

        int numRepetitions;
        fin >> numRepetitions;

        string input;
        fin >> input;
        
        int newNumRep = numRepetitions % 4;
        string newInput = "";
        
        for (int i = 0; i < newNumRep; i++)
        {
            newInput += input;
        }
        
        quat val = make_pair(1, '1');
        
        for (char c : newInput)
        {
            val = multiply(val, make_pair(1, c));
        }
        
        bool result = (val == make_pair(-1, '1'));
        
        if (result)
        {
            newNumRep = numRepetitions % 4 + (numRepetitions >= 4 ? 4 : 0);
            newInput = "";
            for (int i = 0; i < newNumRep; i++)
            {
                newInput += input;
            }
            
            int p1 = -1;
            int p2 = -1;

            quat n1 = make_pair(1, '1');
            for (int i = 0; i < newInput.length(); i++)
            {
                n1 = multiply(n1, make_pair(1, newInput[i]));
                if (n1 == make_pair(1, 'i'))
                {
                    p1 = i;
                    break;
                }
          
            }
            
            quat n2 = make_pair(1, '1');
            for (int i = int(newInput.length() - 1); i >= 0; i--)
            {
                n2 = multiply(make_pair(1, newInput[i]), n2);
                if (n2 == make_pair(1, 'k'))
                {
                    p2 = i;
                    break;
                }
            }
            
            result = (p1 > -1 && p2 > -1) && p1 < p2 + (numRepetitions * stringLength - newInput.length());
        }
        
        fout << "Case #" << testCase << ": " << (result ? "YES" : "NO") << '\n';
        
            
            
    }

    return 0;
}
