#pragma once

//方向枚举 UP上  DOWN下 LEFT左 RIGHT右
enum class DIR
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
//坐标类
class Point
{
public:
	Point();
	Point(int x, int y);
	~Point();
	bool operator==(const Point& target) const;
	bool equals(const Point& target) const;
	void setPosition(int x, int y);
public:
	void move(DIR dir,int speed);
public:
	int m_x;
	int m_y;
};

/****************Size*********************/
class Size
{
public:
	Size();
	Size(int width, int height);
	~Size();
	void setSize(int width, int height);
	bool equals(const Size& target) const;

private:
	int width;
	int height;
};
