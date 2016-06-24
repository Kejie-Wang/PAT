#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int m, n, l;
int point[1286][128][60];

struct pixel
{
	int x;
	int y;
	int z;
	pixel(int xx, int yy, int zz){ x = xx; y = yy; z = zz; }
};

int DFS(int x, int y, int z)
{
	int volume = 0;
	queue<pixel> que;
	pixel p(x, y, z);
	point[x][y][z] = 0;
	que.push(p);
	while (!que.empty())
	{
		pixel p = que.front();
		volume++;
		que.pop();
		if (p.x - 1 >= 0 && point[p.x - 1][p.y][p.z])
		{
			que.push(pixel(p.x - 1, p.y, p.z));
			point[p.x - 1][p.y][p.z] = 0;
		}
		if (p.x + 1 < m && point[p.x + 1][p.y][p.z])
		{
			que.push(pixel(p.x + 1, p.y, p.z));
			point[p.x + 1][p.y][p.z] = 0;
		}
		if (p.y - 1 >= 0 && point[p.x][p.y - 1][p.z])
		{
			que.push(pixel(p.x, p.y - 1, p.z));
			point[p.x][p.y - 1][p.z] = 0;
		}
		if (p.y + 1 < n && point[p.x][p.y + 1][p.z])
		{
			que.push(pixel(p.x, p.y + 1, p.z));
			point[p.x][p.y + 1][p.z] = 0;
		}
		if (p.z - 1 >= 0 && point[p.x][p.y][p.z - 1])
		{
			que.push(pixel(p.x, p.y, p.z - 1));
			point[p.x][p.y][p.z - 1] = 0;
		}
		if (p.z + 1 < l && point[p.x][p.y][p.z + 1])
		{
			que.push(pixel(p.x, p.y, p.z + 1));
			point[p.x][p.y][p.z + 1] = 0;
		}
	}
	return volume;
}

int main()
{
	int threshold;
	scanf("%d%d%d%d", &m, &n, &l, &threshold);
	for (int k = 0; k < l; k++)
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)		
				scanf("%d", &point[i][j][k]);
	int volume = 0;
	for (int k = 0; k < l; k++)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (point[i][j][k])
				{
					int vol = DFS(i, j, k);
					if (vol >= threshold)
						volume += vol;
				}
			}
		}
	}
	printf("%d", volume);					
}
}