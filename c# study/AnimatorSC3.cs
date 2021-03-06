using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AnimatorSC3 : MonoBehaviour
{
    /*
     blend tree만들기
    Animator에 새로운 blend tree 생성 -> 들어감 -> blend type변경 -> parameters 설정
    -> 만든 애니메이션 넣고 값 입력

    creat sub state machine으로 생성 -> 복잡한 애니메이터들을 넣어서 깔끔하게 정리

    trigger는 그냥 실행되는 것
     */

    private Animator anim;
    private Rigidbody rigid;
    private BoxCollider col;

    [SerializeField] private float moveSpeed;
    [SerializeField] private float jumpForce;
    [SerializeField] private LayerMask layerMask;

    private bool isMove;
    private bool isJump;
    private bool isFall;

    // Start is called before the first frame update
    void Start()
    {
        anim = GetComponent<Animator>();
        rigid = GetComponent<Rigidbody>();
        col = GetComponent<BoxCollider>();
    }

    // Update is called once per frame
    void Update()
    {

        TryWalk();
        TryJump();

    }

    private void TryJump()
    {
        if(isJump)
        {
            if(rigid.velocity.y <= -0.1f && !isFall)
            {
                isFall = true;
                anim.SetTrigger("Fall");
            }

            RaycastHit hitInfo;
            if (Physics.Raycast(transform.position, -transform.up, out hitInfo, col.bounds.extents.y + 0.1f, layerMask))
            {
                anim.SetTrigger("Land");
                isJump = false;
                isFall = false;
            }
           
        }

        if(Input.GetKeyDown(KeyCode.Space) && !isJump)
        {
            isJump = true;
            rigid.AddForce(Vector3.up * jumpForce);
            anim.SetTrigger("Jump");
        }
    }

    private void TryWalk()
    {
        float _dirX = Input.GetAxisRaw("Horizontal");
        float _dirZ = Input.GetAxisRaw("Vertical");

        Vector3 direction = new Vector3(_dirX, 0, _dirZ);
        isMove = false;

        if (direction != Vector3.zero)
        {
            isMove = true;
            this.transform.Translate(direction.normalized * moveSpeed * Time.deltaTime);
        }

        anim.SetBool("Move", isMove);
        anim.SetFloat("DirX", direction.x);
        anim.SetFloat("DirZ", direction.z);

    }
}
