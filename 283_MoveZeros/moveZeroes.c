void moveZeroes(int* nums, int numsSize) {
	int i = 0, j = 0;
	for(; i < numsSize; i++) {
		if (nums[i] != 0) {
			nums[j] = nums[i];
			j++;
		}
	}
	for(; j < numsSize; j++) {
		nums[j] = 0;
	}
}
