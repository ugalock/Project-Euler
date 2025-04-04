function uniq(a) {
    var seen = {};
    return a.filter(function(item) {
        return seen.hasOwnProperty(item) ? false : (seen[item] = true);
    });
}

var sumDiv = function(n) {
	var sum = 0;
	for (var i = 1; i < n; i++) {
		if (n % i === 0) {
			sum += i;
		}
	}
	return sum;
};

var isAmicable = function(n) {
	if (sumDiv(sumDiv(n)) === n && sumDiv(n) !== n) {
		return true;
	} else {
		return false;
	}
};

var findAmicables = function(n) {
	var arr = [];
	for (var i = 0; i < n; i++) {
		if (isAmicable(i) && sumDiv(i) < n) {
			arr.push(i, sumDiv(i));
		}
	}
	return arr;
}
var arraySum = function(arr) {
	var sum = 0;
	for (var i = 0; i < arr.length; i++) {
		if (typeof arr[i] === 'number') {
			sum += arr[i];
		} else if (arr[i] instanceof Array) {
			sum += arraySum(arr[i]);
		}
	}
	return sum;
};


var amicables = (uniq(findAmicables(10000)));
console.log(arraySum(amicables));
