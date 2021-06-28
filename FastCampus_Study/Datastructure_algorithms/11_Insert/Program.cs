using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _11_Insert
{
    //삽입정렬
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("삽입정렬");

            int[] arrData = {20, 15, 1, 5, 10 };

            for (int i = 1; i < arrData.Length; i++)
            {
                int key = i;

                for (int j = i - 1; j >= 0; j--)
                {
                    if (arrData[key] < arrData[j])
                    {
                        int temp = arrData[j];
                        arrData[j] = arrData[key];
                        arrData[key] = temp;
                        key = j;
                    }

                    else
                        break;
                }

                for (int j = 0; j < arrData.Length; j++)
                {
                    Console.Write(arrData[j] + ", ");
                }

                Console.WriteLine();
            }
        }
    }
}
