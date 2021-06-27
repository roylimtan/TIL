using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _04_Stack
{
    class Program
    {
        static void Main(string[] args)
        {
            Stack<int> myStack = new Stack<int>();

            for (int i = 0; i < 9; i++)
            {
                myStack.Push(i);
            }

            myStack.Pop();
            myStack.Peek();

            foreach(int data in myStack)
            {
                Console.WriteLine(data);
            }

        }
    }
}
