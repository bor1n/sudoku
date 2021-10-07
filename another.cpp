#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

class Number
{


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

class Sudoku
{
public:
	static int const size = 9;
	int field[size][size]{};

	Sudoku()
	{
		for (auto &i : field)
		{
			for (int &j : i)
			{
				j = 0;
			}
		}
	}

	void refill_pool(vector<int> *pool, int x, int y)
	{
		pool->clear();
		for (int i = 1; i <= size; ++i)
			pool->push_back(i);
		for (int i = 0; i < size; ++i)
		{
			if (find(pool->begin(), pool->end(), field[i][y]) != pool->end())
				//vec.erase(std::remove(vec.begin(), vec.end(), 8), vec.end());
				pool->erase(remove(pool->begin(), pool->end(), field[i][y]), pool->end());
			if (find(pool->begin(), pool->end(), field[x][i]) != pool->end())
				pool->erase(remove(pool->begin(), pool->end(), field[x][i]), pool->end());
		}
		int index_x = (x / 3) * 3;
		int index_y = (y / 3) * 3;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (find(pool->begin(), pool->end(), field[i + index_x][j + index_y]) != pool->end())
					pool->erase(remove(pool->begin(), pool->end(), field[i + index_x][j + index_y]), pool->end());
			}

		}
		if (pool->empty())
			throw "go back";


	}

	int get_random_value(vector<int> pool)
	{
		// logic
		int idx = rand() % pool.size();
		auto it = pool.begin();
		for (int i = 0; i < idx; i++)
		{
			it++;
		}
		return *it;
	}

	int insert(Number next_number)
	{
		field[next_number.posX][next_number.posY] = next_number.value;
		return (0);
	}


	int fill_field()
	{
		srand(time(NULL));
		int stepback = 2;
		vector<int> pool;
		for (int y = 0; y < size; ++y)
		{
			for (int x = 0; x < size; ++x)
			{
				try
				{
					this->refill_pool(&pool, x, y);
				} catch (const char *err)
				{
					if (x > 0)
					{
						field[x - 1][y] = 0;
						x -= stepback;
						stepback++;
						srand(time(NULL));
						continue;
					}
					else if (x == 0)
					{
						for (auto &i : field)
						{
							i[y - 1] = 0;
						}
						y -= stepback;
						stepback++;
						srand(time(NULL));
						break;
					}


				}

				int next_value = this->get_random_value(pool);
				Number next_number(next_value, x, y);

				insert(next_number);
			}
		}
		return (0);
	}
	void print_field()
	{
		for (auto & i : field)
		{
			for (int j : i)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	Sudoku sudoku;
	try
	{
		sudoku.fill_field();
		sudoku.print_field();
	} catch (const char* err)
	{
		sudoku.print_field();
	}
}
