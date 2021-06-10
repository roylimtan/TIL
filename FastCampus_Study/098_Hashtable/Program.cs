using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace _098_Hashtable
{
    class Program
    {
        static void Main(string[] args)
        {
            Hashtable hashtable = new Hashtable();
            hashtable.Add("pos", 10);
            hashtable.Add("name", "jack");
            hashtable["weight"] = 10.8f;

            foreach(object key in hashtable.Keys)
            {
                Console.WriteLine("key: {0}, data: {1}", key, hashtable[key]);
            }

            Console.WriteLine("");

            Hashtable hashTableCopy = new Hashtable()
            {
                ["pos"] = 10,
                ["name"] = "jack",
                ["weight"] = 10.8f,
            };

            foreach(object key in hashTableCopy.Keys)
            {
                Console.WriteLine("key: {0}, data: {1}", key, hashTableCopy[key]);
            }
        }
    }
}
