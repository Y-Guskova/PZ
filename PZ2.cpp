#include <iostream>

using namespace std;
template <typename A>
class Arr
{
private:
	int size = 0;
	A* p_Arr = nullptr;
	bool initialized = false;
public:
	Arr() {};

	Arr(int size)
	{
		this->size = size;
		p_Arr = new A[size];
		for (int i = 0; i < size; i++)
		{
			p_Arr[i] = i;
		}

		initialized = true;
	}

	Arr(const Arr& copmas)
	{
		if (copmas.initialized)
		{
			this->size = copmas.size;
			p_Arr = new A[size];
			for (int i = 0; i < size; i++)
			{
				this->p_Arr[i] = copmas.p_Arr[i];
			}
			this->initialized = true;
		}
		else
		{
			cout << "Error" << endl;
		}
	}

	friend Arr operator  + (const Arr& a, const Arr& b)
	{
		Arr temp;

		if (a.size < b.size)
		{
			temp.init(a.size);
			for (int i = 0; i < a.size; i++)
			{
				temp.p_Arr[i] = a.p_Arr[i] + b.p_Arr[i];
			}
		}

		else
		{
			temp.init(b.size);
			for (int i = 0; i < a.size; i++)
			{
				temp.p_Arr[i] = a.p_Arr[i] + b.p_Arr[i];
			}
		}

		return temp;
	}

	void operator = (const Arr& a)
	{
		if (a.initialized)
		{
			this->size = a.size;
			p_Arr = new A[size];
			for (int i = 0; i < size; i++)
			{
				this->p_Arr[i] = a.p_Arr[i];
			}
			this->initialized = true;
		}
		else
		{
			cout << "Error" << endl;
		}
	}


	~Arr()
	{
		delete[] p_Arr;
	}


	void init(int size)
	{
		this->size = size;
		p_Arr = new A[size];
		for (int i = 0; i < size; i++)
		{
			p_Arr[i] = 0;
		}
		initialized = true;
	}



	void SetArr(int index, A val)
	{
		if (val < -100 || val > 100)
		{
			throw std::invalid_argument("Error");
		}
		if (index < 0 || index >= size)
		{
			throw std::out_of_range("Error");
		}
		p_Arr[index] = val;
	}

	int GetArr(int index)
	{
		if (index < 0 || index >= size)
		{
			throw std::out_of_range("Error");
		}
		return p_Arr[index];
	}

	void show()
	{
		for (int i = 1; i <= size; i++)
		{
			cout << i << "	" << p_Arr[i - 1] << endl;
		}
	}

	void add(Arr& oper)
	{
		if (size < oper.size)
		{
			for (int i = 0; i < size; i++)
			{
				p_Arr[i] += oper.GetArr(i);
			}
		}

		else
		{
			for (int i = 0; i < oper.size; i++)
			{
				p_Arr[i] += oper.GetArr(i);
			}
		}
	}

	void sub(Arr& oper)
	{
		if (size < oper.size)
		{
			for (int i = 0; i < size; i++)
			{
				p_Arr[i] -= oper.GetArr(i);
			}
		}

		else
		{
			for (int i = 0; i < oper.size; i++)
			{
				p_Arr[i] -= oper.GetArr(i);
			}
		}
	}
}


