using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Test2
{
    private int a;
    public int b;
    public static int c; // 공공의 공유자원, 정적 변수
}

public class Designator : MonoBehaviour{

    Test2 a1 = new Test2();
    Test2 a2 = new Test2();
    Test2 a3 = new Test2();

    void Start()
    {
        Abc();
    }

    void Abc()
    {
        a1.b = 5;
        a2.b = 10;
        a3.b = 15;

        Test2.c = 100;

        print(a1.b);
        print(a2.b);
        print(a3.b);
        print(Test2.c);
    }
}
