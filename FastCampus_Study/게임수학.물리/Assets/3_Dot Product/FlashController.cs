using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Vector2 = System.Numerics.Vector2;

public class FlashController : MonoBehaviour
{
    public GameObject[] ghostObjectArray;

    public float moveSpeed = 3f;
    public float rangeAngle = 25f;
    public float rangeDistance = 4f;
    void Update()
    {
        PlayerMove();
        CheckGhost();
    }

    void PlayerMove()
    {
        float x = Input.GetAxis("Horizontal");
        float y = Input.GetAxis("Vertical");
        //GetAxis-> 조이스틱 컨트롤러를 만들 수 있다.
        //horizontal x축, vertical y축

        transform.Translate(new Vector3(x,y) * (moveSpeed * Time.deltaTime));
    }

    void CheckGhost()
    {
        int i = 0; //유령수의 초기값은 0
        foreach (var ghost in ghostObjectArray) //foreach를 이용하여 각 오브젝트를 전부 체크
        {
            Vector3 distanceVec = ghost.transform.position - transform.position;
            if (distanceVec.magnitude < rangeDistance)
            {
                Vector3 dirVec = distanceVec.normalized; //내적을 하기 위해서 무조건 방향벡터로 만들어줌.
                
                if(Vector3.Dot(transform.up, dirVec) > Mathf.Cos(rangeAngle*Mathf.Deg2Rad))
                    i++;
                //transform.right/up  vector.right,left,up,down 전부 방향벡터(크기가 1)
            }
        }
        
        Debug.Log("감지된 유령의 수: "+i);
    }
}
