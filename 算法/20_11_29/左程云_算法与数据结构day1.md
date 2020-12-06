<!-- vim-markdown-toc GFM -->

- [p1、认识复杂度、对数器、二分法与异或运算](#p1 认识复杂度对数器二分法与异或运算)
  - [算法优劣核心指标](#算法优劣核心指标)
  - [常见的常数时间操作](#常见的常数时间操作)
  - [计算 BigO 时间复杂度（最坏情况）](#计算 -bigo- 时间复杂度最坏情况)
  - [常见的时间复杂度](#常见的时间复杂度)

### p1、认识复杂度、对数器、二分法与异或运算

#### 算法优劣核心指标

- 时间复杂度
- 额外空间复杂度
- 常数项时间

#### 常见的常数时间操作

- 算数运算（`+ - * / %`）
- 位运算（`>> >>> << | & ^`）
- 赋值、比较、自增、自减
- 数组寻址操作

#### 计算 BigO 时间复杂度（最坏情况）

1. 计算常数次数 O(aN^2 + bN + c)
2. 删除常数项 O(aN^2 + bN)
3. 取最高项 O(aN^2)
4. 忽略最高项系数 O(N^2)

- 等差数列可以简单看作 aN^2 + bN + c

#### 常见的时间复杂度

- O(1)
- O(logN)
- O(N)
- O(NlogN)
- O(N^2) O(N^3)...O(N^k)
- O(2^N) O(3^N)...O(K^N)
- O(N!)

#### O(N^2) 的排序算法

- 选择排序

```javascript
// 最小位索引与当前数索引进行交换
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
```

- 冒泡排序

```javascript
// 两相邻的数进行交换
function bubbleSort(arr) {
  if (!arr.length) return arr;
  for (let i = arr.length - 1; i > 0; i--) {
    for (let j = 0; j < arr.length; j++) {
      if (arr[j] > arr[j + 1]) swap(arr, j, j + 1);
    }
  }
}

function swap(arr, i, j) {
  let tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}
```

- 插入排序

```javascript
function insertSort(arr) {
  if (arr === null || arr.length < 2) return;
  for (let i = 1; i < arr.length; i++) {
    // 0 ~ i 有序
    for (let j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) swap(arr, j, j + 1);
  }
}

function swap(arr, i, j) {
  let tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}
```

#### 对数器

> 用于提供大量的随记测试数据

- [0, 1) Math.random()
- [0, N) Math.random() \* N
- [0, N - 1] (int)(Math.random() \* N)
- [0, N] (int)(Math.random() + 1) \* N

#### 二分 O(logN)

- 在一个有序数组中，找某个数是否存在

```javascript
function BSExist(arr, target) {
  if (arr === null || !arr.length) return false;
  let l = 0;
  let r = arr.length - 1;
  let m;

  while (l <= r) {
    m = l + ((r - l) >> 1);
    if (arr[m] === target) return true;
    else if (arr[m] > target) r = m - 1;
    else l = m + 1;
  }
  return false;
}
```

- 在一个有序数组中，找 >= 某个数最左侧的位置

```javascript
function BSExistLeft(arr, target) {
  if (arr === null || !arr.length) return false;
  let l = 0;
  let r = arr.length - 1;
  let m;
  let index = -1;

  while (l <= r) {
    m = l + ((r - l) >> 1);
    if (arr[m] >= target) {
      index = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return index;
}
```

- 在一个有序数组中，找 <= 某个数最右侧的位置

```javascript
function BSExist(arr, target) {
  if (arr === null || !arr.length) return false;
  let l = 0;
  let r = arr.length - 1;
  let m;
  let index = -1;

  while (l <= r) {
    m = l + ((r - l) >> 1);
    if (arr[m] >= target) {
      r = m - 1;
    } else {
      index = m;
      l = m + 1;
    }
  }
  return index;
}
```

- 局部最小值

```javascript
function getLessIndex(arr) {
  if (arr === null || !arr.length) return -1;
  if (arr.length === 1 || arr[0] < arr[1]) return 0;
  if (arr[arr.length - 1] < arr[arr.length - 2]) return arr.length - 1;
  let l = 1;
  let r = arr.length - 2;
  let m;
  while (l <= r) {
    m = l + ((r - l) >> 1);
    if (arr[m] > arr[m - 1]) r = m - 1;
    else if (arr[m] > arr[m + 1]) l = m + 1;
    else return m;
  }
  return l;
}
```

#### 常见位运算

| 位运算                       | 表达式         |
| ---------------------------- | -------------- |
| (n << 1) \| 1                | 2 \* n + 1     |
| l + ((r - l) >> 1)           | (l + r) / 2    |
| (-n & n) or (n & ((~n) + 1)) | 提取最低位的 1 |
| n & (n - 1)                  | 删除最低位的 1 |

##### 异或运算

异或运算是无进位的相加

- 异或运算性质
  1.  0 ^ N = N；N ^ N = 0
  2.  异或运算满足交换律和结合率

##### 题目一

不使用额外变量交换 a、b 的值

```javascript
let a = 100,
  b = 200;

// 方法一
[b, a] = [a, b];

// 方法二
// 不要对同一个空间使用异或运算，否则会变为 0
a = a ^ b; // a = 甲 ^ 已
b = a ^ b; // b = 甲 ^ 已 ^ 已
a = a ^ b; // a = 甲 ^ 已 ^ 甲
```

##### 题目二

一个数组中有一种数出现了奇数次，其他数都出现了偶数次，怎么找到并打印这个数

```javascript
function printOddTimesNum1(arr) {
  let eor = 0;
  for (let i = arr.length - 1; i >= 0; i--) eor ^= arr[i];
  return eor;
}
```

##### 题目三

输入一个数字【二进制】获取最右侧的 1

```javascript
// 110001000 input
// 000001000 output
function bit1(n) {
  return n & (~n + 1);
}
```

##### 题目四

一个数组中有两种数出现了奇数次，其他数都出现了偶数次，怎么找到并打印这个两个数

```javascript
function printOddTimesNum2(arr) {
  let eor = 0;
  for (let i = arr.length - 1; i >= 0; i--) eor ^= arr[i];

  /**
   * eor = a ^ b
   * 因为 a !== b，所以 eor 的某 x 位一定为 1，
   * 而且 a 的 x 位一定为 1 or 0；b 的 x 位 一定为 0 or 1
   */

  let a = 0;
  let one = -eor & eor; // 获取 x 位的 1
  for (let i = arr.length - 1; i >= 0; i--) {
    if ((one & arr[i]) !== 0) a ^= arr[i];
  }

  return [a, eor ^ a];
}
```

let a = 0;
let one = -eor & eor; // 获取 x 位的 1
for (let i = arr.length - 1; i >= 0; i--) {
if ((one & arr[i]) !== 0) a ^= arr[i];
}

return [a, eor ^ a];
}

```

```
