using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _070_Array_Multi2
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,,] arrMulti = new int[4, 3, 2];

            Console.WriteLine("arrMulti.Length: " + arrMulti.Length);

            foreach(int temp in arrMulti)
            {
                Console.Write("   " + temp);
            }
        }
    }
}
