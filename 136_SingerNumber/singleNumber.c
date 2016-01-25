int singleNumber(int* nums, int numsSize) {
	/* a XOR b xor a = b
 	 * a XOR b = (a&~b)|(~a&b)
	 * ~b = -(b+1)	
	 */
	while (numsSize > 1)
	{
		*(nums + 1) = (*nums & -(*(nums + 1) + 1))
			      | (-(*nums + 1) & *(nums + 1));
		nums++;
		numsSize--;
	}
	return *nums;
}
