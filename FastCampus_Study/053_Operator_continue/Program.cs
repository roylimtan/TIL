using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _053_Operator_continue
{
    class Program
    {
        static void Main(string[] args)
        {
            for(int i = 0; i < 10; i++)
            {
                if(i == 5)
                {
                    Console.WriteLine();
                    continue;
                }

                Console.WriteLine("i: " + i);
            }

            int total = 0;
            for (int i = 0; i < 10; i++)
            {
                if(i % 2 == 1)
                {
                    continue;
                }
                total += i;
            }
            Console.WriteLine("totoal: " + total);
        }
    }
}
