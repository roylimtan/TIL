using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _08_Sort_Selection
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("선택정렬");

            int[] data = { 20, 15, 1, 5, 10 };

            Console.WriteLine("시작 값");

            for (int i = 0; i < data.Length; i++)
            {
                Console.Write(data[i] + ", ");
            }

            Console.WriteLine();

            //정렬
            for (int i = 0; i < data.Length; i++)
            {
                int min = i;

                for (int j = i+1; j < data.Length; j++)
                {
                    if (data[min] > data[j])
                        min = j;
                }

                swap(ref data[i], ref data[min]);
            }

            Console.WriteLine("정렬 값");
            for (int i = 0; i < data.Length; i++)
            {
                Console.Write(data[i] + ", ");
            }
        }


        static void swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
    }
}
