function fibDigits(num) {
	var phi = 1.618033989;
	var current = 1;
	var sqrtFive = Math.sqrt(5);
	var numDigits = 1;
	var rounded;
	while (Math.ceil(numDigits) < num) {
		numDigits = ((current*Math.log10(phi)) - Math.log10(sqrtFive));
		current++;
	}
	current--;
	console.log("Result: " + current);	
}

fibDigits(1000);