bool isAnagram(char* s, char* t) {
	int alphabet[256] = {0};
	int i=0;
	int len = 0;
	for (i = 0; s[i] != '\0'; i++) {
		alphabet[s[i]]++;
	}
	len = i;
	for (i = 0; t[i] != '\0'; i++) {
		alphabet[t[i]]--;
		if (alphabet[t[i]] < 0)
			return false;
	}
	if (len == i)
		return true;
	else
		return false;
}
