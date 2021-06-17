using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _119_Event
{
    public delegate void delegateEvent(string msg);

    class InDelegate
    {
        public delegateEvent myDelegate;
        public event delegateEvent myEvent;

        public void DoEvent(int a, int b)
        {
            if (null != myEvent) //event는 null값인지 확인 필수
                myEvent("DoEvent: " + (a + b));
        }
    }
    class Program
    {
        static public void ConsoleFunc(string msg)
        {
            Console.WriteLine("ConsoleFunc: " + msg);
        }
        static void Main(string[] args)
        {
            InDelegate id = new InDelegate();
            id.myEvent += ConsoleFunc;
            id.myDelegate = ConsoleFunc;

            id.myDelegate("Test");

            for(int i = 0; i < 10; i++)
            {
                id.DoEvent(i + 1, i + 2);
            }
        }
    }
}
