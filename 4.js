function isPal(num) {
	var string = num.toString();
	if (string.length < 2) {
		return true;
	} else if (string[0].toUpperCase() === string[string.length - 1].toUpperCase()) {
		return isPal(string.slice(1, string.length - 1));
	} else {
		return false;
	}
};
var product = 0;
var highest = 0;
for (var x = 999; x > 99; x--){
	for(var y = 999; y > 99; y--) {
		product = x * y;
		if (isPal(product) && product > highest) {
			highest = product;
		} 

	}
}
console.log(highest);