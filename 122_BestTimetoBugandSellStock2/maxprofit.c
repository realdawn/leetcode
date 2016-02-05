int maxProfit(int* prices, int pricesSize) {
	int i;
	int profit = 0;
	bool obtain = false;
	for (i = 0; i < pricesSize - 1; i++) {
		if (prices[i] < prices[i+1]) {
			if (!obtain) {
				obtain = true;
				profit -= prices[i];	
			}
		} else {
			if (obtain) {
				profit += prices[i];
				obtain = false;
			}
		}		
	}
	if (obtain) {
		profit += prices[i];
		obtain = false;
	}
	return profit;
}
