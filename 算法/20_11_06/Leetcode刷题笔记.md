## 目录

<!-- vim-markdown-toc GitLab -->

* [简单难度](#简单难度)
	* [242. 有效的字母异位词](#242-有效的字母异位词)
		* [题目描述](#题目描述)
		* [方法一：排序](#方法一排序)
		* [方法二：Hashmap](#方法二hashmap)
		* [方法三：ASCII 和比较](#方法三ascii-和比较)
	* [剑指 Offer 25. 合并两个排序的链表](#剑指-offer-25-合并两个排序的链表)
		* [题目描述](#题目描述-1)
		* [方法：迭代](#方法迭代)
	* [88. 合并两个有序数组](#88-合并两个有序数组)
		* [题目描述](#题目描述-2)
		* [方法：从后往前比较](#方法从后往前比较)
	* [剑指 Offer 09. 用两个栈实现队列](#剑指-offer-09-用两个栈实现队列)
		* [题目描述](#题目描述-3)
		* [方法：双栈模拟队列](#方法双栈模拟队列)
	* [20. 有效的括号](#20-有效的括号)
		* [题目描述](#题目描述-4)
		* [方法：堆栈](#方法堆栈)
	* [剑指 Offer 57. 和为 s 的两个数字](#剑指-offer-57-和为-s-的两个数字)
		* [题目描述](#题目描述-5)
		* [方法一：Hashmap](#方法一hashmap)
		* [方法二：双指针](#方法二双指针)
	* [206. 反转链表](#206-反转链表)
		* [题目描述](#题目描述-6)
		* [方法：迭代](#方法迭代-1)
	* [141. 环形链表](#141-环形链表)
		* [题目描述](#题目描述-7)
		* [方法一：Hashmap](#方法一hashmap-1)
		* [方法二：快慢指针](#方法二快慢指针)
* [中等难度](#中等难度)
	* [18. 四数之和](#18-四数之和)
		* [题目描述](#题目描述-8)
		* [方法：将四数之和转换为三数之和](#方法将四数之和转换为三数之和)
	* [15. 三数之和](#15-三数之和)
		* [题目描述](#题目描述-9)
		* [方法：双指针](#方法双指针)
	* [24. 两两交换链表中的节点](#24-两两交换链表中的节点)
		* [题目描述](#题目描述-10)
	* [剑指 Offer 35. 复杂链表的复制](#剑指-offer-35-复杂链表的复制)
		* [题目描述](#题目描述-11)
		* [方法一：迭代](#方法一迭代)
		* [方法二：递归](#方法二递归)
* [困难难度](#困难难度)
	* [剑指 Offer 59 - I. 滑动窗口的最大值](#剑指-offer-59-i-滑动窗口的最大值)
		* [题目描述](#题目描述-12)
		* [方法：双向队列（队列头永远保存最大元素索引）](#方法双向队列队列头永远保存最大元素索引)

<!-- vim-markdown-toc -->

## 简单难度

### 242. 有效的字母异位词

#### 题目描述

```
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:

输入：s = "anagram", t = "nagaram"
输出：true
示例 2:

输入：s = "rat", t = "car"
输出：false
```

#### 方法一：排序

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  return Array.from(s).sort().join("") === Array.from(t).sort().join("");
};
```

#### 方法二：Hashmap

```javascript
var isAnagram = function (s, t) {
  let map = new Map();

  for (let i = 0, sLen = s.length; i < sLen; i++) {
    if (!map.has(s[i])) map.set(s[i], 0);
    map.set(s[i], map.get(s[i]) + 1);
  }

  for (let j = 0, tLen = t.length; j < tLen; j++) {
    if (!map.has(t[j])) return false;
    map.set(t[j], map.get(t[j]) - 1);
    if (map.get(t[j]) === 0) map.delete(t[j]);
  }

  return !map.size;
};
```

#### 方法三：ASCII 和比较

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  let sum = 0;
  for (let i = 0, sLen = s.length; i < sLen; i++) {
    sum += s[i].codePointAt() ** 0.5;
  }
  for (let j = 0, tLen = t.length; j < tLen; j++) {
    sum -= t[j].codePointAt() ** 0.5;
  }
  // 当两个串的 ASCII 差小于 1e-5 时认为它们相等
  return Math.abs(sum) < 1e-5;
};
```

### 剑指 Offer 25. 合并两个排序的链表

#### 题目描述

```
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例 1：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```

#### 方法：迭代

```javascript
var mergeTwoLists = function (l1, l2) {
  let root = new ListNode(-1);
  let cur = root;
  while (l1 && l2) {
    if (l1.val < l2.val) {
      cur.next = l1;
      l1 = l1.next;
    } else {
      cur.next = l2;
      l2 = l2.next;
    }
    cur = cur.next;
  }
  cur.next = l1 ? l1 : l2;
  return root.next;
};
```

### 88. 合并两个有序数组

#### 题目描述

```
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 
说明：

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 

示例：

输入：
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出：[1,2,2,3,5,6]
```

#### 方法：从后往前比较

```javascript
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function (nums1, m, nums2, n) {
  let p = m-- + n-- - 1;

  while (m >= 0 && n >= 0) {
    nums1[p--] = nums1[m] < nums2[n] ? nums2[n--] : nums1[m--];
  }

  while (n >= 0) {
    nums1[p--] = nums2[m--];
  }
};
```

### 剑指 Offer 09. 用两个栈实现队列

#### 题目描述

```
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。
（若队列中没有元素，deleteHead 操作返回 -1 )

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
```

#### 方法：双栈模拟队列

```javascript
var CQueue = function () {
  this.iptStack = []; // 输入栈
  this.optStack = []; // 输出栈
};

/**
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function (value) {
  this.iptStack.push(value);
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function () {
  let iptStack = this.iptStack;
  let optStack = this.optStack;
  if (!iptStack.length && !optStack.length) {
    return -1;
  }
  if (!optStack.length) {
    while (iptStack.length) {
      optStack.push(iptStack.pop());
    }
  }
  return optStack.pop();
};
```

### 20. 有效的括号

#### 题目描述

```javascript
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入："()"
输出：true
示例 2:

输入："()[]{}"
输出：true
示例 3:

输入："(]"
输出：false
示例 4:

输入："([)]"
输出：false
示例 5:

输入："{[]}"
输出：true
```

#### 方法：堆栈

```javascript
var isValid = function (s) {
  let map = new Map([
    ["}", "{"],
    [")", "("],
    ["]", "["],
  ]);
  let stack = [];
  for (let i = 0, len = s.length; i < len; i++) {
    if (!map.has(s[i])) {
      stack.push(s[i]);
    } else {
      if (stack.pop() !== map.get(s[i])) {
        return false;
      }
    }
  }
  return !stack.length;
};
```

### 剑指 Offer 57. 和为 s 的两个数字

#### 题目描述

```
输入一个递增排序的数组和一个数字 s，在数组中查找两个数，使得它们的和正好是 s。如果有多对数字的和等于 s，则输出任意一对即可。

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]
示例 2：

输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]
```

#### 方法一：Hashmap

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  let set = new Set();
  for (let i = 0, len = nums.length; i < len; i++) {
    let y = target - nums[i];
    if (set.has(y)) {
      return [nums[i], y];
    }
    set.add(nums[i]);
  }
};
```

#### 方法二：双指针

```javascript
var twoSum = function (nums, target) {
  let l = 0;
  let r = nums.length - 1;

  while (l < r) {
    let sum = nums[l] + nums[r];
    if (sum < target) l++;
    else if (sum > target) r--;
    else return [nums[l], nums[r]];
  }
};
```

### 206. 反转链表

#### 题目描述

```
反转一个单链表。

示例：

输入：1->2->3->4->5->NULL
输出：5->4->3->2->1->NULL
```

#### 方法：迭代

```javascript
var reverseList = function (head) {
  let pre = null;
  let cur = head;
  let tmp;
  while (cur) {
    tmp = cur.next;
    cur.next = pre;
    pre = cur;
    cur = tmp;
  }
  return pre;
};
```

### 141. 环形链表

#### 题目描述

```
给定一个链表，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
如果链表中存在环，则返回 true 。 否则，返回 false 。

进阶：
你能用 O(1)（即，常量）内存解决此问题吗？

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
```

#### 方法一：Hashmap

```javascript
var hasCycle = function (head) {
  let set = new Set();
  let p = head;

  while (p) {
    if (set.has(p)) {
      return true;
    }
    set.add(p);
    p = p.next;
  }
  return false;
};
```

#### 方法二：快慢指针

```javascript
var hasCycle = function (head) {
  let slow = head;
  let fast = head;

  while (slow && fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
    if (slow === fast) {
      return true;
    }
  }

  return false;
};
```

## 中等难度

### 18. 四数之和

#### 题目描述

```
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
```

#### 方法：将四数之和转换为三数之和

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function (nums, target) {
  if (nums.length < 4) return [];
  let result = [];
  nums.sort((a, b) => a - b);
  for (let i = 0, len = nums.length; i < len; i++) {
    if (i > 0 && nums[i] === nums[i - 1]) continue;
    let new_target = target - nums[i];
    for (let j = i + 1; j < len; j++) {
      if (j > i + 1 && nums[j] === nums[j - 1]) continue;
      let l = j + 1;
      let r = len - 1;
      while (l < r) {
        let sum = nums[j] + nums[l] + nums[r];
        if (sum < new_target) {
          l += 1;
        } else if (sum > new_target) {
          r -= 1;
        } else {
          result.push([nums[i], nums[j], nums[l], nums[r]]);
          while (nums[l] === nums[l + 1]) l += 1;
          while (nums[r] === nums[r - 1]) r -= 1;
          l += 1;
          r -= 1;
        }
      }
    }
  }
  return result;
};
```

### 15. 三数之和

#### 题目描述

```
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
```

#### 方法：双指针

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  if (nums.length < 3) return [];
  let result = [];
  nums.sort((a, b) => a - b);
  for (let i = 0, len = nums.length; i < len; i++) {
    if (i > 0 && nums[i] === nums[i - 1]) continue;
    let l = i + 1;
    let r = len - 1;
    while (l < r) {
      let sum = nums[i] + nums[l] + nums[r];
      if (sum > 0) r -= 1;
      else if (sum < 0) l += 1;
      else {
        result.push([nums[i], nums[l], nums[r]]);
        while (nums[l] === nums[l + 1]) l += 1;
        while (nums[r] === nums[r - 1]) r -= 1;
        l += 1;
        r -= 1;
      }
    }
  }
  return result;
};
```

### 24. 两两交换链表中的节点

#### 题目描述

```
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1：

输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：

输入：head = []
输出：[]
示例 3：

输入：head = [1]
输出：[1]
```

方法：迭代 + 多指针

```javascript
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function (head) {
  if (head === null) {
    return head;
  }
  let result = head;
  let pre = null;
  let slow = head;
  let fast = head.next;

  while (fast) {
    let tmp = fast.next;
    fast.next = slow;
    slow.next = tmp;
    if (pre === null) {
      pre = slow;
      result = fast;
    } else {
      pre.next = fast;
      pre = slow;
    }
    if (tmp === null) break;
    slow = tmp;
    fast = tmp.next;
  }

  return result;
};
```

### 剑指 Offer 35. 复杂链表的复制

#### 题目描述

```
请实现 copyRandomList 函数，复制一个复杂链表。
在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。

示例 1：

输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

示例 2：

输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]

示例 3：

输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]

示例 4：

输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。
```

#### 方法一：迭代

```javascript
/**
 * // Definition for a Node.
 * function Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {Node} head
 * @return {Node}
 */
var copyRandomList = function (head) {
  if (head === null) {
    return null;
  }
  let root = new Node(-1, null, null);
  let pre = root;
  let map = new WeakMap();
  let cur = head;
  while (cur) {
    let node = new Node(cur.val, null, null);
    pre.next = node;
    map.set(cur, node);
    pre = node;
    cur = cur.next;
  }
  let troot = root.next;
  cur = head;
  while (cur) {
    troot.random = map.has(cur.random) ? map.get(cur.random) : null;
    cur = cur.next;
    troot = troot.next;
  }
  return root.next;
};
```

#### 方法二：递归

```javascript
var copyRandomList = function (head) {
  function helper(root, map = new WeakMap()) {
    if (root === null) return root;
    if (map.has(root)) return map.get(root);
    let node = new Node(root.val);
    map.set(root, node);
    node.next = helper(root.next, map);
    node.random = helper(root.random, map);
    return node;
  }

  return helper(head);
};
```

## 困难难度

### 剑指 Offer 59 - I. 滑动窗口的最大值

#### 题目描述

```
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例：

输入：nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出：[3,3,5,5,6,7]
解释：

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

#### 方法：双向队列（队列头永远保存最大元素索引）

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function (nums, k) {
  let [r, windows] = [[], []];
  if (!nums.length) return r;
  for (let i = 0, len = nums.length; i < len; i++) {
    if (i >= k && windows[0] <= i - k) windows.shift();
    let size = windows.length - 1;
    while (windows.length && nums[windows[size--]] < nums[i]) windows.pop();
    windows.push(i);
    if (i >= k - 1) r.push(nums[windows[0]]);
  }
  return r;
};
```
