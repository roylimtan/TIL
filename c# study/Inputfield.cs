using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Inputfield : MonoBehaviour
{

    /*
     caret : 커서 
    placeholder : 값을 입력하기 전에 나오는 텍스트
    
    inputfield와 텍스트 만들고 2개의 버튼 만들기

    int.parse() : 가로안의 내용을 int형식으로 형변환 시켜준다.
     */

    [SerializeField] private Text txt_Money;
    [SerializeField] private InputField inputtxt_Money;

    private int currentMoney;

    public void Input()
    {
        currentMoney += int.Parse(inputtxt_Money.text);

        txt_Money.text = currentMoney.ToString();
    }

    public void output()
    {
        currentMoney -= int.Parse(inputtxt_Money.text);

        txt_Money.text = currentMoney.ToString();
    }
}
