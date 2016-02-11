int maxProduct(char** words, int wordsSize) {
	bool letter[26],flag=false;
	int i,j,k;
	int len1,len2;
	int maxproduct = 0;
	for (i = 0; i < wordsSize; i++) {
		for (k = 0; k < 26; k++) 
			letter[k] = false;
		for (k = 0; words[i][k] != '\0'; k++) 
			letter[words[i][k] - 'a'] = true;
		len1 = k;
		for (j = i + 1; j < wordsSize; j++) {
			for (k = 0; words[j][k] != '\0'; k++) {
				if (letter[words[j][k] - 'a']) {
					flag = true;
					break;
				}
			}		
			if (flag) {
				flag = false;
				continue;
			}
			len2 = k;
			if (maxproduct < len1 * len2)
				maxproduct = len1 * len2;
		}
	}
	return maxproduct;
}
