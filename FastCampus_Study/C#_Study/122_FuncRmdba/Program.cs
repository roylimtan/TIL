using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _122_FuncRmdba
{
    delegate void dPrint(string str);
    delegate void dFunc();
    class Program
    {
        static public void CallPrint(string str)
        {
            Console.WriteLine(str);
        }
        static public void CallBackFunc(dPrint dp, string msg)
        {
            if (null != dp)
                dp("CallBaackFunc: " + msg);
        }
        static void Main(string[] args)
        {
            CallBackFunc(CallPrint, "Hello"); //함수 연결
            CallBackFunc(delegate (string str) { Console.WriteLine(str); }, "Hello"); //delegate 직접 인용
            CallBackFunc((string str) => { Console.WriteLine(str); }, "Hello");//람다의 식형태
            CallBackFunc((str) => Console.WriteLine(str), "Hello"); //람다식 기본
            CallBackFunc(str => Console.WriteLine(str), "Hello");

            dFunc dfunc = () => Console.WriteLine("No Params");
        }
    }
}
