int maxProduct(char** words, int wordsSize) {
	int *mask;
	int *wordlengths;
        int i,j,k;
        int len1,len2;
        int maxproduct = 0;
	mask = (int *)malloc(wordsSize * sizeof(int));
	wordlengths = (int *)malloc(wordsSize * sizeof(int));
	for (i = 0; i < wordsSize; i++) {
		mask[i] = 0;
                for (k = 0; words[i][k] != '\0'; k++)
                       mask[i] |= 1 << words[i][k];  
		wordlengths[i] = k;
	}
        for (i = 0; i < wordsSize; i++) {
                for (j = i + 1; j < wordsSize; j++) {
			if (!(mask[i] & mask[j]))
				 if (maxproduct < wordlengths[i] * wordlengths[j])
                               		 maxproduct = wordlengths[i] * wordlengths[j];
                }
        }
        return maxproduct;
}

