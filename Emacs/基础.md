
<!-- vim-markdown-toc GitLab -->

* [快捷键](#快捷键)
	* [组合键位](#组合键位)
	* [基础快捷键](#基础快捷键)
	* [移动](#移动)
	* [C(trl) 组合键](#ctrl-组合键)
	* [M(alg)-x 组合键](#malg-x-组合键)
* [插件篇](#插件篇)
	* [快捷键](#快捷键-1)
	* [增强](#增强)
	* [配置插件](#配置插件)
* [org-mode](#org-mode)
* [搭建前端开发环境](#搭建前端开发环境)
* [插件](#插件)
	* [修改模式](#修改模式)
* [资源链接](#资源链接)

<!-- vim-markdown-toc -->

## 快捷键

### 组合键位

1. C(trl)
2. M(alt)
3. S(shift)
4. s(uper)【command】

### 基础快捷键
| 快捷键 | 描述            |
|--------|-----------------|
| q      | 退出当前 buffer |

### 移动
| 快捷键 | 描述          |
|--------|---------------|
| C-f    | forward 向前  |
| C-b    | backward 向后 |
| C-n    | next 向下     |
| C-p    | previous 向上 |
| C-a    | 跳行首        |
| C-e    | 跳行尾        |

### C(trl) 组合键

| 快捷键          | 描述                                                                             |
|-----------------|----------------------------------------------------------------------------------|
| C-g             | 中断指令                                                                         |
| C-h             | 查看详细信息                                                                     |
| C-x c-f         | 打开文件                                                                         |
| C-x c-s         | 保存文件                                                                         |
| C-h k/v/f/m     | 查询按键(keys)/变量(variable)/函数(function)/m(major mode & minor mode) 详细信息 |
| C-x c-e         | 执行当前行代码                                                                   |
| C-x 1/2/3       | 移除其他窗口/向下创建窗口/向右创建窗口                                           |
| C-x b / C-x C-b | 显示 buffers                                                                     |

### M(alg)-x 组合键

| 快捷键               | 描述                            |
|----------------------|---------------------------------|
| find-function        | 跳转查询的函数所在文件          |
| find-variable        | 跳转到查询的变量所在文件        |
| find-function-on-key | 跳转到 key 所运行函数所在的文件 |

## 插件篇

### 快捷键

| 快捷键                    | 描述         |
|---------------------------|--------------|
| M-x package-list-packages | 显示插件列表 |
| M-x package-autoremove    | 删除插件     |
| i                         | 安装标记     |
| u                         | 撤销标记     |
| D                         | 删除标记     |
| U                         | 更新标记     |
| x                         | 执行操作标记 |

### 增强

| 名称             | 描述                            |
|------------------|---------------------------------|
| company          | 代码提示                        |
| hungry-delete    | 删除多余空格                    |
| smex             | 增强 M-x 功能，C-s 进行选项切换 |
| swiper + counsel | 增强搜索功能，C-p/n 上下切换    |

### 配置插件

M-x customize-group 回车 -> 输入插件名

## org-mode

org-mode 可以等同于 markdown，以 .org 后缀名结尾的文件

| 快捷键    | 描述                                                                                               |
|-----------|----------------------------------------------------------------------------------------------------|
| tab       | toggle 大纲                                                                                        |
| C-c c-t   | toggle todo 状态                                                                                   |
| C-c '     | 快速编辑 `#+BEGIN_SRC emacs-lisp ... #+END_SRC` 代码块里的内容                                     |
| <s tab    | 快速生成 `#+BEGIN_SRC emacs-lisp ... #+END_SRC` 代码块。Emacs 27.1 好像得导入 (require 'org-tempo) |
| M-entery  | 修改 org-mode 中有序列表序号；生成样式一样的标题                                                   |
| C-c c-s/d | 创建任务开始时间/结束时间                                                                          |
| C-c a  a  | 查看任务                                                                                           |

## 搭建前端开发环境

## 插件
| 名称                 | 描述                                 |
|----------------------|--------------------------------------|
| js2-mode             | emacs 对 js 文件的处理模式           |
| nodejs-repl          | nodejs 执行 js 文件，M-x nodejs-repl |
| exec-path-from-shell | emacs 能使用命令行指令               |

### 修改模式

```emacs
;; config for js2-mode
(setq auto-mode-alist
      (append
       '(("\\.js\\'" . js2-mode))
       auto-mode-alist))

;; config for exec-path-from-shell
(when (memq window-system '(mac ns))
	(exec-path-from-shell-initialize))
```


## 资源链接

1. [Master Emacs in 21 Days](http://book.emacs-china.org/) 
2. [MELPA 官网](https://melpa.org/#/) 
