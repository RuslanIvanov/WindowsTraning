#define stop  __asm nop
void main()
{
	size_t n = 4, m = 5;
	int** p = new int* [n];
	for (size_t i = 0; i < n; i++)
	{
		p[i] = new int[m];
	}
	stop
		for (size_t i = 0; i < n; i++)
		{
			delete[] p[i];
		}
		delete[]p;
stop
}