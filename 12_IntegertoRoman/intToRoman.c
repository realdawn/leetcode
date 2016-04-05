char* intToRoman(int num) {
	char *result = (char *)malloc(30 * sizeof(char));
	char full[4] = {'M', 'C', 'X', 'I'};
	char half[3] = {'D', 'L', 'V'};
	int bit[4] = {0};
	int i,j,unit,len;
	for (i = 0, unit = 1000; i < 4; i++, unit = unit / 10) {
		bit[i] = num / unit;
		num = num % unit;	
	}
	for (i = 0, len = 0; i < 4; i++) {
		if (bit[i] == 9) {
			result[len++] = full[i];
			result[len++] = full[i - 1];
		} else if (bit[i] == 4) {
			result[len++] = full[i];
			result[len++] = half[i - 1];
		} else if(bit[i] < 4) {
			for (j = 0; j < bit[i]; j++) {
				result[len++] = full[i];
			}	
		} else if(bit[i] > 4) {
			result[len++] = half[i - 1];
			for (j = 0; j < bit[i] - 5; j++) {
				result[len++] = full[i];
			}	
		}	
	}
	result[len] = '\0'; 
	return result;
}
