using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ScrollUI : MonoBehaviour
{
    /*
     Canvas에 Panel생성
    panel안에 panel을 생성하여 우측 스크롤바 자리를 만들어준다.
    그안에 다시 panel(contents)을 생성하여 아이템이 들어갈 공간을 만들어준다.
    영역을 확인하기 위해서 색을 설정해주고 a값을 0으로 해준다.

    그 안에 여러개의 버튼을 생성해주고 마지막 만든 panel에 grid layout을 추가한다.

    grid layout의 start corner는 새로운 버튼이 생성되는 위치

    두번째 만든 panel에 mask만들어준다. 그럼 panel을 넘어가 생성된 버튼들은 짤릴것이다.

    두번째 만든 panel에 scroll rect생성

    마지막 만든 panel에 content size fitter 생성

    첫 panel에 scrollbar생성

    두번째 만든 panle의 scroll rect의 vertical scrollbar에 생성한 scrollbar를 넣어준다.
     */

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
