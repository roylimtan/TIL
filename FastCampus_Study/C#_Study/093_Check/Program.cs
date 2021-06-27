using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _093_Check
{
    class CStudent
    {
        private int id;
        private int kor;
        private int math;
        private int eng;

        public int ID { get { return id; } }
        public int Kor { get { return kor; } }
        public int Math { get { return math; } }
        public int Eng { get { return eng; } }

        public CStudent()
        {
            this.id = 0;
            this.kor = 0;
            this.math = 0;
            this.eng = 0;
        }

        public void InputID()
        {
            Console.Write("학생 ID를 입력하세요.  ");
            this.id = int.Parse(Console.ReadLine());
        }

        public void InputKor()
        {
            Console.Write("국어 점수를 입력하세요.  ");
            this.kor = int.Parse(Console.ReadLine());
        }

        public void InputMath()
        {
            Console.Write("수학 점수를 입력하세요.  ");
            this.math = int.Parse(Console.ReadLine());
        }

        public void InputEng()
        {
            Console.Write("영어 점수를 입력하세요.  ");
            this.eng = int.Parse(Console.ReadLine());
        }

        public void PirntID()
        {
            Console.WriteLine("학생 ID: {0}", this.id);
        }

        public int GetTotal()
        {
            return kor + eng + math;
        }
    }

    class Program
    {
        static void PrintID(CStudent[] arrStudents)
        {
            foreach(CStudent data in arrStudents)
            {
                data.PirntID();
            }
        }

        static int CheckID(int id, CStudent[] arrStudents)
        {
            for(int i = 0; i < arrStudents.Length; i++)
            {
                if (id == arrStudents[i].ID)
                    return i;
            }

            return -1;
        }

        static void Main(string[] args)
        {
            const int Max = 3;
            int inputSel = 0;
            int selID = -1;

            CStudent[] arrStudemts = new CStudent[Max];

            for(int i = 0; i < Max; i++)
            {
                arrStudemts[i] = new CStudent();
                arrStudemts[i].InputID();
                arrStudemts[i].InputKor();
                arrStudemts[i].InputMath();
                arrStudemts[i].InputEng();

                Console.WriteLine();
            }

            Console.Clear();

            while(true)
            {
                PrintID(arrStudemts);
                Console.Write("학생 아이디를 입력하세요.  (0)나가기");
                inputSel = int.Parse(Console.ReadLine());

                if (inputSel == 0)
                    break;

                selID = CheckID(inputSel, arrStudemts);

                if(selID >= 0)
                {
                    Console.WriteLine("국어 점수: {0}", arrStudemts[selID].Kor);
                    Console.WriteLine("수학 점수: {0}", arrStudemts[selID].Math);
                    Console.WriteLine("영어 점수: {0}", arrStudemts[selID].Eng);

                    int total = arrStudemts[selID].GetTotal();

                    Console.WriteLine("총점: {0}", total);
                    Console.WriteLine("평균: {0}", total / (float)Max);

                    Console.WriteLine();
                }

                else
                {
                    Console.WriteLine("학생 아이디가 없어요. 다시 입력하세요.");
                }

            }
        }
    }
}
