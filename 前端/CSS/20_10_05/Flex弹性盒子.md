
<!-- vim-markdown-toc GitLab -->

* [Flex 出现的原因](#flex-出现的原因)
* [Flex 基础概念](#flex-基础概念)
* [容器的属性](#容器的属性)
	* [flex-direction](#flex-direction)
	* [flex-wrap](#flex-wrap)
	* [flex-flow](#flex-flow)
	* [justify-content](#justify-content)
	* [align-items](#align-items)
	* [align-content](#align-content)
* [项目属性](#项目属性)
	* [order](#order)
	* [flex-grow](#flex-grow)
	* [flex-shrink](#flex-shrink)
	* [flex-basis](#flex-basis)
	* [flex](#flex)
	* [align-self](#align-self)

<!-- vim-markdown-toc -->

## Flex 出现的原因

在弹性盒子出现之前，通常使用 display + position + float 进行页面布局，但这些方式的布局都存在局限性，非常不灵活，也不好维护，一些特殊的布局就不好实现，例如垂直居中

## Flex 基础概念

1. flex 容器：简称容器，含有 `display: flex ` 属性的元素
2. flex 项目：简称项目，容器下的所有子元素都是项目
3. mian axis：水平主轴，主轴的开始位置为 main start；结束位置为 main end
4. cross axis：垂直交叉轴，交叉轴开始位置为 cross start；结束位置为 cross end
5. main size：项目在 main axis 轴上的大小，可以理解为项目的宽度
6. cross size：项目在 cross axis 轴上的大小，可以理解为项目的高度

![图 1.1 flex 基础概念](http://www.ruanyifeng.com/blogimg/asset/2015/bg2015071004.png) 

## 容器的属性

### flex-direction

容器主轴方向

| 值             | 描述                   |
|----------------|------------------------|
| row            | 默认值，水平，从左至右 |
| row-reverse    | 水平，从右至左         |
| column         | 垂直，至顶向下         |
| column-reverse | 垂直，至底向上         |

![图 1.2](http://www.ruanyifeng.com/blogimg/asset/2015/bg2015071005.png)

### flex-wrap

项目在轴线换行

| 值           | 描述                                           |
|--------------|------------------------------------------------|
| nowrap       | 默认值，不换行                                 |
| wrap         | 换行                                           |
| wrap-reverse | 换行，将原来内容放在下面一行, 换行内容放在上面 |

**nowrap：**   
![nowrap](http://www.ruanyifeng.com/blogimg/asset/2015/bg2015071007.png) 

**wrap：**    
![wrap](http://www.ruanyifeng.com/blogimg/asset/2015/bg2015071008.jpg) 

**wrap-reverse：**   
![wrap-reverse](http://www.ruanyifeng.com/blogimg/asset/2015/bg2015071009.jpg) 

### flex-flow

flex-direction 和 flex-wrap 的简写，默认值为 `row nowrap`

### justify-content

项目在主轴上的排列方式，以下是主轴为 row 的含义

| 值            | 描述                   |
|---------------|------------------------|
| flex-start    | 左对齐                 |
| flex-end      | 右对齐                 |
| center        | 水平居中               |
| space-between | 两端对齐，项目间隔相等 |
| space-around  | 每个项目两侧间隔相等   |

![justify-content](http://www.ruanyifeng.com/blogimg/asset/2015/bg2015071010.png) 

### align-items

项目在交叉轴上的对齐方式，以下是主轴为 row 时，交叉轴的含义

| 值         | 描述               |
|------------|--------------------|
| flex-start | 顶部对齐           |
| flex-end   | 底部对齐           |
| center     | 垂直居中           |
| stretch    | 垂直铺满           |
| baseline   | 第一行文字基线对齐 |

![align-items](http://www.ruanyifeng.com/blogimg/asset/2015/bg2015071011.png) 

### align-content

多行项目在交叉轴上的对齐方式, 只有单行不生效

| 值            | 描述                             |
|---------------|----------------------------------|
| flex-start    | 顶部对齐                         |
| flex-end      | 底部对齐                         |
| center        | 垂直居中                         |
| space-between | 顶部和底部对齐，项目垂直间距相等 |
| space-around  | 项目垂直两侧间距相等             |
| stretch       | 项目垂直方向铺满                 |

![align-content](http://www.ruanyifeng.com/blogimg/asset/2015/bg2015071012.png) 

## 项目属性

### order

项目的排序属性，值越小，权重越高，项目越考前

![order](http://www.ruanyifeng.com/blogimg/asset/2015/bg2015071013.png) 

### flex-grow

项目的放大比例

| 值 | 描述                           |
|----|--------------------------------|
| 0  | 默认值，剩余空间充足，不放大   |
| 1  | 剩余空间充足，一比一放大 |

![flex-grow](http://www.ruanyifeng.com/blogimg/asset/2015/bg2015071014.png) 

### flex-shrink

项目的收缩比例

| 值 | 描述                         |
|----|------------------------------|
| 0  | 默认值，剩余空间不足，不缩放 |
| 1  | 剩余空间不足, 一比一比例缩小 |

![flex-shrink](http://www.ruanyifeng.com/blogimg/asset/2015/bg2015071015.jpg) 

### flex-basis

设置项目的 main size，可以简单理解为设置项目的宽度

| 值          | 描述                         |
|-------------|------------------------------|
| auto        | 自动设置项目大小             |
| number 单位 | 具体数字，表示固定大小       |
| number %    | 设置项目大小为容器的百分之几 |

### flex

flex-grow、flex-shrink、flex-basis 属性的简写，默认值为 0 1 auto

| 值                                      | 描述                                       |
|-----------------------------------------|--------------------------------------------|
| 1                                       | 1 1 0%                                     |
| auto                                    | 1 1 auto                                   |
| none                                    | 0 0 auto                                   |
| 长度或百分比 x                          | 设置 flex-basis 的值，等价于 1 1 x         |
| 一个非负数字 x                          | 设置 flex-grow，等价于 x 1 0%              |
| 两个非负数字 x y                        | 设置 flex-grow、flex-shrink，等价于 x y 0% |
| 设置一个非负数字和一个长度或百分比 x, z | 设置 flex-grow、flex-basis，等价于 x 1 z   |

### align-self

让项目的 align-items 覆盖容器的 align-items 垂直排列方式

| 值         | 描述                                               |
|------------|----------------------------------------------------|
| auto       | 默认值, 继承父容器的 align-items                   |
| stretch    | 项目垂直铺满容器，如果没有父元素，默认值为 stretch |
| flex-start | 项目顶部对齐                                       |
| flex-end   | 项目底部对齐                                       |
| center     | 项目垂直居中                                       |
| baseline   | 项目基于第一行文字的基线对齐                       |

![align-self](http://www.ruanyifeng.com/blogimg/asset/2015/bg2015071016.png) 
