
<!-- vim-markdown-toc GitLab -->

* [过渡和动画出来之前的特效处理](#过渡和动画出来之前的特效处理)
* [transition 过渡](#transition-过渡)
* [animation 帧动画](#animation-帧动画)
* [两者的区别](#两者的区别)
* [易混淆的概念](#易混淆的概念)

<!-- vim-markdown-toc -->

## 过渡和动画出来之前的特效处理

在 CSS3 的 transition、animation 出来之前，我们通常使用伪类和js 控制 CSS 样式的方式，来实现简单动画。但通过这种方式设置的动画，会立即到达最终样式，而没有中间过渡效果
，后面 CSS3 新出的这两种就解决了这一问题。

## transition 过渡

显示元素从初始状态到终止状态的过渡动画。

| 属性                       | 描述                                                     |
|----------------------------|----------------------------------------------------------|
| transition-property        | 要检测的过渡属性名                                       |
| transition-duration        | 过渡动画的持续时间                                       |
| transition-timing-function | 过渡动画的运动类型                                       |
| transition-delay           | 过渡动画的延迟时间【延迟多长时间后，才开始执行过渡动画】 |

可以简写为 transition: property duration timing-function delay，如果要检测多个属性可以使用逗号【,】隔开书写。

## animation 帧动画

显示元素从初始状态到最终状态过程中的每一帧的动画，通过 keyframe 关键字创建动画，通过 animation 执行动画。

| 属性                      | 描述                                                                                                                                                                  |
|---------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| animation-name            | 要执行的动画名                                                                                                                                                        |
| animation-duration        | 动画的持续时间                                                                                                                                                        |
| animation-timing-function | 动画的运动类型                                                                                                                                                        |
| animation-delay           | 动画的延迟时间                                                                                                                                                        |
| animation-iteration-count | 动画的执行次数。nfinite 为无限次                                                                                                                                      |
| animation-direction       | 动画的方向。normal（时间轴正向运动）、reverse（时间轴反向运动）、alternate（时间轴正向运动，再时间轴反向运动）、alternate-reverse（时间轴反向运动，再时间轴正向运动） |
| animation-play-state      | 动画运动状态。running（运动中）、paused（暂停）                                                                                                                       |
| animation-fill-mode       | 动画结束后，元素保持的状态。none（动画还没开始的状态）、forwards（动画结束的状态） 、backwards（动画第一帧的状态）、both（forwards 和 backwords 轮流切换）            |

简写为 animation: name duration timing-function delay iteration-count direction play-state fill-mode

## 两者的区别

1. transition 需要触发条件；animation 会自动执行
2. transition 更容易与 js 结合
3. transition 提供的属性比 animation 的属性少
4. transition 的精度控制力度比 animation 小

## 易混淆的概念

1. animation（动画）:用于设置动画属性
2. transition（过渡）设置元素的样式过渡
3. transform（变换）：用于设置元素的移动、缩放、旋转、倾斜
4. translate（移动）：是 transform 里的一个子属性
