#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct point
{
    double x;
    double y;
};

vector<point> boustrophedon_decomposition(double start_x, double start_y, double end_x, double end_y, double step_size)
{
    vector<point> path;

    double min_x = min(start_x, end_x);
    double max_x = max(start_x, end_x);
    double min_y = min(start_y, end_y);
    double max_y = max(start_y, end_y);
    int rows = (max_y - min_y) / step_size; // 计算区域分成几行
    int cols = (max_x - min_x) / step_size; // 计算区域分成几列
    cout << "行：" << rows << "列:" << cols << endl;

    if ((start_x <= end_x) && (start_y <= end_y))
    {
        if (rows <= cols)
        { // 如果x大于y
            for (int i = 0; i < rows; i++)
            {

                if (i % 2 == 0)
                { // 如果是偶数行，则从左往右走

                    for (int j = 0; j < cols; j++)
                    {
                        point p;
                        p.y = start_y + i * step_size;
                        p.x = start_x + j * step_size;
                        path.push_back(p);
                    }
                }
                else
                { // 如果是奇数行，则从右往左走

                    for (int j = cols - 1; j >= 0; j--)
                    {
                        point p;
                        p.y = start_y + i * step_size;
                        p.x = start_x + j * step_size;
                        path.push_back(p);
                    }
                }
            }
        }
        else if (rows > cols)
        { // 如果x小于y
            for (int i = 0; i <= cols; i++)
            {
                if (i % 2 == 0)
                { // 如果是偶数行，则从上往下走

                    for (int j = 0; j < rows; j++)
                    {
                        point p;
                        p.y = start_y + j * step_size;
                        p.x = start_x + i * step_size;
                        path.push_back(p);
                    }
                }
                else
                { // 如果是奇数行，则从下往上走
                    for (int j = rows - 1; j >= 0; j--)
                    {
                        point p;
                        p.y = start_y + j * step_size;
                        p.x = start_x + i * step_size;
                        path.push_back(p);
                    }
                }
            }
        }
    }
    return path;
}

void read()
{
    double start_x = 0.0;
    double start_y = 0.0;
    double end_x = 1000.0;
    double end_y = 1000.0;
    double step_size = 100.0;
    fstream f;
    f.open("parm.txt", ios::in);
    f >> start_x >> start_y >> end_x >> end_y >> step_size;

    vector<point> path = boustrophedon_decomposition(start_x, start_y, end_x, end_y, step_size);

    fstream o;
    o.open("out.txt", ios::out);
    for (int i = 0; i < path.size(); i++)
    {
        o << (path[i].x + step_size / 2) << "," << (path[i].y + step_size / 2) << ",";
        // o  << path[i].x << "," << path[i].y<<endl;
    }
}
string read2()
{
    string x;
    fstream f2;
    f2.open("out.txt", ios::in);
    f2 >> x;
    return x;
}
int main()
{
    read();
    cout << read2();
    return 0;
}