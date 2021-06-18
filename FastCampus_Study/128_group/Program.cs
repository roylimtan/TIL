using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _128_group
{
    struct Student
    {
        public int _id;
        public string _name;
        public int _kor;
        public int _eng;

        public Student(int _id, string _name, int _kor, int _eng)
        {
            this._id = _id;
            this._name = _name;
            this._kor = _kor;
            this._eng = _eng;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Student[] arrStudent =
           {
                new Student(){_id = 100, _name = "John", _kor = 100, _eng = 20},
                new Student(){_id = 200, _name = "Jane", _kor = 80, _eng = 20},
                new Student(300, "Tom", 50, 60),
                new Student(400, "Max", 80, 80),
                new Student(500, "Jack", 70, 70)
            };

            var QueryData =
                from data in arrStudent
                orderby (data._eng + data._kor) descending
                group data by (data._eng + data._kor) < 150;

            foreach(var data in QueryData)
            {
                string str = data.Key ? "합이 150보다 작은 경우: " : "합이 150보다 큰 경우 : ";
                Console.WriteLine(str);

                foreach (var item in data)
                    Console.WriteLine("\t{0} : {1}", item._name, (item._kor + item._eng));
            }    
        }
    }
}
