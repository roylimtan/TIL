using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//dynamic기초(var, object)

namespace _105_dynamic
{
    class Program
    {
        static T AddArray<T>(T[] arrDatas)
        {
            dynamic temp = default(T);
            for(int i = 0; i < arrDatas.Length; i++)
            {
                temp += arrDatas[i];
            }
            return temp;
        }

        static T SumArray<T>(T[] arrDatas)
        {
            T temp = default(T);
            for(int i = 0; i < arrDatas.Length; i++)
            {
                temp += (dynamic)arrDatas[i];
            }
            return temp;

        }

        static void PrintArray<T>(T[] arrDatas)
        {
            foreach (var data in arrDatas)
                Console.WriteLine("data: {0}", data);
        }

        static void Main(string[] args)
        {
            int[] arrNums = { 1, 2, 3, 4, 5 };

            Console.WriteLine("AddArray: {0}", SumArray(arrNums));
            PrintArray(arrNums);
        }
    }
}
