using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

//입력 받은두 수의 결과를 저장하는 프로그램
//제한 없이 계속 입력 받을 수 있음
//저장했던 자료를 모두 보여주기

namespace _102_Check
{
    class Program
    {
        static void Main(string[] args)
        {
            Queue Aqueue = new Queue();
            Queue Bqueue = new Queue();
            Queue Resultqueue = new Queue();

            int a;
            int b;
            int num;

            while(true)
            {
                Console.Write("첫 번째 수를 입력하세요. ");
                a = int.Parse(Console.ReadLine());

                Aqueue.Enqueue(a);

                Console.Write("두 번째 수를 입력하세요. ");
                b = int.Parse(Console.ReadLine());

                Bqueue.Enqueue(b);

                Resultqueue.Enqueue(a + b);

                Console.WriteLine("{0} + {1} = {2}", a, b, a + b);
                Console.WriteLine("");
                Console.Write("계속 하시겠습니까? (0)나가기 (1)계속");
                num = int.Parse(Console.ReadLine());

                if(num == 1)
                {
                    Console.WriteLine("");
                }
                else
                {
                    Console.Clear();
                    break;
                }
            }

            Console.WriteLine("========결과 공개============");

            while (Aqueue.Count > 0)
            {
                Console.WriteLine("{0} + {1} = {2}", Aqueue.Dequeue(), Bqueue.Dequeue(), Resultqueue.Dequeue());
            }
        }
    }
}
