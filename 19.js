var daysInMonths = {
	0:0,
	1:31,
	2:28,
	3:31,
	4:30,
	5:31,
	6:30,
	7:31,
	8:31,
	9:30,
	10:31,
	11:30,
	12:31
};
var daysInMonthsLeap = {
	0:0,
	1:31,
	2:29,
	3:31,
	4:30,
	5:31,
	6:30,
	7:31,
	8:31,
	9:30,
	10:31,
	11:30,
	12:31
};
var numSundays = 0;
var numDaysTotal = 0;
for (var year = 1901; year < 2001; year++) {	
	for (var month = 1; month < 13; month++) {
		if (year % 4 !== 0) {
			for (var days = 1; days <= daysInMonths[month]; days++){
				if (days === 1 && numDaysTotal % 7 === 5) {
					numSundays += 1;
				}
			}
			numDaysTotal += daysInMonths[month];
		} else {
			for (var days = 1; days <= daysInMonthsLeap[month]; days++) {
				if (days === 1 && numDaysTotal % 7 === 5) {
					numSundays += 1;
				}
			}
			numDaysTotal += daysInMonthsLeap[month];
		}
	}
}	
console.log(numSundays)