using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _12_Heap_sort
{
    //힙정렬
    class Program
    {
        static void Main(string[] args)
        {
            SortHeap();
        }

        #region Heap sort

        static void SortHeap()
        {
            int[] data = { 20, 35, 15, 5, 40, 10, 25, 30 };

            Console.WriteLine("============ 힙정렬 ===========");
            Console.WriteLine();

            Console.Write("시작값 : ");
            for (int i = 0; i < data.Length; i++)
                Console.Write(data[i].ToString() + ", ");
            Console.WriteLine();
            Console.WriteLine();

            for (int i = (data.Length - 1) / 2; i >= 0; --i)
            {
                CalcHeap(data, i, data.Length);
            }

            for (int i = data.Length - 1; i > 0; --i)
            {
                SwapHeap(ref data[i], ref data[0]);
                CalcHeap(data, 0, i);

                Console.Write("정렬값 : ");
                for (int k = 0; k < data.Length; k++)
                    Console.Write(data[k].ToString() + ", ");

                Console.WriteLine();
            }


            Console.Write("정렬값 : ");
            for (int i = 0; i < data.Length; i++)
                Console.Write(data[i].ToString() + ", ");
            Console.WriteLine();
        }

        static void SwapHeap(ref int nData1, ref int nData2)
        {
            int nTemp = nData1;
            nData1 = nData2;
            nData2 = nTemp;
        }

        static void CalcHeap(int[] data, int nRoot, int nMax)
        {
            while (nRoot < nMax)
            {
                // 왼쪽 자식 노드
                int nChild = nRoot * 2 + 1;

                // 오른쪽 자식노드가 더 크면 오른쪽 선택
                if (nChild + 1 < nMax && data[nChild] < data[nChild + 1])
                    ++nChild;

                if (nChild < nMax && data[nRoot] < data[nChild])
                {
                    SwapHeap(ref data[nRoot], ref data[nChild]);
                    nRoot = nChild;

                    Console.Write("정렬값 : ");
                    for (int k = 0; k < data.Length; k++)
                        Console.Write(data[k].ToString() + ", ");

                    Console.WriteLine();
                }
                else
                    break;
            }
        }

        #endregion Heap sort
    }
}
