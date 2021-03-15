using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SliderUI : MonoBehaviour
{

    /*
     RPG게임에서 체력 나타낼수있는 UI 
     
     Canvas 생성 -> Slider 생성
    Background : 채워지지 않은 영역
    fillarea안에 fill은 채워진 영역의 색
    Handle : 손잡이의 모양과 색
    slider의 max value를 바꿔주면 fillarea의 right를 같은값으로 바꿔줘야한다.

    (버튼을 누르면 slider가 채워지는 기능 만들기)
    canvas에 button생성
     */

    [SerializeField] private Slider slider;

    private bool isClick;

    private float dotTime = 1f;
    private float currentDotTime = 0f;

    void Start()
    {
        currentDotTime = dotTime;
    }

    void Update()
    {
        if(isClick)
        {
            currentDotTime -= Time.deltaTime;

            if(currentDotTime <= 0)
            {
                slider.value -= Time.deltaTime;

                if(currentDotTime <= -1f)
                {
                    currentDotTime = dotTime;
                }
            }
        }
    }

    public void Button()
    {
        isClick = true;
    }

    /*
     만든 스크립트를 canvas에 넣는다. 
    slider에 Slider를 넣는다.
    button의 on click에 canvas를 넣고 만든 스크립트의 만든 함수를 선택한다.
     */
}
