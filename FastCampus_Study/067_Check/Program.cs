using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _067_Check
{
    class Program
    {
        static  void Start()
        {
            Console.WriteLine("성적 프로그램 - Method");
        }

        static void Input(ref int KorNum, ref int EngNum, ref int MathNum)
        {
            Console.Write("국어 성적 입력(정수): ");
            KorNum = int.Parse(Console.ReadLine());

            Console.Write("영어 성적 입력(정수): ");
            EngNum = int.Parse(Console.ReadLine());

            Console.Write("수학 성적 입력(정수): ");
            MathNum = int.Parse(Console.ReadLine());

            Console.WriteLine("Kor: {0}, Eng: {1}, Math: {2}", KorNum, EngNum, MathNum);
        }

        static int Total(int kor, int eng, int math)
        {
            int total;
            total = kor + eng + math;

            return total;
        }

        static void Average(int total, out float average)
        {
           
            average = total / 3;          
        }

        static void Main(string[] args)
        {
            int kor = 0;
            int eng = 0;
            int math = 0;
            int total;
            float average;

            Start();
            Input(ref kor, ref eng, ref math);
            total = Total(kor, eng, math);
            Average(total, out average);

            Console.WriteLine("Totla: {0}   Average: {1}", total, average);
        }
    }
}
