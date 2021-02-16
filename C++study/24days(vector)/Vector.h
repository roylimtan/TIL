#pragma once

template <typename T>
class CVectorNode
{
private:
	CVectorNode()
	{

	}

	~CVectorNode()
	{

	}

private:
	template<typename T>
	friend class CVector;

private:
	T m_Data;
	int m_iIndex;
};

template <typename T>
class CVector
{
public:
	CVector()
	{
		m_iSize = 0;
		m_iCapasity = 2;

		m_pArray = new NODE[m_iCapasity + 2];
	}

	CVector(int iSize)
	{
		m_pArray = new NODE[iSize + 2];
		m_iCapasity = iSize;
		m_iSize = 0;
	}

	~CVector()
	{
		delete[] m_pArray;
	}

private:
	typedef CVectorNode<T> NODE;
	typedef CVectorNode<T>* PNODE;

private:
	PNODE m_pArray;
	unsigned int m_iSize;
	unsigned int m_iCapasity;

public:
	void push_back(const T& data)
	{
		if (full())
			resize(m_iSize * 2);

		m_pArray[m_iSize + 1].m_Data = data;
		//0번은 begin이다. 그런데 실제 1번인덱스부터 노드가 추가되는데 처음 추가된 노드는 0번부터 인덱스를 주도록 한다.
		m_pArray[m_iSize + 1].m_iIndex = m_iSize;
		++m_iSize;
	}

	void resize(int size)
	{
		//+2를 해주는 이유는 begin과 end노드를 포함시켜서 생성하기 위해서이다.
		PNODE pArray = new NODE[size + 2];

		//위에서 두배만큼 공간을 새로 할당하고 기존에 있는 노드의 데이터를 새로 할당한 공간에 복사해준다.
		//a메모리 주소에 +1을 해주는 이유는 1번 인덱스부터 시작이기 때문에 여기부터 복사를 해주기 위해서 +1을 해준다.
		memcpy(pArray + 1, m_pArray + 1, sizeof(NODE) * m_iSize);

		//기존 노드를 삭제한다.
		delete[] m_pArray;

		m_pArray = pArray;

		m_iCapasity = size;
	}

	void clear()
	{
		delete[] m_pArray;
		m_iSize = 0;
		m_iCapasity = 2;
		m_pArray = new NODE[m_iCapasity + 2];
	}

	bool full()
	{
		return m_iSize == m_iCapasity;
	}

	bool empty()
	{
		return m_iSize;
	}

	unsigned int size() const
	{
		return m_iSize;
	}

	unsigned int capasity() const
	{
		return m_iCapasity;
	}

	T operator [](int idx)
	{
		return m_pArray[idx + 1].m_Data;
	}

	void reserve(int iSize)
	{
		delete[] m_pArray;
		m_pArray = new NODE[iSize + 2];

		m_iCapasity = iSize;
		m_iSize = 0;
	}
};

