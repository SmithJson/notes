<!-- vim-markdown-toc GitLab -->

* [Css 盒子模型](#css-盒子模型)
* [盒子模型类型](#盒子模型类型)
	* [标准盒子模型](#标准盒子模型)
	* [IE 盒子模型](#ie-盒子模型)
	* [盒子类型转换](#盒子类型转换)
* [基于盒模型的定位](#基于盒模型的定位)
* [BFC](#bfc)
	* [触发条件](#触发条件)
	* [应用场景](#应用场景)

<!-- vim-markdown-toc -->

## Css 盒子模型

页面上的每个元素都可以看成是一个盒子，盒子模型由 `content`、`padding`、`boreder`、`margin` 四个部分构成。

![盒子模型](https://www.runoob.com/images/box-model.gif) 

## 盒子模型类型

盒子模型分为 `标准盒子模型` 和 `IE 盒子模型`，它们之间的唯一区别在于计算方式不同。

### 标准盒子模型

宽度计算：   

width 只包含 content ，盒模型的空间大小 = content（width） + padding + border + margin

![标准盒子模型](http://img.smyhvae.com/2015-10-03-css-27.jpg) 

### IE 盒子模型

宽度计算：   

width 包含 content、padding、border 三部分。盒模型的空间大小 = width + margin   
content 的大小 = width - padding - boreder

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

| 值       | 描述                                                                                                                                                        |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| static   | 静态定位，默认值                                                                                                                                            |
| absolute | 绝对定位，以距离它最近的的含有定位的父元素为参考点【如果没有这样的父元素，以 body 元素为参考点】，设置 left、right、top、bottom                             |
| relative | 相对定位，以自身为参考点，进行 left、right、top、bottom 的值设置                                                                                            |
| fixed    | 与 absolute 类似，使用窗口作为参考点                                                                                                                        |
| sticky   | CSS3 新出的粘性属性，类似于 relative 和 fixed 的结合，在可视区域内，与 relative 类似，元素随页面滚动而移动；超出可视区域后与 fixed 相似，元素不随滚动条移动 |

## BFC

BFC 全名叫做 Block Formatting context（块状格式化上下文），可以理解为一个独立的容器。容器中的元素不会影响外部元素，同时容器中的与元素也不受外部元素影响。

### 触发条件

1. float 除 none 之外的值
2. position 的值为 absolute、fixed
3. overflow 不为 visible
4. display 为 inline-block、flex、table-cell、table-caption

### 应用场景

1. 清除浮动
2. 解决 margin 重叠问题
3. 阻止元素被浮动元素覆盖
4. 自适应两栏布局
