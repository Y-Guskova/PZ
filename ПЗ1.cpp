#include <iostream>
using namespace std;

class Arr
{
private:
	int size;
	int* p_Arr;
public:
	DArr(int size) 
	{
		this->size = size;
		p_Arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			p_Arr[i] = 0;
		}
	}

	Arr(Arr& copmas)
	{

		this->size = copmas.size;
		p_Arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			p_Arr[i] = copmas.GetArr(i);
		}
	}

	~Arr()
	{
		delete [] p_Arr;
	}

	void SetArr(int num, int val) 
	{
		if (num >= 0 && num < size && val > -100 && val < 100) {
			p_Arr[num] = val;
		}
		else
		{
			cout << "Error with setting" << endl;
		}
		
	}

	int GetArr(int num)
	{
		return p_Arr[num];
	}

	void show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << i << "	" << p_Arr[i] << endl;
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
};

int main()
{
	return 0;
}
