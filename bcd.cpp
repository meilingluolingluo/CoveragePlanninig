#include <iostream>
#include <vector>

struct Point
{
    int x;
    int y;
};

void boustrophedonTraversal(const int &x, const int &y,const int& size)
{

    std::vector<Point> path;
    // 记录起点坐标
    path.push_back({0, 0});
    bool moveRight = true;

    if (x >= y)
    {
        for (int row = 0; row <= y; row+=size)
        {
            if (moveRight)
            {
                for (int col = 0 + 1; col <= x; col+=size)
                {
                    path.push_back({col, row});
                }
            }
            else
            {
                for (int col = x; col >= 0 + 1; col-=size)
                {
                    path.push_back({col, row});
                }
            }
            // 改变方向
            moveRight = !moveRight;
        }
        }
        else
        {
            for (int col = 0; col <= x; col+=size)
            {
                if (moveRight)
                {
                    for (int row = 0 + 1; row <= y; row+=size)
                    {
                        path.push_back({col, row});
                    }
                }
                else
                {
                    for (int row = y; row >= 0 + 1; row-=size)
                    {
                        path.push_back({col, row});
                    }
                }
                // 改变方向
                moveRight = !moveRight;
            }
        }

        // 输出遍历路径坐标
        for (const auto &point : path)
        {
            std::cout << "(" << point.x << ", " << point.y << ") ";
        }
        std::cout << std::endl;
    }

    int main()
    {

        int x, y,size;
        x = 8;//长度
        y = 10;//宽度
        size = 1;//步长

        boustrophedonTraversal(x, y,size);

        return 0;
    }
