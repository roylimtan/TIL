using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _019_Data_enum
{
    class Program
    {
        enum Day_of_week
        {
            SUN,
            MON,
            THE,
            WED,
            THU,
            FRI,
            SAT
        }
        static void Main(string[] args)
        {
            Console.WriteLine("{0} {1}", Day_of_week.SUN, (int)Day_of_week.SUN);
        }
    }
}
