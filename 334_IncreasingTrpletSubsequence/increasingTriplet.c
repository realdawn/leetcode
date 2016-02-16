bool increasingTriplet(int* nums, int numsSize) {
	int trinum[3];
	int current = -1;
	int substitute;
	bool subflag = false;
	int i;
	if (numsSize < 3)
		return false;
	trinum[0] = nums[0];
	current = 0;
	for (i = 1; i < numsSize; i++) {
		if (nums[i] > trinum[current]) {
			current++;
			trinum[current] = nums[i];
			if (current == 2)
				return true;
		} else if (nums[i] < trinum[current]) {
			if (current == 0) {
				trinum[current] = nums[i];
			} else {
				if (subflag && (nums[i] > substitute)) {
					trinum[0] = substitute;
					trinum[1] = nums[i];
					subflag = false;
					continue;
				}
				if (nums[i] < trinum[0]) {
					substitute = nums[i];
					subflag = true;	
				} else if (nums[i] > trinum[0]) {
					trinum[1] = nums[i];
				}
			}
		}	
	}    
	return false;
}
