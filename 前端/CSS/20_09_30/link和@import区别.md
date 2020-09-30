
<!-- vim-markdown-toc GitLab -->

* [连接方式](#连接方式)
* [导入方式](#导入方式)
* [区别](#区别)

<!-- vim-markdown-toc -->

## 连接方式

连接方式是指使用 html 中的 link 元素引入外部 CSS 样式，这种方式将 CSS 代码放在一个单独的 CSS 文件里，便于管理和维护。

## 导入方式

导入方式是指使用 CSS 规则的方式加载外部 CSS 样式，可以用于动态加载 CSS 样式。

## 区别

1. link 在网页加载的同时，加载 CSS；@import 在网页全部加载完毕后，加载 CSS
2. link 除了可以加载 CSS 外，还能加载 RSS 订阅和 rel；@import 只能加载 CSS
3. link 是 XHTML 元素，不存在容性问题；@import 是 CSS2.1 提出的，在低版本浏览器会有兼容性问题
4. link 支持使用 js 去控制 DOM 修改样式；@import 不支持
