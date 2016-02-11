int missingNumber(int* nums, int numsSize) {
	int i,sum = 0;
	if (!nums || (numsSize ==0))
		return -1;
	for (i = 0; i < numsSize; i++) {
		sum += nums[i];
	}
	return numsSize * (numsSize  + 1) / 2 - sum;
}
