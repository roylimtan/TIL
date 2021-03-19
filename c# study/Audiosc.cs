using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Audiosc : MonoBehaviour
{

    /*
     빈 오브젝트 생성 -> audio source추가
     play on awake : 시작하자마자 소리나게 한다.
    stereo pan : 스피커에서 소리가 나는 방향 설정
     */

    private AudioSource theAudio;

    [SerializeField] private AudioClip[] clip;

    // Start is called before the first frame update
    void Start()
    {
        theAudio = GetComponent<AudioSource>(); //시작하자마자 오디오를 찾게해준다.
    }

   public void PlaySE() //버튼을 클릭하면 실행하는 함수
    {
        int _temp = Random.Range(0, 4); //int이므로 4는 포함안됨, float일경우 4도 포함

        theAudio.clip = clip[_temp];
        theAudio.Play();
    }

    //canvas에 버튼을 생성하고 버튼에서 이 함수를 사용할수있도록 함수를 넣어준
    //gameobject를 넣어주고 함수를 선택해준다.
}
