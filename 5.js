function isEvenDiv(x, num) {
	if (num % x === 0) return true;
	return false;
}

function firstMultipleOfAllNumsUpTo(num) {
	for (var i = 1;; i++) {
	var x = num;	
		while (isEvenDiv(x, i)) {
			if (x === 1) {
				return console.log(i);
			} else {
				x--;
			}
		}
	}
}
firstMultipleOfAllNumsUpTo(20);

