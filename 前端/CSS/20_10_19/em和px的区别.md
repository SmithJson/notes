<!-- vim-markdown-toc GitLab -->

* [em](#em)
	* [缺点](#缺点)
* [px](#px)
	* [缺点](#缺点-1)
* [rem](#rem)
	* [优点](#优点)

<!-- vim-markdown-toc -->

## em

em 是相对单位，没有固定值，首先参考自身的 font-size, 如果没有则以父元素的 font-size 为参考对象，浏览器的默认字体大小为 16px，所以 1em=16px，以此类推计算 12px=0.75px、10px=0.625em、32px=2em，为了
方便计算我们会在 body 中加入 `body { font-size: 62.5% } /* 计算公式 = 16px * 62.5%=10px */`，这样 1em=10px、1.2em=12px

### 缺点

1. em 的值不固定
2. em 参考父元素的字体大小，但父元素的字体大小也可能 em 单位，这样会造成最终的 em 计算值混乱
3. 当一个元素的 font-size: 1.2em，它的父元素为 font-size: 1.2em，父元素的父元素的 font-size: 1.2em，则此元素的 font-size 其实为 1.2em * 1.2em * 1.2em = 1.728em


## px

px 是绝对单位，参考对象是显示器分辨率。

### 缺点

1. px 是固定值，无法随页面的缩小而改变，不够灵活。

## rem

rem 是一个相对单位，与 em 的唯一区别是 rem 相对于根元素的 font-size 进行计算的。浏览器默认字体大小为 16px。1rem = 16px，但为了计算方便我们会在 html 中加入
`html { font-size: 62.5% } /* 16px * 62.5% = 10px */` 1rem = 10px、1.2rem = 12rem、1.6rem=16px

### 优点

1. rem 参考目标根元素 font-size 一般不会随意改变，使用起来比 em 安全的多。
2. rem 使用起来也比 em 方便多，rem 只需要考虑根元素的 font-size，但em 不仅要考虑父元素的 font-size，还需要考虑父元素的 font-size 是会随祖父元素的 font-size 而改变，容易造成计算混乱。
