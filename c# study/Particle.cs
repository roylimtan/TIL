using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Particle : MonoBehaviour
{

    /*
    Looping : 계속 재생
    Prewarm : 처음부터 재생이 아닌 재생되고 있던것처럼 재생
    Start Lifetime : 살아있는 시간

    Emossion 
    Rate over Distance : 움직이는 속도에 따라서 나오는 입자의 개수 지정

    Shape : 입자들이 나오는 모양 설정

    Velocity over Lifetime : 입자들의 궤도방향 설정

    Color over Lifetime : 입자의 색 바뀌는것 설정

    Size over Lifetime : 입자들의 크기 바뀌는것 설정

    Collision : 충돌 가능하게 설정

    Triggers : 이벤트 설정

    Sub Emitters : emission에서 bursts를 생성하고 넣어주면 완료
    (비가 땅에 떨어졌을때 사라지면서 주변에 퍼지는 효과를 만들때 사용)
    (미사일이 폭발하거나 그 잔해가 다른곳에 날라가서 폭발되는 효과에도 사용)

    Texture Sheet Animation : 입자들의 이미지 설정 가능

    Lights : light를 하나 만들어주고 넣어준다. 입자들이 빛을 발산하는 기능
    (모닥불이 빛을 발산하는 효과에 사용)

    Trails : 입자들의 자국 설정(총알 궤적)

    Render
    render mode
    stretched : 입자들이 찢어져서 나온다.
    horizontal : 눕혀져서 나온다.
    vertical : 새로로 나온다.
    mesh : 설정한 모양에 맞게 나온다.

    sorting Lyer : 우선순위 설정 가능


     */

    ParticleSystem ps;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        // ps.Play(); 파티클효과 실행
        //ps.Emit(개수); 설정한 개수의 입자가 나온다.
    }
}
