/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
	int i;
	int mask = 1;
	int xorresult = 0;
	int *single;  
	*returnSize = 2;
	single = (int *)malloc(*returnSize * sizeof(int));
	single[0] = 0;
	single[1] = 0;
	for (i = 0; i < numsSize; i++) {
		xorresult ^= *(nums+i);
	}
	while (xorresult % 2 == 0) {
		xorresult >>=1;
		mask <<= 1;
	}
	for (i = 0; i <numsSize; i++) {
		if ( (*(nums+i) & mask) == 0) {
			single[0] ^= *(nums+i);
		} else {
			single[1] ^= *(nums+i);
		}
	}
	return single;
}
