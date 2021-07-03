using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ForceController : MonoBehaviour
{
    private Rigidbody boxRigidbody;
    private float movePower = 5f;
    void Start()
    {
        boxRigidbody = GetComponent<Rigidbody>();
    }
    private void FixedUpdate()
    {
        //impulse는 1초동안 가해진 힘의 합

        //Debug.Log(boxRigidbody2D.velocity);
        if (Input.GetKeyDown(KeyCode.A))
            boxRigidbody.AddForce(transform.right * movePower, ForceMode.Impulse);
        //boxRigidbody.AddForce(transform.right * movePower / Time.fixedDeltaTime, ForceMode.Impulse);

        else if (Input.GetKey(KeyCode.S))
            boxRigidbody.AddForce(transform.right * movePower, ForceMode.Force);
        //impulse와 force는 전부 질량에 영향을 받는다. f = ma
        //impulse는 게임에서 순간적인 힘을 가할때
        //force는 게임에서 지속적인 힘을 가할때.

        else if (Input.GetKeyDown(KeyCode.D))
            boxRigidbody.AddForce(transform.right * movePower, ForceMode.VelocityChange);
        //boxRigidbody.AddForce(transform.right * movePower / Time.fixedDeltaTime, ForceMode.Acceleration);
        //가속도가 쌓이면 속도의 변화가 된다.

        else if (Input.GetKey(KeyCode.F))
            boxRigidbody.AddForce(transform.right * movePower, ForceMode.Acceleration);
        //velocitychange와ㅓ acceleration은 질량과 무관하게 힘을 가한다.
    }
}
