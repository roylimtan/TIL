using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Collection : MonoBehaviour
{

    //ArrayList
    //Add로 추가, clear등 삭제와 변경 가능

    ArrayList arrayList = new ArrayList();

    //List
    //ArrayList보다 연산량이 적다.

    List<int> list = new List<int>();

    //HachTable
    //키값으로 값을 찾는다.

    Hashtable hashtable = new Hashtable();

    //Dictionary
    //hachtable과 비슷하지만 연산 속도차이
    Dictionary<string, int> dictionary = new Dictionary<string, int>();

    //Queue, 선입선출, 포션 제작 대기중

    Queue<int> queue = new Queue<int>();

    //Stack, 후입 선출, 요리게임

    Stack<int> stack = new Stack<int>();

    // Start is called before the first frame update
    void Start()
    {
        hashtable.Add("일", 1);
        hashtable.Add("백", 100);
        hashtable.Add(10, "십");

        print(hashtable["일"]);

        dictionary.Add("가", 100);

        queue.Enqueue(5);
        queue.Enqueue(10);

        print(queue.Dequeue());
        print(queue.Dequeue());

        stack.Push(1);
        stack.Push(2);
        stack.Push(3);

        print(stack.Pop());
        print(stack.Pop());
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
