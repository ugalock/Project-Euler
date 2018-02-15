
function Collatz(num, count) {
	if (num === 1) {
		return count + 1;
	} 
	else if (num % 2 === 0) {
		return Collatz((num / 2), count + 1);
	} else {
		return Collatz((3 * num + 1), count + 1);
	}

}
//console.log(Collatz(8, 0));
highest = 0;
for (var i = 500001; i <= 1000000; i++) {
	if ((i - 1) % 3 === 0 && i % 2 !== 0) {
		var num = Collatz(i, 0);
		if (num > highest) {
			highest = num;
			var highestNum = i;
		}
	}
}
console.log(highestNum);
