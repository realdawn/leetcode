int romanToInt(char* s) {
	int i, count = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == 'I') {
			count += 1;
		} else if (s[i] == 'V') {
			if(i > 0 && s[i - 1] == 'I')
				count += 3;
			else
				count += 5;
		} else if (s[i] == 'X') {
			if(i > 0 && s[i - 1] == 'I')
				count += 8;
			else
				count += 10;
		} else if (s[i] == 'L') {
			if(i > 0 && s[i - 1] == 'X')
				count += 30;
			else
				count += 50;
		} else if (s[i] == 'C') {
			if(i > 0 && s[i - 1] == 'X')
				count += 80;
			else
				count += 100;
		} else if (s[i] == 'D') {
			if(i > 0 && s[i - 1] == 'C')
				count += 300;
			else
				count += 500;
		} else if (s[i] == 'M') {
			if(i > 0 && s[i - 1] == 'C')
				count += 800;
			else
				count += 1000;
		}	
	}
	return count;
}
