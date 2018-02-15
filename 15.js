function pascal(numRows) {

  var triangle = [[1]], row;

  for (var i = 0; i < numRows-1; i++) {
    row = [1];
    for (var j = 1; j < triangle[i].length; j++) {
      row[j] = triangle[i][j] + triangle[i][j-1];
    }
    row.push(1);
    triangle.push(row);
  }

  return row, triangle;
}
console.log(pascal(4));