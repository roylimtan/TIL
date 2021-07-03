using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// 4가지의 실습.
// 1. Player 이동 2. Player 이동 패턴을 원을 그리며 이동 3. 미사일 발사(순차적) 4. 미사일 발사(한번에)
public enum Pattern { One, Two };
public class PlayerController : MonoBehaviour
{
    public GameObject bulletObject;
    public Transform bulletContainer;

    public Pattern shotPattern; // 패턴을 선택할 수 있게 되어 있음
    public float moveSpeed = 2f;
    public float circleScale = 5f;
    public int angleInterval = 10;
    public int startAngle = 30;
    public int endAngle = 330;

    private int iteration = 0;
    
    private void Start()
    {
        if(shotPattern == Pattern.One)
            StartCoroutine(MakeBullet());
        else if (shotPattern == Pattern.Two)
            StartCoroutine(MakeBullet2());
    }

    private void Update()
    {
        //PlayerMove(240); //30도 방향으로 움직인다는 뜻
        //PlayerCircle();
    }

    void PlayerMove(float _angle)
    {
        if (Input.GetKey(KeyCode.Space)) //SPACE누르고 있으면 true
        {
            Vector2 direction = new Vector2(Mathf.Cos(_angle * Mathf.Deg2Rad), Mathf.Sin(_angle * Mathf.Deg2Rad));
            //deg값을 rad값으로 변경
            transform.Translate(moveSpeed * direction * Time.deltaTime);
            //time.deltatime은 프레임 간의 시간 차이로 이를 곱해야 컴퓨터 성능과 무관하게 동일한 속도로 이동 가능
        }
    }

    void PlayerCircle()
    {
        //iteration 0->360 으로 각도가 1씩 증가
        //circlescale은 원의 크기 결정
        Vector2 direction = new Vector2(Mathf.Cos(iteration * Mathf.Deg2Rad), Mathf.Sin(iteration * Mathf.Deg2Rad));
        transform.Translate(direction * (circleScale * Time.deltaTime));
        iteration++;
        if (iteration > 360) iteration -= 360;
    }

    private IEnumerator MakeBullet()
    {
        int fireAngle = 0; //초기값은 0도
        while (true)
        {
            GameObject tempObject = Instantiate(bulletObject, bulletContainer, true);
            //bulletcontainer안에 bulletobject를 생성하겠다.

            Vector2 direction = new Vector2(Mathf.Cos(fireAngle*Mathf.Deg2Rad),Mathf.Sin(fireAngle*Mathf.Deg2Rad));
            tempObject.transform.right = direction;
            //총알 오브젝트 오른쪽을 difrction방향으로 설정한다.
            tempObject.transform.position = transform.position;
            //총알 오브젝트의 위치는 플레이어의 위치로 설정

            yield return new WaitForSeconds(0.1f);
            //0.1초간 기다리고
            
            fireAngle += angleInterval;
            //발사한 각도를 설정한 값에 따라서 증가.
            if (fireAngle > 360) fireAngle -= 360;
        }
    }
    
    private IEnumerator MakeBullet2()
    {
        while (true)
        {
            //한번에 미사일 생성
            for (int fireAngle = startAngle; fireAngle < endAngle; fireAngle += angleInterval)
            {
                GameObject tempObject = Instantiate(bulletObject, bulletContainer, true);
                Vector2 direction = new Vector2(Mathf.Cos(fireAngle*Mathf.Deg2Rad),Mathf.Sin(fireAngle*Mathf.Deg2Rad));
               
                tempObject.transform.right = direction;
                tempObject.transform.position = transform.position;
            }

            yield return new WaitForSeconds(4f);
            //4초간 대기
        }
    }
}
