function selectSort(arr) {
  if (!arr.length) return arr;
  let minIndex;
  for (let i = 0; i < arr.length - 1; i++) {
    minIndex = i;
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[minIndex] > arr[j]) minIndex = j;
    }
    swap(arr, minIndex, i);
  }
}

function swap(arr, i, j) {
  let tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

let arr = [44, 4, 34, -30, 16, 45, 31, 35, -5, -69, 15, 9, -10];
selectSort(arr);
console.log(arr);
