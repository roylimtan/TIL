using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;

public class PlayerController2 : MonoBehaviour
{
    public GameObject bulletObject;
    public Transform bulletContainer;
    public GameObject guideLine;
    
    public float ditectionRange = 4f;


    private Camera mainCamera;
    
    //마우스의 위치에 따라서 가이드라인이 생기고 미사일이 발사
    //카메라 위에 마우스의 좌표가 어떻게 나오는지 알기 위해서
    void Start()
    {
        mainCamera = Camera.main;
        //현재 사용하고있는 카메라 객체가 들어가게됨.
    }

    void Update()
    {
        MouseCheck();
        
        if (Input.GetMouseButtonDown(0)) //마우스의 왼쪽버튼 누르면
        {
            Vector2 mousePos = Input.mousePosition;
            mousePos = mainCamera.ScreenToWorldPoint(mousePos);

            Vector3 playerPos = transform.position;
            
            Vector2 dirVec = mousePos - (Vector2)playerPos; //그냥벡터를 만듦
            dirVec = dirVec.normalized; //nomalized를 꼭 해줘야 방향벡터

            GameObject tempObject = Instantiate(bulletObject, bulletContainer);
            tempObject.transform.right = dirVec;
            //총알의 오른쪽 방향을 dirvec로 설정

            tempObject.transform.position = (Vector2)playerPos + dirVec * 0.5f;
            //총알이 플레이어보다 살짝 앞에서 발사

            transform.Translate(-dirVec);
            //dirvec의 정 반대의 벡터를 만들기 위해서 -를 곱해준다.
        }
    }

    void MouseCheck()
    {
        Vector2 mousePos = Input.mousePosition; //마우스의 위치값을 받음.
        mousePos = mainCamera.ScreenToWorldPoint(mousePos);
        //현재 마우스의 위치를 게임 내의 POSITION값으로 변환

        Vector3 playerPos = transform.position;
            
        Vector2 distanceVec = mousePos - (Vector2)playerPos;
        guideLine.SetActive(distanceVec.magnitude < ditectionRange ? true : false); //삼항연산자
        //가이드라인 활성화?
        //일정 거리 않에 들어가면 활성화한다.
        //megnitude이용하면 거리를 알 수 있다.
        //sqrmegnitude는 거리의 제곱을 알 수 있다.

        guideLine.transform.right = distanceVec.normalized;
        //가이드라인의 방향을 distancevec의 방향벡터로 설정하겠다는 뜻.
        //nomalized-> 방향벡터를 설정하는 것.
        //방향에 관련된 것은 전부 방향벡터로 설정!
    }
}
