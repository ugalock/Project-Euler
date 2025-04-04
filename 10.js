function isPrime(num) {
  for(var i = 2; i <= Math.sqrt(num); i++)
    if(num % i === 0) return false;
  return num !== 1;
}

function sumPrimesToN(n) {
	var sum = 0;
	for (var i = 0; i < n; i++) {
		if (isPrime(i)) {
			sum += i;
		}
	}
	console.log(sum);
}

sumPrimesToN(2000000);