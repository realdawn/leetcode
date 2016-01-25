int singleNumber(int* nums, int numsSize) {
	while (numsSize > 1)
	{
		*(nums + 1) ^= *nums;
		nums++;
		numsSize--;
	}
	return *nums;
}
