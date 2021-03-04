using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AnimatorSC : MonoBehaviour
{
    //window -> animation -> animation -> create -> 빨간색 버튼
    //맨 오른쪽 방패모양 : 이벤트 추가 ex)특정프레임이 실행됨과 동시에 체력을 +10 채워주는 함수 호출
    //culling type : absed on lenderer는 카메라에 보이지 않으면 실행하지 않는다.

    //animation설정
    //pingpong : 마지막으로 가면 처음으로 자동 이동
    //clamp forever : 마지막 프레임에 멈춘 상태로 유지

    private Animation anim;

    // Start is called before the first frame update
    void Start()
    {
        anim = GetComponent<Animation>();
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.W))
        {
           anim.Play("Cube_2");
            /*
           anim.PlayQueued("cube_2"); // 실행중이던 애니메이터가 끝나고 실행
          
           anim.Blend("Cube_2"); //실행중이던 애니메이터와 함께 실행
           anim.CrossFade("cube_2"); //자연스럽게 애니메이터가 바뀐다.
           
            if(!anim.IsPlaying("cube_2"))
                anim.Play("cube_2"); //cube_2가 실행중이 아니면 실행해라

           anim.Stop(); //실행중이던 애니메이터가 멈춘다
            */
        }
    }
}
