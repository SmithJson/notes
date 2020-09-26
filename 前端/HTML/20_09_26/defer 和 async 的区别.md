
<!-- vim-markdown-toc GitLab -->

* [出现的原因](#出现的原因)
* [defer 和 async 的区别](#defer-和-async-的区别)
	* [defer](#defer)
	* [async](#async)

<!-- vim-markdown-toc -->

## 出现的原因

html 解析过程中，如果遇到 `<script>`  标签，那么会暂停解析开始加载 js 文件，当加载完毕后，开始执行加载的 js 内容，当执行到 `</script>` 结束标签时，才继续开始解析 html，在执行 js 的这段期间，页面
是处于空白的，用户体验很差，所以使用 defer、async 将这一过程变成异步的，推迟 js 的执行时机。

## defer 和 async 的区别

### defer

当 `<script>` 添加了 defer 后，在加载过程中，不会阻碍 html 解析，加载完毕后不会立即执行，当 html 解析完毕后，在 DOMContentLoaded 事件触发前，执行加载的 js 文件，使用
defer 能保证 js 文件的执行顺序。

### async

当 `<script>` 添加了 async 后，加载过程与 defer 是一样的，不会阻碍 html 解析，但与 defer 的区别在与执行时机，一旦加载完成，变会打断 html 解析，执行 js 文件，当执行完毕后，
才继续解析 html，并且使用 async 加载的 js 无法保证它们的执行顺序，随意一般用于加载互不依赖的脚本文件。
