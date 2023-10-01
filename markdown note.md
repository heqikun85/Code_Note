# Markdown note
## code comments
（# 一级标题）
（## 二级标题）
（### 三级标题）
—————————————— 分割线
**重点加粗** （** 前后无空格 **）  选中文本后  ctrl + B
*斜体* （* 前后无空格 *） 选中文本后 ctrl + I
以上两个可以结合使用，就是加粗斜体（ *** 前后无空格 *** ）
==高亮== （== 高亮 ==）
~~删除线~~ (~~ 前后无空格 ~~ )

## List
* 无序列表
  * 嵌套无序列表


1. 有序列表
   1. 嵌套有序列表
   2. 嵌套有序列表

## 引用文本
> 引用文本
> 可以将公式和引用内容放在这里

### 行内代码
``` python
print("hello, world")
```
python 位置可以更改代码语言来变换风格，比如
``` Java {.line-numbers}
print("hello, world")
this 
return
```

[super link](www.google.com)

![picture name](https://d2vlcm61l7u1fs.cloudfront.net/media%2Ffbc%2Ffbc9d706-9099-4509-8a09-037802cef53f%2Fphp7qLCFe.png)

### Table
| tab1 | tab2 |
| ---- | ---- |
| content | content |
| content | content |

| tab1 | tab2 |
| ---- | ---- |
| content | content |
| > | content |

### 希腊字母
小写	       指令	          大写
π \pi       π	$\pi$	      Π \Pi Π
α \alpha    α	$\alpha$	  A \Alpha A
β \beta     β	$\beta$	    B \Beta B
γ \gamma    γ	$\gamma$	  Γ \Gamma Γ
δ \delta    δ	$\delta$	  Δ \Delta Δ
ϵ \epsilon  ϵ	$\epsilon$	E \Epsilon E
λ \lambda   λ	$\lambda$	  Λ \Lambda Λ
μ \mu       μ	$\mu$	      M \Mu M
ω \omega    ω	$\omega$	  Ω \Omega Ω
σ \sigma    σ	$\sigma$    Σ \Sigma Σ
τ \tau      τ	$\tau$	    T \Tau  T
θ \theta    θ	$\theta$	  Θ \Theta Θ
ϕ \phi      ϕ	$\phi$	    Φ \Phi Φ
η \eta      η	$\eta$	    H \Eta H
ρ \rho      ρ $\rho$	    P \Rho P
ζ \zeta     ζ	$\zeta$	    Z \Zeta Z
ι \iota     ι	$\iota$ 	  I \Iota I
κ \kappa    κ	$\kappa$	  K \Kappa K
ν \nu       ν	$\nu$	      N \Nu N
ξ \xi       ξ	$\xi$	      Ξ \Xi Ξ
ο \omicron  ο	$\omicron$	O \Omicron O
υ \upsilon  υ	$\upsilon$	Υ \Upsilon Υ
χ \chi      χ	$\chi$	    X \Chi X
ψ \psi      ψ	$\psi$	    Ψ \Psi Ψ

将小写语法的首字母大写即可显示大写希腊字母；在大写希腊字母的指令前加var，可实现斜体显示

## 上标、下标

用 ^ 表示上标，用 _ 表示下标。比如
$x_i^2$
$\log_2 x$

如果上标或者下标的字符超过1个，则需要通过 {…} 以组的形式表示，比如：
$A_{ij}$

## 5.1 求和
∑	      $\sum$
∑       $\sum_1^n$
∑       $\sum_{i=1}^n$
∑       $$\sum_{i=1}^\infty$$

5.3 并集、交集
⋃	  $\bigcup$
⋂   $\bigcap$

$\frac ab$	a/b 

$\cfrac{a}{b}$	a/b 格式大一点​	
 
$\frac {a+1}{b+1}	a + 1 / b + 1 ​	
 
$\cfrac {a+1}{b+1}	a + 1 / b + 1 格式大点
​	
 
${a+1\over b+1}$	
 
$\sqrt x$	
 
$\sqrt [x]{y}$

$\log$ ----  $\ln$

$\sin x$	-- $\cos x$	-- $\tan x$	-- $\csc x$	-- $\sec x$	-- $\cot x$

$\lt$	< \lt <
$\gt$	> \gt >
$\le$	≤ \le ≤
$\leq$	≤ \leq ≤
$\leqq$	≦ \leqq ≦
$\leqslant$	⩽ \leqslant ⩽
$\ge$	≥ \ge ≥
$\geq$	≥ \geq ≥
$\geqq$	≧ \geqq ≧
$\geqslant$	⩾ \geqslant ⩾
$\neq$	≠ \neq 
$\approx$	≈ \approx ≈
$\sim$	∼ \sim ∼
$\simeq$	≃ \simeq ≃
$\cong$	≅ \cong ≅
$\equiv$	≡ \equiv ≡
$\prec$	≺ \prec ≺
$\because$	∵ \because ∵
$\therefore$	∴ \therefore ∴

$\cup$	∪ \cup ∪
$\cap$	∩ \cap ∩
$\setminus$	∖ \setminus ∖
$\subset$	⊂ \subset ⊂
$\subseteq$	⊆ \subseteq ⊆
$\subsetneq$	⊊ \subsetneq ⊊
$\supset$	⊃ \supset ⊃
$\in$	∈ \in ∈
$\notin$	∉ \notin ∈ 
​	
 
$\emptyset$	∅ \emptyset ∅
$\varnothing$	∅ \varnothing ∅

$\to$	→ \to →
$\rightarrow$	→ \rightarrow →
$\leftarrow$	← \leftarrow ←
$\uarr$	↑ \uarr ↑
$\darr$	↓ \darr ↓
$\harr$	↔ \harr ↔
$\Rightarrow$	⇒ \Rightarrow ⇒
$\Leftarrow$	⇐ \Leftarrow ⇐
$\hArr$	⇔ \hArr ⇔

$\exists$	∃ \exists ∃
$\forall$	∀ \forall ∀

