using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//람다식과 비교
namespace _125_LINQ
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] data = new int[] { 0, 54, 98, 102, 332 };

            var QueryData =
                from temp in data
                where temp < 100
                select temp;

            var test = from temp in data
                       select temp;

            foreach(int n in QueryData)
            {
                Console.WriteLine("QueryData: " + n);
            }

            foreach(int n in test)
            {
                Console.WriteLine("test: " + n);
            }

            //람다식 사용과 비교
            List<int> listData = new List<int>(data);
            List<int> findAllData = listData.FindAll(a => a < 100);

            foreach(int n in findAllData)
            {
                Console.WriteLine("findAllData: " + n);
            }
        }
    }
}
