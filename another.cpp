#include <string>
#include <iostream>
#include <list>

using namespace std;

class Number{


public:
	Number(int _value, int _posX, int _posY)
	{
		value = _value;
		posX = _posX;
		posY = _posY;
	}

	int value;
	int posX;
	int posY;
};

class Sudoku{
	static int const size = 10;
	int field[size][size]{};

	Sudoku(){
		for (auto & i : field)
		{
			for (int &j : i)
			{
				j = 0;
			}
		}
	}

	static void refill_pool(list<int> pool)
	{
		for (int i = 1; i < size; ++i)
			pool.push_back(i);
	}

	int insert(Number next_number)
	{

	}


	int fill_field()
	{
		for (int y = 0; y < size; ++y)
		{
			list<int> pool;
			for (int x = 0; x < size; ++x)
			{
				refill_pool(pool);
				int next_value = (rand() % 9) + 1;
				Number next_number(next_value, x, y);

				insert(next_number);
			}
		}
	}
};

int main()
{
	Sudoku sudoku();
}
