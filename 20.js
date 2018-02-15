var factorial = function(n) {
	if (n === 0) {
		return 1;
	} else {
		return n * factorial(n - 1);
	}

};

var string = '93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000';
var sum = 0;
for (var i = 0; i < string.length; i++) {
	sum += parseInt(string[i]);
}
console.log(sum);