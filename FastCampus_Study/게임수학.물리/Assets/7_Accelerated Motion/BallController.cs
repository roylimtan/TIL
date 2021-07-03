using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BallController : MonoBehaviour
{
    public float shotVelocity;
    public float shotAngle;

    private Rigidbody2D ballRB2D;
    private bool isGround = true;
    private bool isCenter = false;
    private float totalTime = 0f;

    void Start()
    {
        ballRB2D = GetComponent<Rigidbody2D>();
    }
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            StartCoroutine(ShotBall());
        }
    }
    IEnumerator ShotBall()
    {
        Debug.Log("=== Simulation ===");

        isGround = false;
        transform.right = new Vector2(Mathf.Cos(shotAngle * Mathf.Deg2Rad), Mathf.Sin(shotAngle * Mathf.Deg2Rad));
        //공의 각도 설정
        ballRB2D.velocity = transform.right * shotVelocity;
        //설정된 각도로 shotvelocity속도로 발사하겠다.

        totalTime = 0f; //처음 시간은 0으로 초기화
        while (true)
        {
            yield return null;
            if (isGround) break; //착지를 하면 while문이 끝남
            totalTime += Time.deltaTime; //착지를 하기 전까지 시간을 더해줌
            if (Mathf.Abs(ballRB2D.velocity.y) < 0.1f && !isCenter)
            {
                //y축의 속도의 절대값이 0.1보다 작을 때, iscenter false일때(딱 1번만 발동)
                isCenter = true;
                Debug.Log("CenterHeight: " + transform.position.y); //최고높이
            }
        }
    }
    private void OnCollisionEnter2D(Collision2D _col)
    {
        if(isGround == false) //그라운드에 착지
        {
            isGround = true;
            ballRB2D.velocity = Vector2.zero; //속도는 0(더이상 움직이지 않게 하기 위해)
            Debug.Log("Totaltime: " + totalTime); //총 걸린 시간
            Debug.Log("TotalMeter: " + (transform.position.x + 8)); //초기 위치가 -8에서 시작했기때문

            Verification();
        }
    }

    private void Verification()
    {
        Debug.Log("=== Verification ===");

        float totalTime = 2 * shotVelocity * Mathf.Sin(shotAngle * Mathf.Deg2Rad) / 9.81f;
        //총 걸린 시간은 2t
        //2*v*sin(theta)/g
        float centerHeight = Mathf.Pow(shotVelocity * Mathf.Sin(shotAngle * Mathf.Deg2Rad), 2) / (2*9.81f); // (V*sin(theta))^2 / 2g
        float totalMeter = Mathf.Pow(shotVelocity,2) / 9.81f * Mathf.Sin(2 * shotAngle * Mathf.Deg2Rad); // v^2/g*sin(2*theta)

        Debug.Log("Totaltime: " + totalTime);
        Debug.Log("CenterHeight: " + centerHeight);
        Debug.Log("TotalMeter: " + totalMeter);
    }
}
