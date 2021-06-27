using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

//성적 프로그램을 3명까지만 저장하고 정보 검ㅁ색이 가능한 프로그램
//저장했던 자료에서 참고하고 싶은 학생번호로 정보 보여주기
//ContainKey()함수 참고: Hashtable에 저장된 키값이 있는지 체크

namespace _101_Check
{
    class Program
    {
        static int CheckID(int id, Hashtable hashTable)
        {
            if(hashTable.ContainsKey(id))
            {
                return id;
            }

            return -1;
        }

        static void Main(string[] args)
        {
            int id;
            int kor;
            int math;
            int eng;
            int Num;
            int Count = 1;
            int Studentnum;
            int SellID;
            Hashtable KorhashTable = new Hashtable();
            Hashtable MathhashTable = new Hashtable();
            Hashtable EnghashTable = new Hashtable();
            Hashtable TotalhashTable = new Hashtable();
            Hashtable AvehashTable = new Hashtable();


            while (true)
            {
                Console.Write("학생 ID를 입력하세요.");
                id = int.Parse(Console.ReadLine());


                Console.Write("국어 점수를 입력하세요.");
                kor = int.Parse(Console.ReadLine());

                Console.Write("수학 점수를 입력하세요.");
                math = int.Parse(Console.ReadLine());

                Console.Write("영어 점수를 입력하세요.");
                eng = int.Parse(Console.ReadLine());

                KorhashTable.Add(id, kor);
                MathhashTable.Add(id, math);
                EnghashTable.Add(id, eng);
                TotalhashTable.Add(id, (kor + math + eng));
                AvehashTable.Add(id, (kor + math + eng) / 3);

                Console.Write("(0)나가기  (1)학생 추가");
                Num = int.Parse(Console.ReadLine());

                if (Num == 1)
                {
                    Count++;
                    Console.WriteLine("");
                }
                else
                {
                    Console.Clear();
                    break;
                }
            }

            while (true)
            {
                foreach (object key in KorhashTable.Keys)
                    Console.WriteLine("학생ID:  {0}", key);

                Console.Write("찾으시는 학생 ID를 입력하세요. (0)나가기");
                Studentnum = int.Parse(Console.ReadLine());

                if (Studentnum == 0)
                    break;

                SellID = CheckID(Studentnum, KorhashTable);

                if(SellID >= 0)
                {
                    Console.WriteLine("찾으려는 학생 ID: {0}", SellID);
                    Console.WriteLine("국어점수: {0}", KorhashTable[SellID]);
                    Console.WriteLine("수학점수: {0}", MathhashTable[SellID]);
                    Console.WriteLine("영어점수: {0}", EnghashTable[SellID]);
                    Console.WriteLine("총점: {0}", TotalhashTable[SellID]);
                    Console.WriteLine("평균: {0}", AvehashTable[SellID]);
                    Console.WriteLine("");
                }
            }
        }
    }
}
