function factorial(n) {
	if (n === 0) {
		return 1
	} else {
		return n * factorial(n - 1)
	}
}

function findNumRoutes(sizeGrid) {
	return factorial(sizeGrid*2) / (factorial(sizeGrid) * factorial(sizeGrid))
}

console.log(findNumRoutes(20))


