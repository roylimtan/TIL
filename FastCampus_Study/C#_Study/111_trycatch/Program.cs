using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _111_trycatch
{
    class Program
    {
        static void Main(string[] args)
        {
            int inputNum = 0;
            bool isCorrect = false;

            while(!isCorrect)
            {
                Console.WriteLine("입력문자: ");
                string readStr = Console.ReadLine();

                try
                {
                    inputNum = int.Parse(readStr);
                    isCorrect = true;
                }
                catch(FormatException e)
                {
                    Console.WriteLine(e.Message);
                    Console.WriteLine("입력문자: " + readStr + "정수를 입력하세요.");
                }
            }

            Console.WriteLine("inputNum: " + inputNum);
        }
    }
}
