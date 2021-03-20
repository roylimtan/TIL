using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//player를 바라보고 총알이 나가게하는 SC

public class PhysicsSC : MonoBehaviour
{

    /*
     만든 player의 태그를 Player로 바꿔주고 rigidbody를 추가해준다.
     */

    [SerializeField] private LayerMask layerMask;
    [SerializeField] private GameObject go_BulletPrefab; //prefab한 총알을 불러오는 기능

    private float createTime = 1f;
    private float currentCreateTime = 0;

    // Update is called once per frame
    void Update()
    {
        currentCreateTime += Time.deltaTime;
        if(currentCreateTime >= createTime) //1초에 한발씩 나가게 해준다.
        {
            currentCreateTime = 0f;

            RaycastHit hitInfo;

            //enemy캡슐이 player캡슐을 바라보고있는지 Z축에 레이저를 쏴서 확인
            if (Physics.Raycast(this.transform.position, this.transform.forward, out hitInfo, 10f, layerMask)) //특정 레이어만 충돌하게 한다.
            {
                if (hitInfo.transform.tag == "Player")
                {
                    Instantiate(go_BulletPrefab, transform.position, Quaternion.LookRotation(hitInfo.transform.position - transform.position)); //prefab을 생성시켜주는 명령어
                }
            }
        }
    }
}
