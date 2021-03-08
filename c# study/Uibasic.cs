using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Uibasic : MonoBehaviour
{

    /*
    ui -> canvas생성
    canvas 안에 panel생성 -> Render Mode를 camera로 바꾸면 카메라가 보는 방향에 나타난다.
    -> plane distance를 이용하여 거리 조절

    world space모드 : 화면상에 canvas가 고정

    Graphics reycaster : 클릭을 반환한다.

    Text생성 -> overflow를 둘다 overflow로 설정하면 폰트사이즈를 키워도 짤리지 않는다.
    Raycast target 체크풀면 텍스트를 클릭해도 뒤에있는 버튼이 클릭된다.

    image->source image를 background로 하면 채우기 가능(hp등 표현할때 사용)

    button
    transition의 color tint : 마우스의 위치에 따라서 바뀌는 색 설정
    sprite swap : 마우스의 위치에 따라서 바뀌는 모습 설정
     */
    [SerializeField] private Text txt_name;
    [SerializeField] private Image img_name;
    //[SerializeField] private Sprite sprite; -> 인스펙터창에서 직접 이미지 넣기 가능

    private bool isCoolTime = false;

    private float currentTime = 5f;
    private float delayTime = 5f;

    private void Update()
    {

        //img_name.sprite = sprite이미지 변경
        //img_name.color = Color.red; 색 변경 가능
  

        if(isCoolTime)
        {
            currentTime -= Time.deltaTime;
            img_name.fillAmount = currentTime / delayTime;

            if(currentTime <0 )
            {
                isCoolTime = false;
                currentTime = delayTime;
                img_name.fillAmount = currentTime;
            }
        }
    }
    public void Change()
    {
        txt_name.text = "변경됨";
        isCoolTime = true;
    }
}
