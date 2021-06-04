using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

abstract class abstractAA
{
    protected int num;

    public abstractAA(int num)
    {
        this.num = num;
    }

    public abstract void abstractPrint();

    public virtual void virtualPrint()
    {
        Console.WriteLine("abstractAA virtual void virtualPrint()");
    }

    public void Print()
    {
        Console.WriteLine("abstractAA pritn()");
    }
}

class AA : abstractAA
{
    public AA(int num) : base(num)
    {
        Console.WriteLine("num: {0}", num);
    }

    public override void abstractPrint()
    {
        Console.WriteLine("AA override void abstractPrint()");
    }

    public override void virtualPrint()
    {
        base.virtualPrint();
        Console.WriteLine("AA override void virtualPrint()");
    }
}

namespace _090_abstract
{
    class Program
    {
        static void Main(string[] args)
        {
            AA aa = new AA(10);
            aa.abstractPrint();
            aa.virtualPrint();
            aa.Print();

            //abstractAA aaa = new abstractAA(10); 불가능
        }
    }
}
