/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
	int *returnArray;
	int i,step,doublestep;
	returnArray = (int *)malloc((num + 1) * sizeof(int));
	*returnSize = num + 1;
	returnArray[0] = 0;
	for (i = 1, doublestep =1, step = 1; i <= num; i++) {
		if (i == doublestep) {
			returnArray[i] = 1;	
			step = i;
			doublestep = step * 2;
		} else {
			returnArray[i] = returnArray[i - step] + 1;
		}
	}
	return returnArray;
} 
