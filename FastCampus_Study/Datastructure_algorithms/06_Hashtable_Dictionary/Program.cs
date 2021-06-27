using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace _06_Hashtable_Dictionary
{
    class Program
    {
        static void Main(string[] args)
        {
            Hashtable Myhash = new Hashtable();

            Myhash.Add("민수", 78);
            Myhash.Add("정현", 90);
            Myhash.Add("현수", 85);
            Myhash.Add("수민", 69);

            Console.WriteLine(Myhash["정현"]);

            foreach (object key in Myhash.Keys)
                Console.WriteLine("keys: {0}  value: {1}", key, Myhash[key]);

            Dictionary<string, string> dic = new Dictionary<string, string>();

            dic.Add("민수", "010-0000-0001");
            dic.Add("정현", "010-0000-0002");
            dic.Add("현수", "010-0000-0003");
            dic.Add("수민", "010-0000-0004");

            foreach (var item in dic.Keys)
                Console.WriteLine(item+ ":" + dic[item]);

            if (!dic.ContainsKey("용슈"))
                dic.Add("용수", "010-0000-0005");

            dic.Remove("정현");

            Console.WriteLine();

            foreach (var item in dic.Keys)
                Console.WriteLine(item + ":" + dic[item]);
        }
    }
}
