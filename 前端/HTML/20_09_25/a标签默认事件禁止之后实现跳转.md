
<!-- vim-markdown-toc GitLab -->

* [默认事件禁止之后实现跳转方式](#默认事件禁止之后实现跳转方式)

<!-- vim-markdown-toc -->

## 默认事件禁止之后实现跳转方式

```javascript
let domArr = document.getElementsByTagName("a");

domArr.forEach(function (e) {
	e.preventDefault();
	location.href = this.href;
});
```
