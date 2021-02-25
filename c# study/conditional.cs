using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Array : MonoBehaviour
{

    //1차원 배열
    int[] exp = { 10, 20, 30, 40, 50 };

    int[] array = new int[10];

    //2차원 배열
    int[,] array2 = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 } };

    //3차원 배열
    int[,,] array3 = { { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 } }, { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 } } };

    // Start is called before the first frame update
    void Start()
    {
        print(array2[1, 3]);
        print(array3[0, 1, 3]);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
