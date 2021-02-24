using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Function : MonoBehaviour
{
    int Ivalue;

    float Fvalue = 10.5f;
    float Fvalue2 = 20.5f;

    //함수에 반환값이 없을때 void사용
    int FloatToInt(float parameter, float parameter2, string SPar = "디폴트값") //디폴트는 맨 뒤에 와야한다.
    {
        print(SPar);
        return Multyply((int)(parameter + parameter2));
    }

    int Multyply(int parameter)
    {
        return parameter * parameter;
    }

    // Start is called before the first frame update
    void Start()
    {
        print(FloatToInt(Fvalue, Fvalue2));   
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
