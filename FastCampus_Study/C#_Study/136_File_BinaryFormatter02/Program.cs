using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

namespace _136_File_BinaryFormatter02
{
    [Serializable]
    struct Player
    {
        public string _Name;
        public int _Level;
        public double _Exp;
    }

    class Program
    {
        const string fileNmae = "list.dat";
        static void Main(string[] args)
        {
            List<Player> listPlayers = new List<Player>();

            for(int i = 0; i < 10; i++)
            {
                Player player = new Player();
                player._Name = i.ToString();
                player._Level = i;
                player._Exp = i * 10;

                listPlayers.Add(player);
            }

            //쓰기
            FileStream fsw = new FileStream(fileNmae, FileMode.Create);

            BinaryFormatter bfw = new BinaryFormatter();
            bfw.Serialize(fsw, listPlayers);

            fsw.Close();

            //읽기
            FileStream fsr = new FileStream(fileNmae, FileMode.Open);

            BinaryFormatter bfr = new BinaryFormatter();
            List<Player> readPlaayers = (List<Player>)bfr.Deserialize(fsr);

            foreach(var data in readPlaayers)
            {
                Console.WriteLine("name: {0}  Level: {1}  Exp: {2}", data._Name, data._Level, data._Exp);
            }

            fsr.Close();
        }
    }
}
