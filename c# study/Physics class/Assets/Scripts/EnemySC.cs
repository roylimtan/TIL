using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//움직이는 PLAYER에게 총알이 나가게하는 SC
public class EnemySC : MonoBehaviour
{
    private float createTime = 1f;
    private float currentCreateTime;

    [SerializeField] GameObject go_BulletPrefab;

    // Update is called once per frame
    void Update()
    {
        Collider[] col = Physics.OverlapSphere(transform.position, 5f);
            //특정 모양으로 영역을 생성하고 그 영역 안에있는 collider를 배열에 담는다. 

        if(col.Length > 0)
        {
            for(int i = 0; i < col.Length; i++)
            {
                Transform tf_Target = col[i].transform;

                if(tf_Target.tag == "Player")
                { 
                    Quaternion rotation = Quaternion.LookRotation(tf_Target.position - this.transform.position);
                    transform.rotation = rotation;

                    currentCreateTime += Time.deltaTime;

                    if(currentCreateTime >= createTime)
                    {
                        GameObject _temp = Instantiate(go_BulletPrefab, transform.position, rotation);
                        currentCreateTime = 0;

                        //서로의 콜라이더가 무시되어진다.
                        //Physics.IgnoreCollision(_temp.GetComponent<Collider>(), tf_Target.GetComponent<Collider>());
                    }
                }
            }
        }
    }
}
