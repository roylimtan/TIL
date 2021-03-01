using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rigid : MonoBehaviour
{
    private Rigidbody myRigid;
    private Vector3 rotation;

    // Start is called before the first frame update
    void Start()
    {
        myRigid = GetComponent<Rigidbody>();
        rotation = this.transform.eulerAngles;
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKey(KeyCode.W))
        {
            //myRigid.velocity = Vector3.forward;
            //myRigid.angularVelocity = -Vector3.right;

            /*
            myRigid.maxAngularVelocity = 100; //회전의 최대속도를 변경
            myRigid.angularVelocity = Vector3.right * 100;
            */

            //moveposition과 moverotation은 관성과 질량의 영향을 받지 않고 실행
            //myRigid.MovePosition(transform.forward);

            //rotation += new Vector3(90, 0, 0) * Time.deltaTime;
            //myRigid.MoveRotation(Quaternion.Euler(rotation));

            //질량과 관성의 영향을 받게하고 싶다면
            //myRigid.AddForce(Vector3.forward);

            //addtorque 회전하다가 바로 멈추는 것이 아니라 회전력이 남아있다.
            //myRigid.AddTorque(Vector3.up);

            //폭발로 인해 날라가는 효과
            myRigid.AddExplosionForce(10, this.transform.right, 10);

            //add는 물리효과와 관련이 있고 move는 물리효과 없이 강제적으로 이동시키는 것
        }

        //질량 바꾸기
        //myRigid.mass = 2f;

        //저항 바꾸기
        //myRigid.drag = 2f;

        //회전저항 바꾸기
        //myRigid.angularDrag = 2f;

        //중력을 끄기 켜기
        //myRigid.useGravity = true;
    }
}
