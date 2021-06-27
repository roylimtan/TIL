using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.IO;

namespace _132_File01
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = "";

            if(args.Length <= 0)
            {
                path = Directory.GetCurrentDirectory();
                path += "\\a.txt";

                Console.WriteLine("path: " + path);
            }

            else
            {
                path = args[0];
            }

            if(File.Exists(path))
            {
                Console.WriteLine("\nGetCreationTime: " + File.GetCreationTime(path));
            }

            FileInfo fileInfo = new FileInfo("b,txt");
            FileStream ff = fileInfo.Create();

            ff.Close();
        }
    }
}
