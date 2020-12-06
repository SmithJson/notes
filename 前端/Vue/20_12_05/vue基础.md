
<!-- vim-markdown-toc GFM -->

* [创建一个 Vue 应用](#创建一个-vue-应用)

<!-- vim-markdown-toc -->

### 创建一个 Vue 应用

```javascript
<div id="app">
  {{message}}
</div>

<script>
	let vm = new Vue({
			el: "#app",
			data: {
					message: "Hello world"
			}
	});
</script>
```
