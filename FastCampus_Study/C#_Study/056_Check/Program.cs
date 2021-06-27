using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _056_Check
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random();
            int a = rnd.Next(1, 100);
            int TryNum = 0;

            while(true)
            {
                Console.WriteLine("1~99사이 어떤 숫자일까요(단, 0은 나가기)", a);
                int Num = int.Parse(Console.ReadLine());
                TryNum++;
                if(Num == 0)
                {
                    Console.WriteLine("종료합니다.");
                    break;
                               
                }

                else if(Num > a)
                {
                    Console.WriteLine("입력한 수는 커요.");
                }

                else if(Num == a)
                {
                    Console.WriteLine("== 정답 입니다. ==");
                    Console.WriteLine("총{0}번 시도", TryNum);
                    break;
                }
                
                else if(Num < a)
                {
                    Console.WriteLine("입력한 수는 작아요.");
                }
            }
        }
    }
}
