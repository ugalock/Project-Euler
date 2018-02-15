function findTriplesThatSumToN(n) {	
	for (var i = 0; i < n; i++) {
		for (var j = 0; j < i; j++) {
			for (var k = 0; k < j; k++) {
				if ((Math.pow(k, 2) + Math.pow(j, 2) === Math.pow(i, 2)) && i + j + k === n) {
					console.log(i, j, k);
					//console.log(i * j * k);
				}
			}
		}
	}
}

findTriplesThatSumToN(1000);