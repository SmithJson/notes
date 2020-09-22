/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
	this.capacity = capacity;
	this.map = new Map();
	this.stack = [];
};

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
	let map = this.map;
	let stack = this.stack;
	if (map.has(key)) {
		let i;
		let searchItem = stack.find((item, index) => {
			if (item.key === key) {
				i = index;
			}
			return item.key == key;
		});
		stack.splice(i, 1);
		stack.unshift(searchItem);
		return map.get(key);
	}
	return -1;
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
	let map = this.map;
	let stack = this.stack;
	if (map.has(key)) {
		let index;
		for (let i = 0, len = stack.length; i < len; i++) {
			if (stack[i].key === key) {
				index = i;
				break;
			}
		}
		stack.splice(index, 1);
	} else {
		if (map.size === this.capacity) {
			let item = stack.pop();
			map.delete(item.key);
		}
	}
	stack.unshift({key, value});
	map.set(key, value);
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */

var cache = new LRUCache( 2 /* 缓存容量 */ );

console.log("=========================== 1 =====================");

cache.put(1, 1);
cache.put(2, 2);
console.log(cache.get(1));       // 返回  1
cache.put(3, 3);								 // 该操作会使得密钥 2 作废
console.log(cache.get(2));       // 返回 -1 (未找到)
cache.put(4, 4);								 // 该操作会使得密钥 1 作废
console.log(cache.get(1));       // 返回 -1 (未找到)
console.log(cache.get(3));       // 返回  3
console.log(cache.get(4));       // 返回  4

console.log("=========================== 2 =====================");

var cache = new LRUCache( 1 /* 缓存容量 */ );
cache.put(2, 1);
console.log(cache.get(2)); // 1
cache.put(3, 2);
console.log(cache.get(2)); // -1
console.log(cache.get(3)); // 2

console.log("=========================== 3 =====================");

var cache = new LRUCache( 2 /* 缓存容量 */ );
cache.put(2, 1);
cache.put(2, 2);
console.log(cache.get(2)); // 2
cache.put(1, 1);
cache.put(4, 1);
console.log(cache.get(2)); // -1

console.log("=========================== 4 =====================");

var cache = new LRUCache( 2 /* 缓存容量 */ );
cache.put(2, 1);
cache.put(1, 1);
console.log(cache.get(2)); // 1
cache.put(4, 1);
console.log(cache.get(1)); // -1
console.log(cache.get(2)); // 1
