using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/*
 Type : 여러가지 형태로 빛 변경
 Mode : realtime(매 프레임마다 계산, 즉 과부하 가능성 높음)
 Strength : 그림자의 세기
 Resolution : 그림자의 퀄리티
 Cookie : 빛을 방해할 녀석
 Draw Halo : 후광효과 (type이 point일때 사용)
 Flare : 카메라에 플레어효과가 생긴다
 
 */

public class LightSC : MonoBehaviour
{
    private Light theLight;

    private float targetIntensity;
    private float currentIntensity;

    // Start is called before the first frame update
    void Start()
    {
        theLight = GetComponent<Light>();
        currentIntensity = theLight.intensity;
        targetIntensity = Random.Range(0.4f, 1f);
    }

    // Update is called once per frame
    void Update()
    {
        if(Mathf.Abs(targetIntensity - currentIntensity) >= 0.01f)
        {
            if (targetIntensity - currentIntensity >= 0)
                currentIntensity += Time.deltaTime * 3f;

            else
                currentIntensity -= Time.deltaTime * 3f;

            theLight.intensity = currentIntensity;
            theLight.range = currentIntensity + 10;
             
        }

        else
        {
            targetIntensity = Random.Range(0.4f, 1f);
        }
    }
}
