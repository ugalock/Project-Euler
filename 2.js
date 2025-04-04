function evenFib(sumUntil) {
	var first = 0;
	var second = 1;
	var next = 0; 
	var result = 0;
	while (first + second < sumUntil) {
		next = first + second;
		first = second;
		second = next;
		if (next % 2 === 0) {
			result += next;
		}
	}	
	console.log(result);	
}
evenFib(4000000);