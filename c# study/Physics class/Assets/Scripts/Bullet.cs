using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/*
 만든 총알에 스크립트를 넣고 프리팹해준다.
 */

public class Bullet : MonoBehaviour
{
    [SerializeField] private float speed;
    [SerializeField] private float damage;

    // Update is called once per frame
    void Update()
    {
        transform.position += transform.forward * speed * Time.deltaTime;
    }

    private void OnTriggerEnter(Collider other) //만든 bullet의 is trigger체크
    {
        Debug.Log(other.transform.name + "에게 데미지" + damage + "을 입혔습니다.");
        Destroy(this.gameObject);
    }
}
