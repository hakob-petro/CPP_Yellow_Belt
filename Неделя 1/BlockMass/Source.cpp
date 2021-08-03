#include <iostream>
#include <vector>
using namespace std;

int main()
{
	uint64_t R, i=0;
	uint64_t N, W, H, D;
	uint64_t mass = 0;
	cin >> N >> R;
	while (i < N)
	{
		cin >> W >> H >> D;
		mass += R * W * H * D;
		i++;
	}
	cout << mass;
	return 0;
}