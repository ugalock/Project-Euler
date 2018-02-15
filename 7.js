function isPrime(num) {
  for(var i = 2; i <= Math.sqrt(num); i++)
    if(num % i === 0) return false;
  return num !== 1;
}

function findNthPrime(n) {
  var count = 0;
  for (var i = 2;; i++) {
    if (isPrime(i)) {
      //console.log(i);
      count++;
      if (count === n) {
        return console.log(i);
      }
    }
  }
}
findNthPrime(10000);