
<!-- vim-markdown-toc GitLab -->

* [防抖（debounce）](#防抖debounce)
	* [使用场景](#使用场景)
* [节流（throttle）](#节流throttle)
	* [使用场景](#使用场景-1)
* [call&apply&bind](#callapplybind)
	* [使用场景](#使用场景-2)
	* [call](#call)
	* [apply](#apply)
	* [bind](#bind)
* [curry](#curry)
	* [使用场景](#使用场景-3)
* [发布订阅模式](#发布订阅模式)
* [instanceof](#instanceof)
* [new](#new)
* [深克隆](#深克隆)
* [Promise](#promise)

<!-- vim-markdown-toc -->

## 防抖（debounce）

触发事件后，n 秒内只执行一次该事件的回调函数。

### 使用场景

1. 输入框的输入
2. 浏览器窗口缩放
3. 手机号、邮箱验证

```javascript
let ipt = document.querySelector("#ipt");

function debounce(callback, delay = 300) {
	let tid = null;
	return function (...args) {
		clearTimeout(tid);
		tid = setTimeout(() => {
			callback.apply(this, args);
		}, delay);
	}
}

ipt.oninput = debounce(function (e) {
	console.log(e.target.value, this);
}, 500);
```

## 节流（throttle）

在指定时间内只执行一次回调函数。

### 使用场景

1. 按钮点击事件
2. 拖拽事件
3. onScroll

```javascript
let ipt = document.querySelector("#ipt");

function throttle(callback, wait = 300) {
	let isReady = true;
	return function (...args) {
		if (isReady) {
			isReady = false;
			setTimeout(() => {
				callback.apply(this, args);
				isReady = true;
			}, wait);
		}
	};
}


ipt.oninput = throttle(function (e) {
	console.log(e.target.value);
});
```

## call&apply&bind

修改上下文里的 this 指向

### 使用场景

1. 借用别人的 api
2. 实现对象的私有属性继承

### call

```javascript
Function.prototype.myCall = function (ctx, ...args) {
	ctx = ctx || window;
	ctx.fn = this;
	let result  = ctx.fn(...args);
	delete ctx.fn;
	return result;
}

window.color = "red";
let o = {color: "blue"};
function sayColor(){
	console.log(this.color);
}
sayColor.myCall(this);//red
sayColor.myCall(window);//red
sayColor.myCall();
sayColor.myCall(null);
sayColor.myCall(undefined);
sayColor.myCall(o);//blue
```

### apply

```javascript
Function.prototype.myApply = function (ctx, args = []) {
	ctx = ctx || window;
	ctx.fn = this;
	let result = ctx.fn(...args);
	delete ctx.fn;
	return result;
}

let foo = {
    count: 1
};
function bar(name, age) {
    console.log(this.count, name, age);
}
bar.myApply(foo, ["Stone", 18]); // 1
```

### bind

```javascript
Function.prototype.myBind = function (ctx, ...args) {
	ctx = ctx || window;
	let _self = this;
	return function F (...params) {
		let _arg = [...args, ...params];
		return  this instanceof F ? new _self(..._arg) : _self.apply(ctx, _arg);
	}
}


function Person(age, gender) {
	console.log(this.name);
	console.log(age);
	console.log(gender);
}

Person.prototype.extend = "继承";

var egg = {
	name: "Stone"
};


var newP = Person.myBind(egg, 18);
var p = newP("male");
console.dir(newP);

var p1 = new newP("female");
console.log(p1);
```

## curry

函数柯里化

### 使用场景

1. 参数复用
2. 参树缓存

```javascript
function fixCurry(fn, ...args) {
	return function (...params) {
		return fn.apply(this, [...args, ...params]);
	}
}

function curry(fn, length) {
	let len = length || fn.length;
	return function (...args) {
		if (args.length < len) {
			let combine = [fn, ...args];
			return curry(fixCurry.apply(this, combine), len - args.length);
		}
		return fn.apply(this, args);
	}
}

function add(a, b, c, d) {
	return a + b + c + d;
}

var newAdd = curry(add);
var a = newAdd(1);
console.log(a(2, 3, 4, 5));
console.log(a(2)(3, 4));
console.log(a(2, 3)(4));
```

## 发布订阅模式

```javascript
class PubSub {
	constructor() {
		this.events = {};
	}

	subscribe(type, callback) {
		this.events[type] = this.events[type] || [];
		this.events[type].push(callback);
	}

	publish(type) {
		if (!this.events[type]) {
			return;
		}
		this.events[type].forEach(event => typeof event === "function" && event());
	}

	cancel(type) {
		return delete this.events[type];
	}

	once(type, callback) {
		this.subscribe(type, () => {
			callback();
			this.cancel(type);
		});
	}
}

let pubsub = new PubSub();

// publish
pubsub.subscribe("sub", () => {
	console.log("sub1");
});

pubsub.subscribe("sub", () => {
	console.log("sub2");
});

pubsub.subscribe("sub", () => {
	console.log("sub3");
});

// pubsub.publish("sub");

// once
pubsub.once("once-1", () => {
	console.log("once-1");
});

// pubsub.once("once-1", () => {
// 	console.log("once-2");
// });
//
// pubsub.once("once-1", () => {
// 	console.log("once-3");
// });

pubsub.publish("once-1");
```

## instanceof

```javascript
function myInstanceof(obj, target) {
	if (obj == null) {
		return false
	}
	let left = obj.__proto__;
	let right = target.prototype;

	if (left === right) {
		return true;
	}

	return myInstanceof(left, target);
}

function Foo() {

}

console.log(myInstanceof(Object, Object));
console.log(myInstanceof(Function, Function));
console.log(myInstanceof(Function, Object));
console.log(myInstanceof(Foo, Foo));
console.log(myInstanceof(Foo, Object));
console.log(myInstanceof(Foo, Function));
console.log("===============");
console.log(Object instanceof Object);
console.log(Function instanceof Function);
console.log(Function instanceof Object);
console.log(Foo instanceof Foo);
console.log(Foo instanceof Object);
console.log(Foo instanceof Function);
```

## new

```javascript
function create(...args) {
	let [constructor, ...params] = args;
	let obj = Object.create(constructor.prototype);
	let result = constructor.apply(obj, params);
	return result instanceof constructor ? obj : result;
}

function Person(name, age) {
	this.name = name;
	this.age = age;
	return {
		name: 1343,
		age: 20,
	};
}

let p = create(Person, "Stone", 18);

console.log(p)
```

## 深克隆

```javascript
deepClone.isComplexDataType = data => (typeof data === "function" || typeof data === "object") && data !== null;
deepClone.dataType = [
	Array,
	Math,
	RegExp,
	Date,
	Map,
	Set,
	WeakMap,
	WeakSet,
];

function deepClone(obj, hash = new WeakMap()) {
	if (hash.has(obj)) {
		return hash.get(obj);
	}
	let type = deepClone.dataType;
	let isComplexDataType = deepClone.isComplexDataType;
	if (type.includes(obj.constructor)) {
		return new obj.constructor(obj);
	}
	let desc = Object.getOwnPropertyDescriptors(obj);
	let cloneObj = Object.create(Object.getPrototypeOf(obj), desc);
	hash.set(obj, cloneObj);
	for (let key of Reflect.ownKeys(obj)) {
		let val = obj[key];
		if (isComplexDataType(val) && typeof val !== "function") {
			cloneObj[key] = deepClone(val, hash);
		}
	}
	return cloneObj;
}


let obj = {
    bigInt: BigInt(12312),
    set: new Set([2]),
    map: new Map([['a', 22], ['b', 33]]),
    num: 0,
    str: '',
    boolean: true,
    unf: undefined,
    nul: null,
    obj: {
        name: '我是一个对象',
        id: 1,
    },
    arr: [0, 1, 2],
    fn() {
        return '我是一函数'
    },
    date: new Date(0),
    reg: new RegExp('/我是一个正则/ig'),
    [Symbol('1')]: 1,
};

Object.defineProperty(obj, 'innumerable', {
    enumerable: false,
    value: '不可枚举属性',
    writable: false,
});
obj = Object.create(obj, Object.getOwnPropertyDescriptors(obj));
obj.loop = obj;

const obj1 = deepClone(obj);
console.log(obj1);

obj.map.delete('a');
console.log(obj);
console.log(obj1);

obj.obj.name = "new name";
console.log(obj);
console.log(obj1);
```

## Promise

```javascript
function MyPromise(executor) {
	let _self = this;
	_self.status = "pending";
	_self.data;
	_self.callbacks = [];

	function resolve(value) {
		if (_self.status !== "pending") {
			return;
		}
		_self.status = "resolved";
		_self.data = value;
		_self.callbacks.forEach(cbObj => {
			cbObj.onResolved();
		});
	}

	function reject(error) {
		if (_self.status !== "pending") {
			return;
		}
		_self.status = "rejected";
		_self.data = error;
		_self.callbacks.forEach(cbObj => {
			cbObj.onRejected();
		});
	}

	try {
		executor(resolve, reject);
	} catch (e) {
		reject(e);
	}
}


MyPromise.prototype.then = function (onResolved, onRejected) {
	let _self = this;
	// 解决值穿透问题
	onResolved = typeof onResolved === "function" ? onResolved : value => value;
	onRejected = typeof onRejected === "function" ? onRejected : reason => {
		throw reason;
	};

	return new MyPromise((resolve, reject) => {

		function handle(callback) {
			try {
				let result = callback(_self.data);
				if (result instanceof MyPromise) {
					result.then(
						value => {
							resolve(value);
						},
						reason => {
							reject(reason);
						}
					);
				} else {
					resolve(result);
				}
			} catch (e) {
				reject(e);
			}
		}

		if (_self.status === "pending") {
			_self.callbacks.push({
				onResolved() {
					handle(onResolved);
				},
				onRejected() {
					handle(onRejected);
				}
			});
		} else if (_self.status === "resolved") {
			setTimeout(function () {
				handle(onResolved);
			}, 0);
		} else {
			setTimeout(function () {
				handle(onRejected);
			}, 0);
		}
	});
};

MyPromise.prototype.catch = function (onRejected) {
	return this.then(null, onRejected);
};

MyPromise.resolve = function (value) {
	return new MyPromise((resolve, reject) => {
		if (value instanceof MyPromise) {
			value.then(
				val => {
					resolve(val);
				},
				reason => {
					reject(reason);
				}
			);
		} else {
			resolve(value);
		}
	});
};

MyPromise.reject = function (value) {
	return new MyPromise((resolve, reject) => {
		reject(value);
	});
}

MyPromise.all = function (promises) {
	let values = new Array(promises.length);
	let resolvedCount = 0;
	return new MyPromise((resolve, reject) => {
		promises.forEach((p, index) => {
			MyPromise.resolve(p).then(
				value => {
					values[index] = value;
					resolvedCount++;
					if (resolvedCount === promises.length) {
						resolve(values);
					}
				},
				reason => {
					reject(reason);
				}
			);
		});
	});
};

MyPromise.race = function (promises) {
	return new MyPromise((resolve, reject) => {
		promises.forEach((p, index) => {
			MyPromise.resolve(p).then(
				value => {
					resolve(value)
				},
				reason => {
					reject(reason);
				}
			)
		});
	});
};

let p = new MyPromise((resolve, reject) => {
	setTimeout(() => {
		reject({
			name: "Stone",
		})
	}, 1000);
});

p.catch(reason => {
	console.log(reason);
});

// all 校验
// let p2 = new MyPromise((resolve, reject) => {
// 	setTimeout(() => {
// 		resolve({
// 			name: "Stone"
// 		})
// 	}, 1000);
// });
//
// let p3 = new MyPromise((resolve, reject) => {
// 	setTimeout(() => {
// 		resolve({
// 			name: "Stone"
// 		})
// 	}, 1000);
// });
//
// MyPromise.race([p, p2, p3, 5, "Stone"])
// 	.then(data => {
// 		console.log("1-resolve", data);
// 		return "smithjson";
// 	}, reason => {
// 		console.log("1-reject", reason);
// 		throw new Error();
// 	})
// 	.then(data => {
// 		console.log("2-resolve", data);
// 	}, reason => {
// 		console.log("2-reject", reason);
// 	})

// 空置校验
// p.then().then((data) => {
// 	console.log("2-resolve", data);
// }, (reason) => {
// 	console.log("2-reject", reason);
// });
```
