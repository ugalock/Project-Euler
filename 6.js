function diffBetweenSumAndAllSquared(num) {
	var result = 0;
	for(var i = 0; i <= num; i++) {
		result += (Math.pow(i, 3) - Math.pow(i, 2));
	}
	console.log(result);
}
diffBetweenSumAndAllSquared(100);