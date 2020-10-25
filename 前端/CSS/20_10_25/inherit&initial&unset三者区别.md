
<!-- vim-markdown-toc GitLab -->

* [initial](#initial)
* [inherit](#inherit)
	* [默认可以继承的属性](#默认可以继承的属性)
		* [所有元素](#所有元素)
		* [内联元素](#内联元素)
		* [块状元素](#块状元素)
		* [列表元素](#列表元素)
		* [表格元素](#表格元素)
* [unset](#unset)

<!-- vim-markdown-toc -->

## initial

initial 关键字用于设置一个属性的默认值【IE 不支持】，将属性值初始化为浏览器默认样式。

## inherit

强制继承父元素的某个属性值。

### 默认可以继承的属性

**内联元素**

#### 所有元素

1. visibility
2. cursor

#### 内联元素

1. font
2. font-family
3. font-size
4. font-weight
5. font-variant
6. line-height
7. letter-spacing
8. word-spacing
9. white-space
10. color
11. text-decoration
12. text-transform
13. direction

#### 块状元素

1. text-indent
2. text-align

#### 列表元素

1. list-style
2. list-style-type
3. list-style-position
4. list-style-image

#### 表格元素

1. border-collapse

## unset

不进行设置，相当于 initial 和 inherit 的结合，当属性为继承属性时，使用 inherit；如果不是使用则使用 initial。
