
<!-- vim-markdown-toc GitLab -->

* [单行省略](#单行省略)
* [多行省略](#多行省略)

<!-- vim-markdown-toc -->

## 单行省略

```html
<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Document</title>
</head>
<style type="text/css">
	.wrap {
		width: 500px;
		overflow: hidden;
		text-overflow: ellipsis;
		white-space: nowrap;
	}
</style>

<body>
	<div class="wrap">
		Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore
		magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd
		gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.
		Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore
		magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd
		gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.
		Lorem ipsum dolor sit amet consectetur adipisicing elit. Aliquid quasi aut corrupti. Incidunt, eligendi! Quam,
		assumenda architecto natus sunt illo rem accusantium mollitia laudantium, nostrum odio autem blanditiis alias
		itaque!
	</div>
</body>

</html>
```

## 多行省略

```html
<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Document</title>
</head>
<style type="text/css">
	.wrap {
		display: -webkit-box;
		-webkit-box-orient: vertical;
		-webkit-line-clamp: 3;
		overflow: hidden;
		word-break: break-all;
		text-overflow: ellipsis;
	}
</style>

<body>
	<div class="wrap">
		Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore
		magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd
		gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.
		Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore
		magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd
		gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.
		Lorem ipsum dolor sit amet consectetur adipisicing elit. Aliquid quasi aut corrupti. Incidunt, eligendi! Quam,
		assumenda architecto natus sunt illo rem accusantium mollitia laudantium, nostrum odio autem blanditiis alias
		itaque!
	</div>
</body>

</html>
```
