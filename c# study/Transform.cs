using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Transform : MonoBehaviour
{
    [SerializeField] //private을 하면 스크립트 내에서만 사용 가능하지만 인스펙터창에 뜨지 않는다 이를 해결하기 위해 이 문장 사용
    private GameObject go_camera;

    Vector3 rotation;

    void Strat()
    {
        rotation = this.transform.eulerAngles;
    }
    

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKey(KeyCode.W))
        {
            //this는 스크립트가 있는 게임 오브젝트를 의미한다.
            // 포지션 값 직접 수정하는 코드
            //this.transform.position = this.transform.position + new Vector3(0, 0, 1) * Time.deltaTime; 
            //Time.deltatime 은 한 프레임 실행하는데 걸리는 시간 약60분의1

            //직접 이동 시키는 코드
            this.transform.Translate(new Vector3(0, 0, 1) * Time.deltaTime);
        }

        if(Input.GetKey(KeyCode.E))
        {
            /*
            rotation = rotation + new Vector3(90, 0, 0) * Time.deltaTime;
            this.transform.eulerAngles = rotation;
            Debug.Log(transform.eulerAngles);
            */

            //매서드 이용 방법
            //this.transform.Rotate(new Vector3(90, 0, 0) * Time.deltaTime);


            //Quaternion 사용 이유는 한 축을 고정해놨을 때 다른 축이 고정되는 것을 막기 위해서
            //즉, 짐블락을 막기 위해서
            rotation = rotation + new Vector3(90, 0, 0) * Time.deltaTime;
            this.transform.rotation = Quaternion.Euler(rotation);
        }

        if(Input.GetKey(KeyCode.R))
        {
            this.transform.localScale = this.transform.localScale + new Vector3(2, 2, 2) * Time.deltaTime;
        }

        //정규화 벡터(방향만을 알려주는 녀석) right(1,0,0), up(0,1,0), forward(0,0,1)
        //this.transform.right * Time.deltaTime;

        //카메라를 바라보는 기능
        //this.transform.LookAt(go_camera.transform.position);

        //주변을 공전하는 기능
        transform.RotateAround(go_camera.transform.position, Vector3.up, 100 * Time.deltaTime);
    }
}
