function sumtorial(num) {
	var sum = (num * (num + 1) / 2);
	return sum;
}
function sumMultiples(d1, d2, countTo) {
	var divOne = Math.floor(countTo / d1);
	var divTwo = Math.floor(countTo / d2);
	var divOneAndTwo = Math.floor(countTo / (d1 * d2));
	var result = ((d1 * sumtorial(divOne)) + (d2 * sumtorial(divTwo)) - (d1 * d2 * sumtorial(divOneAndTwo)));
	return result;
}
console.log(sumMultiples(3, 5, 99999999999999999999999999999999999999999999999999999999999999999999999));