using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _033_Check
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("국어 점수를 입력하세요");
            string KorS = Console.ReadLine();

            Console.Write("영어 점수를 입력하세요");
            string EngS = Console.ReadLine();

            Console.Write("수학 점수를 입력하세요");
            string MathS = Console.ReadLine();

            Console.Write("과학 점수를 입력하세요");
            string SciS = Console.ReadLine();

            int KorNum = int.Parse(KorS);
            int EngNum = int.Parse(EngS);
            int MathNum = int.Parse(MathS);
            int SciNum = int.Parse(SciS);

            int TotalNum = KorNum + EngNum + MathNum + SciNum;
            double AverageNum = (TotalNum / 4);

            Console.WriteLine("국어: {0}, 영어: {1}, 수학: {2}, 과학: {3}", KorNum, EngNum, MathNum, SciNum);
            Console.WriteLine("총점: {0}, 평균: {1}", TotalNum, AverageNum);
        }
    }
}
