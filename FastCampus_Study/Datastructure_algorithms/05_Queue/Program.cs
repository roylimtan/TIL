using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _05_Queue
{
    class Program
    {
        static void Main(string[] args)
        {
            Queue<int> myQueue = new Queue<int>();

            for (int i = 0; i < 10; i++)
            {
                myQueue.Enqueue(i);
            }

            myQueue.Dequeue();
            myQueue.Dequeue();

            foreach (int data in myQueue)
                Console.WriteLine(data);
        }
    }
}
