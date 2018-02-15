function fibDigits(num) {
	var phi = 1.618033989;
	var current = 1;
	var sqrtFive = Math.sqrt(5);
	var numDigits = 0;
	var rounded;
	while (numDigits < num) {
		numDigits = ((current*Math.log10(phi)) - Math.log10(sqrtFive));
		rounded = Math.floor(numDigits) + 1;
		if (numDigits > num - 5) {	
			console.log('Current term: ' + current +', numDigits: ' + Math.round(rounded));
		}
		current++;
	}	
}

fibDigits(1001);