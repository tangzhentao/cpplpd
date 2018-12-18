/*
 * 使用优先级队列模拟细胞分裂
 */
#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SPLITE_TIME_MIN = 500;
const int SPLITE_TIME_MAN = 2000;

class Cell;
priority_queue<Cell> cellQueue;

class Cell
{
public:
	Cell(int birth): _id(count++) // birth是出生日期
	{
		// 细胞一出生，就确定细胞分裂的时间
		_splitTime = birth + (rand() % (SPLITE_TIME_MAN - SPLITE_TIME_MIN) ) + SPLITE_TIME_MIN;
	}

	int getId() const {return _id;}
	int getSplitTime() const {return _splitTime; }
	bool operator < (const Cell &c) const { return _splitTime > c._splitTime; }

	// 细胞分裂
	void split () const
	{
		Cell child1(_splitTime), child2(_splitTime);
		cout << _splitTime << "s: Cell #" << _id << " split to #"
			<< child1.getId() << " and #"
			<< child2.getId() << endl;

		cellQueue.push(child1);
		cellQueue.push(child2);
	}

private:
	int _id;
	int _splitTime; // 将要分裂的时间

private:
	static int count;
};

int Cell::count = 0;

int main()
{
	srand(static_cast<int>( time(0) ) );
	int t; // 时间期限
	cin >> t;
	cellQueue.push(Cell(0)); // 第一个细胞

	while(cellQueue.top().getSplitTime() <= t)
	{
		cellQueue.top().split(); // 模拟细胞分裂
		cellQueue.pop(); // 弹出刚刚分裂的细胞
	}

	return 0;
}
