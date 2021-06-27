using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//로또번호 만들기

namespace _01_Array
{
    class Program
    {
        static void Main(string[] args)
        {
            Lotto MyLotto = new Lotto();
        }

        class Lotto
        {
            private int[] number;

            public Lotto()
            {
                GetNumber();
            }

            private void GetNumber()
            {
                Random rnd = new Random();
                number = new int[6];

                int index = 0;
                int Bonusnumber = rnd.Next(1, 46);

                while (index < number.Length)
                {
                    int temp = rnd.Next(1, 46);
                    if(SameNum(index, temp) == true && temp != Bonusnumber)
                    {
                        number[index++] = temp;
                    }
                }

                for(int i = 0; i < number.Length; i++)
                {
                    Console.WriteLine(number[i]);
                }

                Console.WriteLine("보너스 번호: " + Bonusnumber);
            }

            private bool SameNum(int index, int temp)
            {
                for (int i = 0; i < index; i++)
                {
                    if (number[index] == temp)
                        return false;
                }              
                    return true;
            }           
        }
    }
}
