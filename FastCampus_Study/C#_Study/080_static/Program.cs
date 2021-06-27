using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _080_static
{
    class AA
    {
        public static int a;
        public static int b;
        public static readonly int c = 200; //상수화된다.(읽기 전용)
        public int num;

        public static void Print()
        {
            Console.WriteLine("a: {0}", a);
            Console.WriteLine("b: {0}", b);
            Console.WriteLine("c: {0}", c);

            //num = 10; 오류
        }

        //static 속성이 있는 메소드는 static속성이 있는 변숨만 사용 가능
    }

    class BB
    {
        public int a;
        public int b;

        public void Print()
        {
            Console.WriteLine("a: {0}", a);
            Console.WriteLine("b: {0}", b);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            AA.a = 100;
            AA.b = 200;
            AA.Print();

            BB bb = new BB();

            bb.a = 10;
            bb.b = 20;
            bb.Print();

        }
    }
}
