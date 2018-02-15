var fs = require("fs");

var text = fs.readFileSync("./names.txt").toString('utf-8');
var array = text.split('"');

function uniq(a) {
    var seen = {};
    return a.filter(function(item) {
        return seen.hasOwnProperty(item) ? false : (seen[item] = true);
    });
}
var arr = uniq(array);
arr.shift();
arr.shift();
arr.shift();
arr.unshift('MARY');

var sortedNames = arr.sort();
//console.log(sortedNames);

var letters = {
    'A':1,
    'B':2,
    'C':3,
    'D':4,
    'E':5,
    'F':6,
    'G':7,
    'H':8,
    'I':9,
    'J':10,
    'K':11,
    'L':12,
    'M':13,
    'N':14,
    'O':15,
    'P':16,
    'Q':17,
    'R':18,
    'S':19,
    'T':20,
    'U':21,
    'V':22,
    'W':23,
    'X':24,
    'Y':25,
    'Z':26
};

var totalScore = 0;
for (var i = 0; i < sortedNames.length; i++) {
	var nameScore = 0;
	for (var j = 0; j < sortedNames[i].length; j++) {
		nameScore += letters[sortedNames[i][j]];
	}
	totalScore += nameScore * (i+1);
}
console.log(totalScore);