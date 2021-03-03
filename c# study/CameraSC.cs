using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/*
 Clear Flags : 여백을 어떻게 설정할지 결정
 Projection : 원근감 설정
 Viewport Rect : 카메라를 복사하여 미니맵 만들기에 사용
 HDR : 조명효과
 MSAA : 계단현상 제거
 Dynamic Resol : 끄면 GPU의 부하를 줄여진다.
*/

public class CameraSC : MonoBehaviour
{
    [SerializeField]
    private GameObject go_Target;

    [SerializeField]
    private float speed;

    private Vector3 difValue;

    private Camera theCam;

    // Start is called before the first frame update
    void Start()
    {
        //theCam.fieldOfView = 50;  카메라 시점 변환
        //theCam.clearFlags skybox나 다른 걸로 변환 가능
        difValue = transform.position - go_Target.transform.position;
        difValue = new Vector3(Mathf.Abs(difValue.x), Mathf.Abs(difValue.y), Mathf.Abs(difValue.z));
    }

    // Update is called once per frame
    void Update()
    {
        this.transform.position = Vector3.Lerp(this.transform.position, go_Target.transform.position + difValue, speed);
        //Lerp를 이용하면 카메라의 부드러운 움직임을 구현할 수 있다.
    }
}
