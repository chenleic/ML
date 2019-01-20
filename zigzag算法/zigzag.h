typedef unsigned char byte;
int int_to_zigzag(int n) {
	return (n << 1) ^ (n >> 31);
}

int zigzag_to_int(int n) {
	return (((unsigned int)n) >> 1) ^ -(n & 1);
}

int write_to_buffer(int z, byte* buf, int size) 
{
	int ret = 0;

	for (int i = 0; i < size; i++) 
	{
		if ((z & (~0x7f)) == 0) {
			buf[i] = (byte)z;
			ret = i + 1;
			break;
		}
		else
		{
			buf[i] = (byte)((z & 0x7f) | 0x80);
			z = ((unsigned int)z) >> 7;
		}
	}

	return ret;
}

int read_from_buffer(byte* buf, int max_size)
{
	int ret = 0;

	int offset = 0;

	for (int i = 0; i < max_size; i++, offset += 7)
	{
		byte n = buf[i];

		if ((n & 0x80) != 0x80)
		{
			ret |= (n << offset);
			break;
		}
		else
		{
			ret |= ((n & 0x7f) << offset);
		}
	}

	return ret;
}