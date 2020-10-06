
<!-- vim-markdown-toc GitLab -->

* [Css 盒子模型](#css-盒子模型)
* [盒子模型类型](#盒子模型类型)
	* [标准盒子模型](#标准盒子模型)
	* [IE 盒子模型](#ie-盒子模型)
	* [盒子类型转换](#盒子类型转换)
* [基于盒模型的定位](#基于盒模型的定位)

<!-- vim-markdown-toc -->

## Css 盒子模型

页面上的元素都可以看成是一个盒子，盒子模型由 `content`、`padding`、`boreder`、`margin` 四个部分构成。

![盒子模型](https://www.runoob.com/images/box-model.gif) 

## 盒子模型类型

盒子模型分为 `标准盒子模型` 和 `IE 盒子模型`，它们之间的唯一区别在于计算方式不同。

### 标准盒子模型

盒子模型宽度为 content 的大小， width = content

![标准盒子模型](http://img.smyhvae.com/2015-10-03-css-27.jpg) 

### IE 盒子模型

盒子模型宽度为 content、padding、border 三部分的和，width = content + padding + border

![IE 盒子模型](http://img.smyhvae.com/2015-10-03-css-30.jpg) 

### 盒子类型转换

通过 box-sizing 属性进行盒子转换

| 值          | 描述                 |
|-------------|----------------------|
| content-box | 元素使用标准盒子模型 |
| border-box  | 元素使用 IE 盒子模   |

## 基于盒模型的定位

CSS 中使用 position 和 float 进行元素定位

**position**   

| 值       | 描述                                                                                                                            |
|----------|---------------------------------------------------------------------------------------------------------------------------------|
| static   | 静态定位，默认值                                                                                                                |
| absolute | 绝对定位，以距离它最近的的含有定位的父元素为参考点【如果没有这样的父元素，以 body 元素为参考点】，设置 left、right、top、bottom |
| relative | 相对定位，以自身为参考点，进行 left、right、top、bottom 的值设置                                                                |
| fixed    | 与 absolute 类似，但以可视窗口作为参考点                                                                                        |
