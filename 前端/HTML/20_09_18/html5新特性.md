# HTML5 新特性、如何处理兼容性、如何区分 HTML5 和 HTML

<!-- vim-markdown-toc GitLab -->

* [h5新性](#h5新性)
	* [拖拽释放](#拖拽释放)
	* [语义化标签](#语义化标签)
	* [画布（Canvas）API](#画布canvasapi)
	* [音频和视频 API](#音频和视频-api)
	* [地理（geolocation）API](#地理geolocationapi)
	* [本地存储](#本地存储)
	* [webworker](#webworker)

<!-- vim-markdown-toc -->

## h5新性

1. 拖拽释放 API
2. 语义化标签
3. 画布（Canvas）API
4. 音频和视频（audio and video) API
5. 地理（geolocation) API
6. 本地存储（localStorage and sessionStorage)
7. 表单控件、type属性新类型
8. 新技术（webworker、websocket and geolocation)

### 拖拽释放

通过在元素上添加 `dragged="true"` 将元素变为拖拽元素。拖拽事件分为拖拽元素事件和目标区域事件两部分。

- 拖拽元素
	+ ondragstart：开始拖拽元素
	+ ondrag：元素拖拽中
	+ ondragend：拖拽结束（松开鼠标按键或按 ESC 键
- 目标区域：当拖拽元素进入一个特定的区域才会触发下列事件
	+ ondragenter：拖拽元素进入目标区域
	+ ondragover：拖拽元素在目标区域（每 100ms 触发一次)
	+ ondragleave：拖拽元素离开目标区域
	+ ondrop：在目标区域释放拖拽元素
- 注意点：由于浏览器不支持在 ondragenter 和 ondragover 中接收拖拽元素【只能拖拽进入目标区域，但在 drop 的时候不会放在目标区域里】，所以得通过`e.stopPropagation()` 来阻止默认事件

### 语义化标签

h4 通过 id、class 取特定含义的值，来实现语义化；   
h5 则专门推出来语义化标签（如：header、footer、aside、arcticle、section、nav等）   

作用：   
	1. 模块化，有利于团队开发和维护；   
	2. 有利于搜索引擎解析网页，提高 SEO；   
	3. 增强可读性

### 画布（Canvas）API

通过 JavaScript 和 HTML 的 canvas 元素来绘制图形的方式。

- API：
	+ .getContext("2d")：获取 canvas 上下文对象【可以理解为画笔】
	+ .rect(x, y, width, height)：绘制矩形
	+ .arc(x, y, radius, startAngle, endAngle, anticlockwise)：绘制圆形, anticlockwise 为 true 逆时针，false 为顺时针

> 	4. 音频和视频（audio and video)
> 5. 地理（geolocation) API
> 6. 本地存储（localStorage and sessionStorage)
> 7. 表单控件、type属性新类型
> 8. 新技术（webworker、websocket and geolocation)

### 音频和视频 API

- API
	+ currentTime：当前时间
	+ durationTime：总时长
	+ paused：是否暂停
	+ .pause()：暂停视频/音频
	+ .play()：播放视频/音频

### 地理（geolocation）API

通过 window.navigator.geolocation 对象使用API。

- API：
	+ .getCurrentPosition(successCallback, errorCallback, options)：获取当前地址位置
	+ successCallback(pos)：成功的回调函数里传入 postition 对象
	+ pos.coords：坐标对象, 里面包含来纬度(latitude)、经度(longitude)、精度(accuracy)等关于坐标详细信息

### 本地存储

h5 之前通过 cookie 实现本地存储，但 cookie 的容量并不大只有 4KB 左右，存储的信息有限，而且 cookie 能与服务器交互，存在安全性问题。
h5 通过 localStorage 和 sessionStorage 对象实现本地缓存，localStorage 和 sessionStorage 的 api 是一样，这里就写一个。

- localStorage API
	+ setItem(key,value)：设置键值
	+ getItem(key)：获取值
	+ removeItem(key)：删除指定键名的值
	+ clear()：删除所有键值对

### webworker

在主线程创建一个 worker 线程去执行一些事情，实现 js 的并发操作。

```javascript
// main.js
var a = 1000;
var worker = new Worker('./worker.js');

worker.postMessage({
    num: a,
});

worker.onmessage = function (e) {
    console.log(e.data);
};

// worker.terminate(); // 手动停止worker

// worker.js
// worker 中的全局上对象就是 worker 自己，并不是 windows
this.onmessage = function (e) {
    var result = 1;

    for (var i = 0; i < e.data.num; i++) {
        result += i;
    }
    this.postMessage(result);
    // this.close(); // worker自动停止工作
};
```
