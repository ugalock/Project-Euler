// var newarray = [];

// for (i=0; i< Math.pow(2, array.length); i++) {

//     var s = i.toString(2)
//     var t = 0;
//     for (c in s) t += s[c] * array[c];

//     newarray.push(t);
// }

// var findAbundantsUpTo = function(n) {
// 	if (n === 2) {
// 		return [];
// 	} else {w
// 		if(isAbundant(n)) {
// 			return findAbundantsUpTo(n - 1).concat(n);
// 		} else {
// 			return findAbundantsUpTo(n - 1);
// 		}
// 	}
// }

// function uniq(a) {
//     var seen = {};
//     return a.filter(function(item) {
//         return seen.hasOwnProperty(item) ? false : (seen[item] = true);
//     });
// }

// var possibleSums = function(array) {
// 	var sumArray = [];
// 	for (var i = 0; i < array.length; i++) {
// 		var sum = array[0] + array[i];
// 		sumArray.push(sum);
// 	}
// 	return sumArray;
// }

// var getAllPossibleSums = function(array) {
// 	if (array.length === 0) {
// 		return [];
// 	} else {
// 		return [...new Set(possibleSums(array).concat(getAllPossibleSums(array.slice(1))))];
// 	}
// }

var isAbundant = function(n) {
	var sum = 1;
	var limit = n / 2;
	for (var i = 2; i <= limit; i++) {
		if (n % i === 0) {
			sum += i;
			if (sum > n) {
				return true;
			}
		}
	}
	return false;
};

var abundants = [],
	k = 0;
for (var i = 0; i < 20161; i++) {
	if (isAbundant(i)) {
		abundants[k] = i;
		k++;
	}
}

var sumOfAbundantsIndex = [];

for (var i = 0; i <= abundants.length; i++) {
	for (var j = i; j <= abundants.length; j++) {
		if ((abundants[i] + abundants[j]) <= 20161) {
			sumOfAbundantsIndex[abundants[i] + abundants[j]] = true;
		} else {
			break;
		}
	}
}

for (var i = 0; i <= 20161; i++) {
	if (sumOfAbundantsIndex[i] == true) {
		continue;
	} else {
		sumOfAbundantsIndex[i] = false;
	}
}

var sum = 0;
for (var i = 0; i <= 20161; i++) {
	if (!sumOfAbundantsIndex[i]) {
		sum += i;
	}
}

console.log(sum);