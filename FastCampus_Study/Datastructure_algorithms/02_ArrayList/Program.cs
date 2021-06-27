using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace _02_ArrayList
{
    class Program
    {
        static void Main(string[] args)
        {
            ArrayList list = new ArrayList();
            list.Add(1);
            list.Add("한국");
            list.Insert(1, 4);
            list.Add(true);

            for (int i = 0; i < list.Count; i++)
            {
                Console.WriteLine(list[i]);
            }

            List<string> music = new List<string>();
            music.Add("좋은날");
            music.Add("이런엔딩");
            music.Insert(1, "이름에게");

            music.RemoveAt(1);
            music.Remove("이런엔딩");
            for (int i = 0; i < music.Count; i++)
            {
                Console.WriteLine(music[i]);
            }
        }
    }
}
