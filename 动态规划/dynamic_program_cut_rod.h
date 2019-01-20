/*
钢条长度和价格分布，求截钢条的最佳方案
	length:[1,2,3,4,5,  6, 7, 8, 9,10]
	price：[1,5,8,9,10,17,17,20,24,30]
*/
int cut_rod(int p[], int n) 
{
	if (n == 0) 
	{
		return 0;
	}

	int maxprice = -1;
	for (int i = 1; i <= n; i++) {
		maxprice = max(maxprice, p[i]+cut_rod(p, n - i));
	}

	return maxprice;
}

int cut_rod_mem(int p[], int n, int mem[])
{
	
	if (mem[n] >= 0) 
	{
		return mem[n];
	}
	if (n == 0)
	{
		return 0;
	}

	int maxprice = -1;
	for (int i = 1; i <= n; i++) 
	{
		maxprice = max(maxprice, p[i] + cut_rod_mem(p, n - i, mem));
	}

	mem[n] = maxprice;
	return maxprice;
}

int bottom_to_up_cut_rod(int p[], const int n) 
{
	vector<int> r;
	r.push_back(0);

	for (int j = 1; j <= n; j++) 
	{
		int q = -1;
		for (int i = 1; i <= j; i++)
		{
			q = max(q, p[i] + r[j - i]);
		}
		r.push_back(q);
	}

	return r[n];
}