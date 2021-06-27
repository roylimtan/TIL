using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _116_delegate
{
    delegate int DelegateFunc(int a);

    class Program
    {
        delegate int DelegateFunc(int a);

        static int Add(int a)
        {
            Console.WriteLine("Add");
            return a + a;
        }
        static void Main(string[] args)
        {
            DelegateFunc delegateFunc = Add;
            Console.WriteLine("delegateFunc: " + delegateFunc(10));
        }
    }
}
