using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//행렬을 게임해서 적용하는 경우는
//directx나 opengl공부를 하게 돠ㅣ면 많이 사용
//유니티에서는 mesh값을 직접 바꾸지 않는 이상
//shader나 좀 더 심화된 내용을 공부 할 때 사용.
//내부적으로 transform값이 행렬을 이용해서 연산이 된다.

public class Matrix : MonoBehaviour
{
    private Matrix4x4 worldMat;
    void Start()
    {
        MakeWorldMatrix();
        //ExtractionMatrix();
    }

    void MakeWorldMatrix()
    {
        Quaternion rot = Quaternion.Euler(45, 0, 45);
        //쿼터니언
        //회전행렬을 이용함.(오일러 각-> 직관적으로 각도를 이용한 것)
        //짐벌락이라는 현상이 일어남.
        //각 회전에 대해서 서로가 종속적이여서 생기는 문제
        //짐벌락 문제 => 쿼터니언 도입

        //유니티는 내부적으로 쿼터니언 사용
        //오일러각 -> 쿼터니언으로 변환해서 사용
        //회전에 관한 것은 전부 쿼터니언을 거처서 연사을 해야함.

        Vector3 tran = new Vector3(2, 1, 5);
        Vector3 scal = new Vector3(10, 10, 10);
        worldMat = Matrix4x4.TRS(tran, rot, scal);
        //worldMat = Matrix4x4.Translate(new Vector3(2, 1, 5)) * Matrix4x4.Rotate(rot) * Matrix4x4.Scale(new Vector3(10,10,10));
        
        for (int i = 0; i < 4; i++)
        {
            Debug.Log(worldMat.GetColumn(i));
        }
    }
    private void ExtractionMatrix()
    {
        Matrix4x4 matrix = transform.localToWorldMatrix;
        //localtoworldmatrix를 저장하겠다.
        //TRS == localtoworldmatrix

        Debug.Log("=== Matrix ===");
        for (int i = 0; i < 4; i++)
        {
            Debug.Log(matrix.GetColumn(i));
        }

        //================================
        //변환행렬을 가지고 position,  rotation, scale을 알고싶을 때

        Vector3 position = matrix.GetColumn(3);
        Debug.Log("=== Position ===");
        Debug.Log(position);

        Quaternion rotation = Quaternion.LookRotation(
            matrix.GetColumn(2),
            matrix.GetColumn(1)
        );

        Debug.Log("=== Rotation ===");
        Debug.Log(rotation.eulerAngles);

        Debug.Log("=== Scale ===");
        Vector3 scale = new Vector3(
            matrix.GetColumn(0).magnitude,
            matrix.GetColumn(1).magnitude,
            matrix.GetColumn(2).magnitude
        );
        Debug.Log(scale);
    }
}
