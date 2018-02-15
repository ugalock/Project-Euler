function decimalPeriods(max) {
  var longest = 0;
  var index = 0;
  for (var i = 1; i <= max; i++) {
    var count = 0;
    var value = 10 % i;
    var z = max;
    while (value !== 1 && z > 0) {
      value *= 10;
      value = value % i;
      count++;
      z--;
    }
    if (count > longest && z > 1) {
      longest = count;
      index = i;
    }
  }
  return longest, index;
}

var ans = decimalPeriods(10000);
console.log(ans);
