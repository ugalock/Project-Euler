var permutator = function(array) {
	var allPerms = [];

	var mutator = function(arr, currentPerm) {
		var currentItem,
			currentPerm = currentPerm || [];
		for (var i = 0; i < arr.length; i++) {
			currentItem = arr.splice(i, 1);
			if (arr.length === 0) {
				allPerms.push(currentPerm.concat(currentItem));
			}
			mutator(arr.slice(), currentPerm.concat(currentItem));
			arr.splice(i, 0, currentItem[0]);
		}
		return allPerms;
	}
	return [...new Set(mutator(array).map(v=>v.join('')))];
}

var answer = permutator(['0','1','2','3','4','5','6','7','8','9']);
console.log(answer[999999])