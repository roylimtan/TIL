using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _081_02_classInheritance
{
    class Super
    {
        protected int a;

        public Super()
        {
            a = 100;
            Console.WriteLine("call super 생성자 호출");
        }

        ~Super()
        {
            Console.WriteLine("call super 소멸자 함수");
        }
    }

    class Sub:Super
    {
        public Sub()
        {
            Console.WriteLine("call sub 생성자 호출");
        }

        ~Sub()
        {
            Console.WriteLine("call sub 소멸자 호출");
        }
    } 

    class Program
    {
        static void Main(string[] args)
        {
            Sub sub = new Sub();
        }
    }
}
