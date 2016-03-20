int totalNQueens(int n) {
	int i,j,p,q;
	int **flag;
	int *oneSolution;
	int solutionCount = 0;    
	oneSolution = (int *)malloc(n * sizeof(int));
	flag = (int **) malloc(n * sizeof(int *));
	for (i = 0; i < n; i++) {
		flag[i] =(int *)malloc(n * sizeof(int));
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			flag[i][j] = 0;		
		}
	}
	i = 0; j = 0;
	while (i >= 0) {
		while (j >= 0) {
			if (j == n) {
				/* Execute into a dead corner, so backtrace and clean the flag */
				i--;
				if (i < 0)
					break;
				j = oneSolution[i] + 1;
				for (p = i; p < n; p++) {
					flag[p][j - 1]--;
				}	
				for (p = 1; ((i + p) < n) && ((j - 1 + p) < n); p++) {
					flag[i + p][j - 1 + p]--;	
				}
				for (p = 1; ((i + p) < n) && ((j -1 - p) >= 0); p++) {
					flag[i + p][j - 1 - p]--;	
				}
				break;
			}
			if (flag[i][j] == 0) {
				oneSolution[i] = j;
				for (p = i; p < n; p++) {
					flag[p][j]++;
				}	
				for (p = 1; ((i + p) < n) && ((j + p) < n); p++) {
					flag[i + p][j + p]++;	
				}
				for (p = 1; ((i + p) < n) && ((j - p) >= 0); p++) {
					flag[i + p][j - p]++;	
				}
				i++;
				j = 0;
				break;
			}			
			j++;
		}
		if (i == n) {
			/* Find a solution, so backtrace to find the next solution. */
			solutionCount++;
			i--;
			j = oneSolution[i] + 1;
			for (p = i; p < n; p++) {
				flag[p][j - 1]--;
			}	
			for (p = 1; ((i + p) < n) && ((j - 1 + p) < n); p++) {
				flag[i + p][j - 1 + p]--;	
			}
			for (p = 1; ((i + p) < n) && ((j -1 - p) >= 0); p++) {
				flag[i + p][j - 1 - p]--;	
			}
				
		}
	}
	free(oneSolution);
	for (i = 0; i < n; i++)	{
		free(flag[i]);
	}
        free(flag);
	return solutionCount;
}
