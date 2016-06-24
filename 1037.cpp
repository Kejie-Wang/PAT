#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int integer1, int integer2)
{
	return integer1 > integer2;
}

int main()
{
	int NC, NP;
	vector<int> positiveCoupons, negativeCoupons,  positiveProduct, negativeProduct;
	cin >> NC;
	for (int i = 0; i < NC; i++)
	{
		int coupon;
		scanf("%d", &coupon);
		if (coupon > 0)
			positiveCoupons.push_back(coupon);
		else if (coupon < 0)
			negativeCoupons.push_back(coupon);

	}
	sort(positiveCoupons.begin(), positiveCoupons.end(), cmp);
	sort(negativeCoupons.begin(), negativeCoupons.end());
	cin >> NP;
	for (int i = 0; i < NP; i++)
	{
		int product;
		scanf("%d", &product);
		if (product > 0)
			positiveProduct.push_back(product);
		else if (product < 0)
			negativeProduct.push_back(product);

	}
	sort(positiveProduct.begin(), positiveProduct.end(), cmp);
	sort(negativeProduct.begin(), negativeProduct.end());

	int MaxMonmey = 0;
	for (int i = 0; i < positiveCoupons.size() && i < positiveProduct.size(); i++)
		MaxMonmey += positiveCoupons[i] * positiveProduct[i];
	for (int i = 0; i < negativeCoupons.size() && negativeProduct.size(); i++)
		MaxMonmey += negativeCoupons[i] * negativeProduct[i];

	cout << MaxMonmey;
}