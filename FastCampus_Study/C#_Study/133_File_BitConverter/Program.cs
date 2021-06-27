using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


using System.IO;
namespace _133_File_BitConverter
{
    class Program
    {
        const string fileName = "a.txt";
        static void Main(string[] args)
        {
            long LValue = 1234567890123456789;
            int num = 100;
            Console.WriteLine("LValue: " + LValue);
            Console.WriteLine("num: " + num);

            Stream outStream = new FileStream(fileName, FileMode.Create);
            byte[] wBytes = BitConverter.GetBytes(LValue);

            Console.Write("Byte: ");

            foreach (var item in wBytes)
                Console.Write("{0:X2}", item);
            Console.WriteLine();

            outStream.Write(wBytes, 0, wBytes.Length);

            wBytes = BitConverter.GetBytes(num);

            Console.Write("Byte: ");

            foreach(var item in wBytes)
                Console.Write("{0:X2}", item);
            Console.WriteLine();

            outStream.Write(wBytes, 0, wBytes.Length);

            outStream.Close();

            //파일읽기
            FileStream inStream = new FileStream(fileName, FileMode.Open);

            //rByte의  길이만큼 데이터를 읽어 rByte에 저장
            byte[] rBytes = new byte[sizeof(long)];
            inStream.Read(rBytes, 0, rBytes.Length);
            long readValue = BitConverter.ToInt64(rBytes, 0);

            rBytes = new byte[sizeof(int)];
            inStream.Read(rBytes, 0, rBytes.Length);
            int readNum = BitConverter.ToInt32(rBytes, 0);

            Console.WriteLine("Read Data: " + readValue);
            Console.WriteLine("Read Data: " + readNum);

            inStream.Close();
        }
    }
}
