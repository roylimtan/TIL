using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _018_Data_object
{
    class Program
    {
        static void Main(string[] args)
        {
            object a = 100;
            object b = 2.14325346673535234346346f;
            object c = 3.12324534535242353464564m;
            object d = 'H';
            object e = 'i';
            object f = "World";
            object g = false;

            Console.WriteLine("a: " + a);
            Console.WriteLine("b: " + b);
            Console.WriteLine("c: " + c);
            Console.WriteLine("{0}{1} {2}", d, e, f);
            Console.WriteLine("g: " + g);


        }
    }
}
