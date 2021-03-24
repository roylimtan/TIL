using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems; //터치와 관련된 네임스페이스 가져오기 위해서 선언 

public class Joystick : MonoBehaviour, IPointerDownHandler, IPointerUpHandler, IDragHandler
{

    /* 
     canvas안에 이미지 두개를 만들고 하나는 조이스틱크기로 설정 후 둘다 knob으로 해준다.
     */

    //조이스틱이 백그라운드를 넘지 못하도록 선언
    [SerializeField] private RectTransform rect_Background;
    [SerializeField] private RectTransform rect_Joystick;

    //background의 반지름을 선언해준다.
    private float radius;

    //움직일 캐릭터 선언
    [SerializeField] private GameObject go_Player;
    [SerializeField] private float moveSpeed;

    //터치가 시작되면 플레이어를 움직이기 위해서 선언
    private bool isTouch = false;
    private Vector3 movePosition;

    // Start is called before the first frame update
    void Start()
    {
        radius = rect_Background.rect.width * 0.5f;
    }

    // Update is called once per frame
    void Update()
    {
        if (isTouch)
            go_Player.transform.position += movePosition;
    }

    public void OnDrag(PointerEventData eventData)
    {
        Vector2 value = eventData.position - (Vector2)rect_Background.position;
        //마우스포지션은 vector2, 유아이는 vector3 그러므로 강제 형변환 시켜준다.

        //조이스틱이 부모객체를 넘지 못하게 가두기
        value = Vector2.ClampMagnitude(value, radius);

        rect_Joystick.localPosition = value;

        //중심에서 멀어질수록 더 빨라지도록
        float distance = Vector2.Distance(rect_Background.position, rect_Joystick.position) / radius;

        //플레이어의 움직이는 방향구하기
        //value의 속도값은 빠지고 방향만 남는다.
        value = value.normalized;
        movePosition = new Vector3(value.x * moveSpeed * distance * Time.deltaTime, 0f, value.y * moveSpeed * distance * Time.deltaTime);
    }

    public void OnPointerDown(PointerEventData eventData)
    {
        isTouch = true;
    }

    public void OnPointerUp(PointerEventData eventData)
    {
        isTouch = false;

        //조이스틱을 놨을때 원위치로 돌아가게 한다.
        rect_Joystick.localPosition = Vector3.zero;
        
        //마우스를 땠을때 직전에 움직임을 기억하지 않게한다.
        movePosition = Vector3.zero;
    }
}
