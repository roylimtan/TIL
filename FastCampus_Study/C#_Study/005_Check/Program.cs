using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _005_Check
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length > 0)
            {
                Console.WriteLine("지금 듣는 강의는 " + args[0] + args[1] + "좋아요!!");
            }
            else
            {
                Console.WriteLine("HelloWorld: args.Length = 0");
            }

            Console.ReadKey();
        }
    }
}

//커맨드창 겨기
//cd..으로 초기화
//주소 복붙
//dir
//실행하고자 하는 파일과 리스트에 넣을 값 입력
//출력
