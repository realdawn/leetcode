#include<stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char*** solveNQueens(int n, int* returnSize) {
	int i,j,p,q;
	int **flag;
	int *oneSolution;
	int solutionCount = 0;    
	char ***allSolution;
	allSolution = (char ***)malloc (1000 * sizeof(char**));
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
			char **solution;
			solution = (char **)malloc(n * sizeof(char *));
			for (p = 0; p < n; p++)	{
				solution[p] = (char *)malloc(n * sizeof(char));
			}
			for (p = 0; p < n; p++)	{
				for (q = 0; q < n; q++) {
					solution[p][q] = '.';
				}
			} 
			for (p = 0; p < n; p++)	{
				solution[p][oneSolution[p]] = 'Q';
			}
			allSolution[solutionCount] = solution;
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
	*returnSize = solutionCount;
	return allSolution;
}
int main()
{
	int *returnSize = (int *)malloc(sizeof(int));	
	char ***allSolution;
	allSolution = solveNQueens(5,returnSize);
}
