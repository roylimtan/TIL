using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WarriorController : MonoBehaviour
{
    private Rigidbody2D warriorRigidbody2D;

    public float jumpPower;
    public float speed;
    void Start()
    {
        warriorRigidbody2D = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        PlayerMove(); //플레이어 이동
        PlayerJump(); //플레이어 점프
    }
    
    void PlayerMove()
    {
        float  x = Input.GetAxis("Horizontal"); //x축만 받아서 사용
        transform.Translate(Vector3.right * (x * speed * Time.deltaTime));
    }

    void PlayerJump()
    {
        if(Input.GetKeyDown(KeyCode.Space))
            warriorRigidbody2D.AddForce(Vector2.up * jumpPower,ForceMode2D.Impulse);
        //힘을 위쪽방향으로 jumppower만큼 줄것인데 타입은 impulse(순간적인 힘)
    }

    private void OnCollisionEnter2D(Collision2D _col)
    {
        //태그가 그라운드가 아닐경우 사용
        if (_col.gameObject.tag != "Ground")
        {
            UpOrDown(_col);
        }
    }

    void UpOrDown(Collision2D _col)
    {
        Vector3 distVec = transform.position - _col.transform.position; 
        //warrior pos - wall pos
        //벽 -> 전사로 벡터 생성
        if (Vector3.Cross(_col.transform.right, distVec).z > 0)
        {
            //_col.transform.right는 충돌체의 오른쪽 방향벡터
            //반시계방향 -> 엄지의 방향(화면에서 밖으로 나옴) -> 양수 -> 벽의 위에 부딪힘
            //시계방향 -> 엄지의 방향(화면으로 들어간다) -> 음수 -> 벽의 아래에 부딪힘
            Debug.Log("Up");
            return;
        }
        Debug.Log("Down");
    }
 
}
