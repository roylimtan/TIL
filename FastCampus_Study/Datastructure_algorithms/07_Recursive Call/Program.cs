using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _07_Recursive_Call
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(FuncFactorial(5));
            Console.WriteLine(Fibonacci(5));
        }

        //팩토리얼
        static public int FuncFactorial(int nNumber)
        {
            int nResult = 0;

            if (nNumber == 1)
                nResult = 1;

            else
                nResult = nNumber * FuncFactorial(nNumber - 1);

            return nResult;
        }

        //피보나치수열
        static int Fibonacci(int num)
        {
            int nResult = 0;

            if (num == 1 || num == 2)
                nResult = 1;

            else
                nResult = Fibonacci(num-2) + Fibonacci(num - 1);

            return nResult;
        }

    }
}
