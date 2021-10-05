#include <string>
#include <iostream>

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

	int check_column(Number next_number)
	{
		for (int y = 0; y < size; ++y)
		{
			if (field[next_number.posX][y] == next_number.value)
				return (1);
		}
		return (0);
	}

	int check_column(Number next_number)
	{
		for (int y = 0; y < size; ++y)
		{
			if (field[next_number.posX][y] == next_number.value)
				return (1);
		}
		return (0);
	}

	int check_row(Number next_number)
	{
		for (auto & x : field)
		{
			if (x[next_number.posY] == next_number.value)
				return (1);
		}
		return (0);
	}



	int insert(Number next_number)
	{
		check_row(next_number);
	}


	int fill_field()
	{
		for (int y = 0; y < size; ++y)
		{
			for (int x = 0; x < size; ++x)
			{
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
