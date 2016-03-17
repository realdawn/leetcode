int majorityElement(int* nums, int numsSize) {
	int left,right;
	int i;
	int count = 0;
	if (numsSize == 1)
		return nums[0];
	left = majorityElement(nums, numsSize / 2);
	right = majorityElement(nums + numsSize/2, numsSize - numsSize / 2);
	/* Compare left and right which is majority.*/
	for (i = 0; i < numsSize; i++) {
		if (left == nums[i])	
			count++;
	}
	if (count > numsSize / 2)
		return left;
	else
		return right;
}
