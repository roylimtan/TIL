using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _055_Check
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random();
            int ANum;
            int Num = 0;

            for (int i = 1; i < 6; i++)
            {
                
                int a = rnd.Next(0, 100);
                int b = rnd.Next(0, 100);
                Console.WriteLine("{0}: 다음 두 수의 합은 몇?", i);
                Console.WriteLine("{0} + {1} = ??", a, b);
                ANum = a + b;

                int MyNum = int.Parse(Console.ReadLine());

                if(MyNum == ANum)
                {
                    Console.WriteLine("== 정답 ==");
                    Num++;
                }

                else
                {
                    Console.WriteLine("오답(정답은: {0})", ANum);
                }
            }
            Console.WriteLine("총 접답 수: {0}/5", Num);  

            

           

            
        }
    }
}
