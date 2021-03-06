using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AnimatorSC2 : MonoBehaviour
{
    /*
     add component로 Animator추가 -> animation controller추가 -> Ainmator에 Controller에 추가

    window->animation->각각의 애니메이션 만들기
    window->animator->원하는 상태에 맞게 화살표 연결 -> parameters의 프러스버튼을 통해 조건 생성

    Exit Time : 애니메이션이 얼만큼 끝나고 난 뒤에 상태 전이 할 지.
    Transition Duration : 상태 전이하는데 얼마나 걸리게 할 지.
    Interruption source : 언제 중단시킬지.
     */

    private Animator anim;

    [SerializeField] private float moveSpeed;

    // Start is called before the first frame update
    void Start()
    {
        anim = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        float _dirX = Input.GetAxisRaw("Horizontal"); //getaxisraw는 우측 좌측키에 따라서 1과 -1이 반환된다.
        float _dirZ = Input.GetAxisRaw("Vertical");

        Vector3 direction = new Vector3(_dirX, 0, _dirZ);

        anim.SetBool("Right", false);
        anim.SetBool("Left", false);
        anim.SetBool("Up", false);
        anim.SetBool("Down", false);

        if (direction != Vector3.zero)
        {
            this.transform.Translate(direction.normalized * moveSpeed *Time.deltaTime);
            //normalized를 하는 이유: 대각선의 움직임도 수평 수직 움직임과 똑같이 만들기 위해서 Normalized를한다.
            //하지 않으면 대각선 속도만 빨라진다.

            if (direction.x > 0)
                anim.SetBool("Right", true);
            else if (direction.x < 0)
                anim.SetBool("Left", true);
            else if (direction.z > 0)
                anim.SetBool("Up", true);
            else if (direction.z < 0)
                anim.SetBool("Down", true);
        }
    }
}
