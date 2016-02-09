/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
	int i,j;
	int leftProductResult=1, rightProductResult=1;	    
	int *returnArray;
	returnArray = (int *)malloc(numsSize * sizeof(int));
	*returnSize = numsSize;
	for (i = 0, j = numsSize-1; i < numsSize >> 1; i++, j--) {
		returnArray[i] = leftProductResult * nums[i];
		leftProductResult = returnArray[i];
		returnArray[j] = rightProductResult * nums[j];
		rightProductResult = returnArray[j];
	}
	if ((numsSize & 0x1) == 0 && numsSize > 2)
		rightProductResult = returnArray[j + 2];
	for (i = numsSize >> 1, j = 0; i - j -1 >= 0 && i + j + 1 < numsSize; j++) {
		returnArray[i + j] = leftProductResult * returnArray[i + j + 1];	
		returnArray[i - j] = rightProductResult * returnArray[i - j - 1];
		leftProductResult = leftProductResult * nums[i + j];
		rightProductResult = rightProductResult * nums[i -j];
	}
	if (i - j - 1 >= 0 && numsSize > 2) {
		returnArray[i - j] = rightProductResult * returnArray[i - j - 1];
		rightProductResult = rightProductResult * nums[i -j];
	}
	returnArray[0] = rightProductResult;	
	returnArray[numsSize - 1] = leftProductResult;
	return returnArray;
}
