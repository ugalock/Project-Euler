// function getPrimes(max) {
//     var sieve = [], i, j, primes = [];
//     for (i = 2; i <= max; ++i) {
//         if (!sieve[i]) {
//             // i has not been marked -- it is prime
//             primes.push(i);
//             for (j = i << 1; j <= max; j += i) {
//                 sieve[j] = true;
//             }
//         }
//     }
//     return primes;
// }


// function getAllFactorsFor(remainder) {
//     var factors = [], i;

//     for (i = 2; i <= remainder; i++) {
//         while ((remainder % i) === 0) {
//             factors.push(i);
//             remainder /= i;
//         }
//     }

//     return factors;
// }



function triangle(x) {
	var triangle = x * (x + 1) / 2;
	return triangle;
}


function findDiv(num) {
	var div = 1;
	for (var i = 0; i <= Math.floor(Math.sqrt(num)); i++) {
		if (num % i === 0) {
			div++;
		}
	}
	return (div * 2);
}


var solution = function() {
	for (var x = 1, y = triangle(x);; ++x, y = triangle(x)) {
	    result = findDiv(y);
	    if (result > 500) {
	      
	      console.log(x);
	      return y;
	    }
	}
}  
console.log(solution());



