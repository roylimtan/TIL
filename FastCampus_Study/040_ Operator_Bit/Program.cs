using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _040__Operator_Bit
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 15;     //0000 0000   0000 0000   0000 0000   0000 1111
            int b = 22;     //0000 0000   0000 0000   0000 0000   0001 0110
            int c = a & b;  //0000 0000   0000 0000   0000 0000   0000 0110 => 6
            Console.WriteLine("a & b: " + c);

            //0000 0000   0000 0000   0000 0000   0000 1111
            //0000 0000   0000 0000   0000 0000   0001 0110
            //0000 0000   0000 0000   0000 0000   0001 1111 => 31
            int d = a | b;
            Console.WriteLine("a | b" + d);

            //0000 0000   0000 0000   0000 0000   0000 1111
            //0000 0000   0000 0000   0000 0000   0001 0110
            //0000 0000   0000 0000   0000 0000   0001 1001 => 25
            int e = a ^ b;
            Console.WriteLine("a ^ b: " + e);

            int f = a << 2; //0000 0000   0000 0000   0000 0000   0011 1100 => 60
            Console.WriteLine("a << 2: " + f);
            Console.WriteLine("a << 1: " + (a << 1)); //왼쪽으로 1시프트 하면 2배로 증가(곱셈연산가능)

                             //0000 0000   0000 0000   0000 0000   0001 0100
            int g = 20 >> 2; //0000 0000   0000 0000   0000 0000   0000 1010 => 5
            Console.WriteLine("20 >> 2: " + g);
            Console.WriteLine("(20 >> 1):" + (20 >> 1)); //오른쪽을 ㅗ1시프트 하면 2로 나눔

                           //0000 0000   0000 0000   0000 0000   0001 0110
            int h = ~b;    //1111 1111   1111 1111   1111 1111   1110 1001 => -23  
            Console.WriteLine("h = ~b: " + h);

            int i = (~b) >> 2;
            Console.WriteLine("i = (~b) >>: " + i);

            string s = Convert.ToString(a, 2).PadLeft(32, '0');
            Console.WriteLine("s: " + s);
            s = Convert.ToString(b, 2).PadLeft(32, '0');
            Console.WriteLine("s: " + s);

        }
    }
}
