using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Collider : MonoBehaviour
{
    private BoxCollider col; //collider를 조정할 수 있는 변수 선언

    // Start is called before the first frame update
    void Start()
    {
        col = GetComponent<BoxCollider>(); //col이라는 변수로 큐브의 boxcollider통제 가능
    }

    
    //들어올때 최초 1회 실행
    private void OnTriggerEnter(UnityEngine.Collider other) //is trigger가 체크된 상태에서 다른 컬라이더가 들어오면 실행 
    {
        
    }

    //나갈때 최초 1회 실행
    private void OnTriggerExit(UnityEngine.Collider other)
    {
        other.transform.position = new Vector3(0, -2, 0);
    }
    

    //머물때 실행
    private void OnTriggerStay(UnityEngine.Collider other)
    {
        other.transform.position += new Vector3(0, 0, 0.1f);
    }

    //is trigger가 체크된게 아니라 실제 물리적 충돌이 일어났을 때 호출되는 함수
    private void OnCollisionEnter(Collision collision)
    {
        
    }


    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.W))
        {
            //기본적인 속성
            Debug.Log("col.bounds =" + col.bounds);
            Debug.Log("col.bounds.extents =" + col.bounds.extents);
            Debug.Log("col.bounds.extents.x =" + col.bounds.extents.x);
            Debug.Log("col.size =" + col.size);
            Debug.Log("col.center = " + col.center); 
        }

        //컬러이더의 매서드
        if (Input.GetMouseButtonDown(0)) //down은 한번 클릭할때 만 발동 0은 좌버튼
        {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hitinfo;
            if(col.Raycast(ray, out hitinfo, 1000))
            {
                this.transform.position = hitinfo.point;
            }

        }
    }
    
}
