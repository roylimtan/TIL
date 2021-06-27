using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _074_Array_Clear
{
    class Program
    {
       

        static void Main(string[] args)
        {
            int[] array = new int[3];

            Array.Clear(array, 0, array.Length);
            for(int i = 0; i < array.Length; i++)
            {
                array[i] = i;
            }

            for(int i = 0; i < array.Length; i++)
            {
                Console.Write("  {0}", array[i]);
            }

            Console.WriteLine("\n------------------------------------");

            int[,] arrNumm = new int[3, 2];

            Console.WriteLine("\n--------- Array.Clear -------------");
            Array.Clear(arrNumm, 0, arrNumm.Length);

            for(int i = 0; i < arrNumm.GetLength(0); i++)
            {
                for(int j = 0; j < arrNumm.GetLength(1); j++)
                {
                    arrNumm[i, j] = (i * arrNumm.GetLength(1)) + j;
                }
            }

            for(int i = 0; i < arrNumm.GetLength(0); i++)
            {
                for(int j = 0; j < arrNumm.GetLength(1); j++)
                {
                    Console.Write(" " + arrNumm[i, j]);
                }

                Console.WriteLine();
            }
        }
    }
}
