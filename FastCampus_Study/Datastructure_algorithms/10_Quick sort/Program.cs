using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _10_Quick_sort
{
    class Program
    {
        static int[] data = { 25, 15, 60, 45, 10, 20, 5, 30 };

        static void Main(string[] args)
        {
            Console.WriteLine("============== 퀵정렬 ==============");
            Console.WriteLine();
            Console.Write("시작값 : ");

            for (int i = 0; i < data.Length; i++)
            {
                Console.Write(data[i].ToString() + ", ");
            }

            Console.WriteLine();

            SortQuick(0, data.Length - 1);

            Console.Write("정렬값 : ");

            for (int i = 0; i < data.Length; i++)
            {
                Console.Write(data[i].ToString() + ", ");
            }

            Console.WriteLine();
        }

       
        static void SortQuick(int nFirst, int nLast)
        {
            if (nFirst < nLast)
            {
                int pivotIndex = FuncPartition(nFirst, nLast);

                // 분할 정복
                SortQuick(nFirst, pivotIndex - 1);
                SortQuick(pivotIndex + 1, nLast);
            }
        }


        static int FuncPartition(int nFirst, int nLast)
        {
            int nLow, nHigh, nPivot;


            // 임의 값 여기에서는 마지막 값
            nPivot = data[nLast];

            nLow = nFirst;
            nHigh = nLast - 1;


            while (nLow <= nHigh)
            {
                // 25, 15, 60, 45, 10, 20, 5, 30
                // 1회차 Pivot 30 - 2, 6 - 25, 15, 5, 45, 10, 20, 60, 30
                // 2회차 Pivot 30 - 3, 5 - 25, 15, 5, 45, 10, 20, 60, 30
                // 3회차 Pivot 30 - 3, 5 - 25, 15, 5, 20, 10, 45, 60, 30

                while (data[nLow] < nPivot)
                    nLow++;

                while (data[nHigh] > nPivot)
                    nHigh--;

                if (nLow <= nHigh)
                {
                    Swap(data, nLow, nHigh);
                }
            }

            Swap(data, nLow, nLast);

            Console.Write("정렬값(Pivot : " + nPivot + ") - ");

            for (int i = 0; i < data.Length; i++)
            {
                if (nPivot == data[i])
                    Console.Write("*" + data[i] + "*, ");
                else
                    Console.Write(data[i] + ", ");
            }

            Console.WriteLine();

            return nLow;
        }

        static void Swap(int[] nArrData, int nValue1, int nValue2)
        {
            int nTemp = nArrData[nValue1];
            nArrData[nValue1] = nArrData[nValue2];
            nArrData[nValue2] = nTemp;
        }
    }
}
