﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _028_Data_reference
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = 100;
            int refNum = num;
            refNum = 1000;

            Console.WriteLine("refNum : {0}          ReferenceEquals: {1}", num, Object.ReferenceEquals(num, refNum));

            int[] arrNum = { 100, 200 };
            int[] refArrNum = arrNum;
            refArrNum[0] = 1000;

            Console.WriteLine("refArrNum : {0}          ReferenceEquals: {1}", arrNum[0], Object.ReferenceEquals(arrNum, refArrNum));

        }
    }
}
