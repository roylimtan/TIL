using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _09_Bubble
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("버블정렬");
            int[] data = { 20, 15, 1, 5, 10 };
            Console.WriteLine("초기 값");

            for (int i = 0; i < data.Length; i++)
            {
                Console.Write(data[i] + ", ");
            }

            Console.WriteLine();

            for (int i = 0; i < data.Length - 1; i++)
            {
                for(int j = 0; j < data.Length - (i+1); j++)
                {
                    if(data[j] > data[j + 1])
                    {
                        swap(ref data[j], ref data[j + 1]);
                    }

                    Console.Write((i + 1) + "번쩨 정렬 값({0} , {1})", j, j + 1);

                    for (int k = 0; k < data.Length; k++)
                    {
                        Console.Write(data[k] + ", ");
                    }

                    Console.WriteLine();
                }

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
