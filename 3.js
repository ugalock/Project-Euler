function isPrime(num) {
  if (num % 2 === 0) return false;
  if (num % 3 === 0) return false;
  var i = 5;
  var w = 2;
  	while (i < Math.sqrt(num)) {
  		if (num % i === 0) {	  		
  			return false;
	  	} else {
	  		i = i + w;
	  		w = 6 - w;
	  	}
  	}
  return true;
}

function primeFactorsGreaterThanThree(num) {
	for (var i = 0; i <= (num / 2); i++) {
		if (num % i === 0 && isPrime(i)) {
			console.log(i);
		}
	}
}

//primeFactorsGreaterThanThree(5764);

const getPrimes = (bound) => {
	let i = 0,
			res = [];
	while (i < bound) {
		if (isPrime(i)) {
			res.push(i);
		}
		i++;
	}
	return res;
}
console.log(getPrimes(100))


