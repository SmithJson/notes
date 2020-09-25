
<!-- vim-markdown-toc GitLab -->

* [元数据](#元数据)
* [meta 元素](#meta-元素)
	* [键/值对设置元数据](#键值对设置元数据)
	* [charset 声明字符串编码](#charset-声明字符串编码)
	* [http-equiv 模拟 http 标头字段](#http-equiv-模拟-http-标头字段)

<!-- vim-markdown-toc -->

## 元数据

用于构建 THML 文档的基础结构，以及就如何处理文档向浏览器提供信息和指示，它们本身不是文档内容，但提供了关于后面文档内容的信息。

## meta 元素

html 中的元数据元素，提供关于网站的各种信息，利于搜索引擎理解。html 文档可以包含多个 meta 元素，每个 meta 只包含一种用途，如果想定义多个文档信息，则需要在 head 标签中添加多个 meta 元素

meta 元素包含 charset、name、content、http-equiv 四个属性

1. charset：声明了页面的字符编码。如 utf-8 unicode 字符编码
2. name：设置网页的元数据，不能与 charset、http-equiv 共存。通常是 content 配合使用
3. content：配合 name 或 htte-equiv 使用，能够给两个属性设置一个值
4. http-equiv：可以用做 http 头部的某些作用，通过定义该属性可以改变服务器和用户代理的行为

### 键/值对设置元数据

```html
<meta name="参数" content="具体描述信息">

<head>
	<title>示例</title>
	<meta name="keywords" content="网页关键字">

	<meta name="description" content="网页描述">

	<meta name="author" content="作者">

	让多内核浏览器，使用 webkit 内核，如(360 浏览器)
	<meta name="renderer" content="webkit">

	<meta name="copyright" content="版权">

	<meta name="viewport" content="initial-scale=1,maximum-scale=3,minimum-scale=1,user-scalable=no">
</head>
```
### charset 声明字符串编码

```html
设置网页字符编码
<meta charset="utf-8">
```
### http-equiv 模拟 http 标头字段

```html
设置字符编码
<meta http-equiv="content-type" content="text/html; charset=utf-8">

IE 和 Chrome 使用最新版本渲染页面
<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">

2 秒后在从当前网页跳转到百度页面
<meta http-equiv="refresh" content="2:URL=http://www.baidu.com">

设置浏览器的缓存机制
<meta http-equiv="cache-control" content="no-cache">
```
