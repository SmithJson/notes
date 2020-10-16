
<!-- vim-markdown-toc GitLab -->

* [使用transform 不使用 margin 的原因](#使用transform-不使用-margin-的原因)
* [transform 的原理](#transform-的原理)
* [独立的合成层形成条件](#独立的合成层形成条件)
* [margin](#margin)
* [transform 的局限性](#transform-的局限性)

<!-- vim-markdown-toc -->

## 使用transform 不使用 margin 的原因

transform 会创建单独的图层，margin 会导致回流和重绘

## transform 的原理

transform 会单独创建一个 Render Layers 合成层，拥有一个独立的 Graphics Layers。每一个 Graphics Layers 都有一个 Graphics Context，其对应的 Render Layers 会 paint 进 Graphics Context
中。合成器最终会负责将 Graphics Context 输出的位图合并成最终屏幕展示的图案。

## 独立的合成层形成条件

1. 有 3D 或者 perspective、transform 的 CSS 属性层
2. video 元素的层
3. canvas 元素的层
4. flash
5. 对 opacity 和 transform 应用里 CSS 动画的层
6. 使用里 CSS 滤镜的层
7. 有合成层后代的层
8. 同合成层重叠，且在该合成层上面的层

## margin

margin：外边距，可以通过 margin 改变元素的位置，但改变位置的同时也会使 render tree 结构改变，引起页面的回流和重绘。因此，从性能来考虑，transform 比 margin 的性能更好。

## transform 的局限性

虽然使用 transform. 会使用 GPU 进行加速，但当图层数量很多时，也会占用大量内存，使渲染的消耗大于性能的优化。
