using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

[System.Serializable] // Dilogue사이즈 설정하는 것이 나온다.

public class Dialogue
{
    [TextArea] //한줄이 아닌 여러줄 쓸수있게 해준다.
    public string dialogue;
    public Sprite cg;
}

public class Spriterenderer : MonoBehaviour
{
    /*
     image의 texture type을 sprite로 변경하면 sprite editer이용가능

    빈 객체 생성 -> sprite Rendererer생성 sprite안에 원하는 이미지 넣는다

    image sprite는 ui이기대문에 canvas안에 있어야한다.

    대화창 만들기
    1.canvas안에 빈 오브젝트 생성하고 sprite rendererer 생성
    2. sprite에 이미지 넣는다.
    3. order in layer의 숫자에 따라서 먼저 보이는 이미지 순서 설정
    (같을경우는 z값에 의해서 설정)
    4. text생성하고 canvas의 oreder in layer을 가장 높은수로 설정하면 가장 위에 보이게된다.
    5. 스크립트를 작성하고 새로운 canvas에 버튼을 생성하여 작성한 스크립트를 넣어준다.
     */

    [SerializeField] private SpriteRenderer sprite_standingCG;
    [SerializeField] private SpriteRenderer sprite_DialogueBox;
    [SerializeField] private Text txt_Dialogue;

    private bool isDialogue = false;

    private int count = 0;

    [SerializeField] private Dialogue[] dialogue; //대사교체가 가능하도록 배열로 생성

    public void ShowDialogue()
    {
        Onoff(true);

        count = 0;
        isDialogue = true;
        NextDialogue();
    }

    private void Onoff(bool _flag)
    {
        sprite_DialogueBox.gameObject.SetActive(_flag); // 비활성화 해놓은 것을 활성화
        sprite_standingCG.gameObject.SetActive(_flag);
        txt_Dialogue.gameObject.SetActive(_flag);
        isDialogue = _flag;
    }


    private void NextDialogue()
    {
        txt_Dialogue.text = dialogue[count].dialogue;
        sprite_standingCG.sprite = dialogue[count].cg;
        count++; 
    }

    // Update is called once per frame
    void Update()
    {
        if(isDialogue)
        {
            if(Input.GetKeyDown(KeyCode.Space))
            {
                if (count < dialogue.Length)
                    NextDialogue();
                else
                    Onoff(false);
            }
        }
       
    }
}
