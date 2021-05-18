using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace CheckPoint01
{
    class Program
    {
        const string LINE = "=============================================";
        const int END_LINE = 42;
        const int DELAY_TIME = 200;

        static int runA = 0;
        static int runB = 0;
        static int runC = 0;
        static int runD = 0;

        static void ClearScreen()
        {
            Thread.Sleep(DELAY_TIME); //딜레이
            Console.Clear();
        }

        static void Process(Random rnd)
        {
            ++runA;
            ++runB;
            ++runC;
            ++runD;

            int rndNum = rnd.Next(0, 4);

            switch (rndNum)
            {
                case 0:
                    ++runA;
                    break;

                case 1:
                    ++runB;
                    break;

                case 2:
                    ++runC;
                    break;

                case 3:
                    ++runD;
                    break;
            }
        }

        static void UpdateScreen()
        {
            Console.WriteLine(LINE);

            for (int i = 0; i < runA; i++)
                Console.Write(" ");
            Console.Write("1");

            for (int i = (END_LINE - 2) - runA; i >= 0; i--)
                Console.Write(" ");
            Console.WriteLine("|");

            for (int i = 0; i < runB; i++)
                Console.Write(" ");
            Console.Write("2");

            for (int i = (END_LINE - 2) - runB; i >= 0; i--)
                Console.Write(" ");
            Console.WriteLine("|");

            for (int i = 0; i < runC; i++)
                Console.Write(" ");
            Console.Write("3");

            for (int i = (END_LINE - 2) - runC; i >= 0; i--)
                Console.Write(" ");
            Console.WriteLine("|");

            for (int i = 0; i < runD; i++)
                Console.Write(" ");
            Console.Write("4");

            for (int i = (END_LINE - 2) - runD; i >= 0; i--)
                Console.Write(" ");
            Console.WriteLine("|");

            Console.WriteLine(LINE);
        }

        static bool CheckResult()
        {
            if (runA >= END_LINE || runB >= END_LINE || runC >= END_LINE || runD >= END_LINE)
            {
                string strResult = "결과: ";

                if (runA >= END_LINE)
                {
                    strResult += "!! 1번선수 우승 !!";
                }

                else if (runB >= END_LINE)
                {
                    strResult += "!! 2번선수 우승 !!";
                }

                else if (runC >= END_LINE)
                {
                    strResult += "!! 3번선수 우승 !!";
                }

                else
                {
                    strResult += "!! 4번선수 우승 !!";

                }

                Console.WriteLine(strResult);

                Console.Write("다시하시려면 0번 입력: ");
                if (0 == int.Parse(Console.ReadLine()))
                {
                    runA = 0;
                    runB = 0;
                    runC = 0;
                    runD = 0;

                    return true;
                }

                else
                    return false;
            }

            return true;
        }

        static void Main(string[] args)
        {
            
            while (true)
            {
                ClearScreen();

                Random rnd = new Random();

                Process(rnd);

                UpdateScreen();

                if (CheckResult() == false)
                    break;
            }

        }
    }
}

