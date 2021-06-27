using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _03_LinkedList
{
    class Program
    {
        static void Main(string[] args)
        {
            SinglyLinkedList<int> list = new SinglyLinkedList<int>();

            list.AddLast(1);
            list.AddLast(2);
            list.AddLast(3);
            list.AddLast(4);
            list.AddLast(5);

            list.AddFirst(0);

            Node<int> find = list.Find(3);

            list.AddAfter(find, 10);
            list.Remove(find);

            Console.WriteLine(list.ToString());
        }
    }
}
