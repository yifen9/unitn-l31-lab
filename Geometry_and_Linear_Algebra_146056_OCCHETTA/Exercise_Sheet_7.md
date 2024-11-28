# Exercise Sheet 7

---

## **Exercise 7.9.**

---

### a

Ricordiamo che $\lVert \bf{u}\rm \rVert = \sqrt{(\bf{u}\rm,\bf{u}\rm)}$ , quindi:

$$
\begin{aligned}

& \lVert \bf{u}\rm \rVert = \sqrt{4^2 + 2^2 + (-2)^2} = \sqrt{24} = 2\sqrt{6}

\\

& \lVert \bf{v}\rm \rVert = \sqrt{3^2 + (-3)^2 + 2^2} = \sqrt{22}

\end{aligned}
$$

### b

Si $\bf{w}\rm = (x,y,z)$ il generico vettore di $\R^3$ e imponiamo la condizione che sia ortogonale a $\bf{u}\rm$ e a $\bf{v}\rm$, ovvero $(\bf{u}\rm,\bf{w}\rm) = (\bf{v}\rm,\bf{w}\rm) = 0$ :

$$
\begin{cases}
 4x+2y-2z=0\\
 3x-3y+2z=0
\end{cases}
$$

Risolviamo il sistema considerando la matrice associata

$$
\begin{bmatrix}
 4&2&-2&|&0\\
 3&-3&2&|&0
\end{bmatrix}

\\
\Darr
\\

\begin{aligned}
 1/2I \\
 II+I
\end{aligned}
\begin{bmatrix}
 2&1&-1&|&0\\
 7&-1&0&|&0
\end{bmatrix}

\\
\Darr
\\

\begin{cases}
 2x+y-z=0\\
 7x-y=0
\end{cases}

\\
\Darr
\\

\begin{cases}
 x=t\\
 y=7t\\
 z=2t+7t=9t
\end{cases}
$$

Quindi il generico vettore $w$ ortogonale a $\bf{u}\rm$ e $\bf{v}\rm$ è del tipo

$$
(t,7t,9t)
$$

Imponiamo ora la condizione che $\bf{w}\rm$ abbia norma 1:

$$
\sqrt{t^2+(7t)^2+(9t)^2} = 1

\implies

\sqrt{131t^2} = 1

\implies

t = \pm\frac{1}{\sqrt{131}}
$$

Quindi abbiamo due possibili scelte per $\bf{w}\rm$ :

$$
\bf{w}\rm = \pm(\frac{1}{\sqrt{131}},\frac{7}{\sqrt{131}},\frac{9}{\sqrt{131}})
$$

---

## **Exercise** 7.10.

---

### a

La lunghezza di un vettore corrisponde alla sua norma:

$$
\begin{aligned}

& \lVert \bf{v}\rm_1 \rVert = \sqrt{4+1+1} = \sqrt{6}

\\

& \lVert \bf{v}\rm_2 \rVert = \sqrt{1+1} = \sqrt{2}

\end{aligned}
$$

### b

Utilizzando la formula per calcolare la proiezione ortogonale di $v_1$ su $v_2$ otteniamo:

$$
pr_{\bf{v}\rm_2}=\frac{(\bf{v}\rm_1,\bf{v}\rm_2)}{(\bf{v}\rm_2,\bf{v}\rm_2)}\cdot \bf{v}\rm_2=\frac{1}{2}\cdot(1,0,0,1)=(\frac{1}{2},0,0,\frac{1}{2})
$$

---

## Exercise 7.11.

---

Sia $\cal{B}^′ = \{\bf{u}\rm_1, \bf{u}\rm_2, \bf{u}\rm_3\}$ la base ortonormale che vogliamo ottenere a partire dalla base $\cal{B}$. Costruiamo prima una base $\cal{B}^{′′} = \{\bf{w}\rm_1, \bf{w}\rm_2, \bf{w}\rm_3\}$ di vettori a due a due ortogonali (non necessariamente di norma 1).

$$
\begin{aligned}

\bf{w}\rm_1&=\bf{v}\rm_1\\&=(-1,0,1)

\\

\bf{w}\rm_2&=\bf{v}\rm_2-pr_{\bf{w}\rm_1}(\bf{v}\rm_2)\\&=\bf{v}\rm_2-\frac{(\bf{v}\rm_2,\bf{w}\rm_1)}{(\bf{w}\rm_1,\bf{w}\rm_1)}\cdot \bf{w}\rm_1

\\

&=(0,1,0)-0\cdot \bf{w}\rm_1
\\
&=(0,1,0)

\\

\bf{w}\rm_3&=\bf{v}\rm_3-pr_{\bf{w}\rm_1}(\bf{v}\rm_3)-pr_{\bf{w}\rm_2}(\bf{v}\rm_3)

\\

&=\bf{v}\rm_3-\frac{(\bf{v}\rm_3,\bf{w}\rm_1)}{(\bf{w}\rm_1,\bf{w}\rm_1)}\cdot \bf{w}\rm_1-\frac{(\bf{v}\rm_3,\bf{w}\rm_2)}{(\bf{w}\rm_2,\bf{w}\rm_2)}\cdot \bf{w}\rm_2

\\

&=(1,0,1)-0\cdot \bf{w}\rm_1-0\cdot \bf{w}\rm_2
\\
&=(1,0,1)

\end{aligned}
$$

---

## Exercise 7.12.

---

Gli elementi di $U$ sono i vettori di $\R^3$ tali che $2x_1 + x_2 = 0$, ovvero

$$
\begin{array}{}

\begin{cases}
x_1=t\\
x_2=-2t\\
x_3=s
\end{cases}

&\forall s,t\in\R

\end{array}
$$

Quindi

$$
U=\langle(1,-2,0),(0,0,1)\rangle
$$

Poichè i due generatori sono tra loro ortogonali, per ottenere una base ortonormale di $U$ è sufficiente prenderli di norma 1:

$$
\cal{B}=\{(\frac{1}{\sqrt{5}},-\frac{2}{\sqrt{5}},0),(0,0,1)\}
$$

---

## Exercise 7.13.

---

Sia $\bf{u}\rm = (x, y, z, w)$ il generico elemento di $U^\perp$. Per la condizione di ortogonalità deve essere

$$
(\bf{u}\rm, \bf{v}\rm_1) = (\bf{u}\rm, \bf{v}\rm_2) = 0
$$

ovvero

$$
\begin{array}{}

\begin{cases}
x+y=0\\
x+2y-z+3w=0
\end{cases}

\implies

\begin{cases}
x=-t\\
y=t\\
z=t+3s\\
w=s
\end{cases}

&\forall s,t\in\R

\end{array}
$$

Quindi

$$
\begin{aligned}

U^\perp&=
\{
\begin{array}{}
(-1,1,1,0)\cdot t+(0,0,3,1)\cdot s&|&\forall s,t\in\R
\end{array}
\}

\\

&=\langle(-1,1,1,0),(0,0,3,1)\rangle

\end{aligned}
$$

---

## Exercise 7.14.

---

Il complemento ortogonale di $U$ è lo spazio

$$
\begin{aligned}
U^\perp
&=\{\begin{array}{}
\bf{v}\rm=(x,y,z,w)\in\R^4
&|
&(\bf{v}\rm,\bf{v}\rm_1)=(\bf{v}\rm,\bf{v}\rm_2)=0
\end{array}\}
\\
&=\{\begin{array}{}
\bf{v}\rm=(x,y,z,w)\in\R^4
&|
&2x+y+z=0,
&-x+y+2z=0
\end{array}\}
\end{aligned}
$$

Risolviamo il sistema di due equazioni in quattro incognite:

$$
\begin{cases}
2x+y+z=0\\
-x+y+2z=0
\end{cases}

\implies 2II+I

\begin{cases}
2x+y+z=0\\
3y+5z=0
\end{cases}

\implies

\begin{cases}
x=\frac{1}{3}t\\
y=-\frac{5}{3}t\\
z=t\\
w=s
\end{cases}
$$

Infine una base di $U^\perp$ è

$$
\cal{B}\rm(\it{U}\rm^\perp)=\{
(1,-5,3,0),(0,0,0,1)
\}
$$

---

## *Exercise 7.15.

---

### a

$$
\undergroup{

\begin{alignedat}{2}

&\begin{bmatrix}
2&1&0\\
-1&-2&3\\
3&0&3\\
0&1&-2
\end{bmatrix}

&\begin{array}{}
S_{12}\\
\implies\\
{}
\end{array}&
\begin{bmatrix}
-1&-2&3\\
2&1&0\\
3&0&3\\
0&1&-2
\end{bmatrix}

\\

\begin{array}{}
D_1(-1)\\
\implies\\
{}
\end{array}
&\begin{bmatrix}
1&2&-3\\
2&1&0\\
3&0&3\\
0&1&-2
\end{bmatrix}

&\begin{array}{}
E_{21}(-2)\\
\implies\\
E_{31}(-3)
\end{array}&
\begin{bmatrix}
1&2&-3\\
0&-3&6\\
0&-6&12\\
0&1&-2
\end{bmatrix}

\\

\begin{array}{}
D_2(-\frac{1}{3})\\
\implies\\
{}
\end{array}
&\begin{bmatrix}
1&2&-3\\
0&1&-2\\
0&-6&12\\
0&1&-2
\end{bmatrix}

&\begin{array}{}
E_{32}(6)\\
\implies\\
E_{42}(-1)
\end{array}&
\begin{bmatrix}
1&2&-3\\
0&1&-2\\
0&0&0\\
0&0&0
\end{bmatrix}

\end{alignedat}

}

\\
\Darr
\\

\cal{B}\rm(\it{U}\rm)=\{\bf{u}\rm_1,\bf{u}\rm_2\}
$$

### b

$$
\undergroup{

\begin{alignedat}{2}

&\begin{bmatrix}
2&-1&3&0\\
1&-2&0&1
\end{bmatrix}

&\begin{array}{}
S_{12}\\
\implies\\
{}
\end{array}&
\begin{bmatrix}
1&-2&0&1\\
2&-1&3&0
\end{bmatrix}

\\

\begin{array}{}
E_{21}(-2)\\
\implies\\
D_2(\frac{1}{3})
\end{array}
&\begin{bmatrix}
1&-2&0&1\\
0&1&1&-\frac{2}{3}
\end{bmatrix}

&\begin{array}{}
E_{12}(2)\\
\implies\\
{}
\end{array}&
\begin{bmatrix}
1&0&2&-\frac{1}{3}\\
0&1&1&-\frac{2}{3}
\end{bmatrix}

\end{alignedat}

}

\\
\Darr
\\

\begin{aligned}
U^\perp &= (-2x+\frac{1}{3}y,-x+\frac{2}{3}y,x,y)

\\&=x(-2,-1,1,0)+y(\frac{1}{3},\frac{2}{3},0,1)
\end{aligned}
$$

Choose $x=1$ and $y=3$ :

$$
\cal{B}\rm(\it{U}\rm^\perp)=\{(-2,-1,1,0),(1,2,0,3)\}
$$

---

## *Exercise 7.16.

---

Choose $\bf{v}\rm_1=(0,1)$ , $\bf{v}\rm_2=(1,0)$ :

$$
\undergroup{

\begin{aligned}

\bf{w}\rm_1'
&= \bf{v}\rm_1
\\
&= (0,1)

\\

\bf{w}\rm_2'
&= \bf{v}\rm_2 - pr_{\bf{w}\rm_1'}(\bf{v}\rm_2)
\\
&= \bf{v}\rm_2 - \frac{\bf{v}\rm_2\cdot\bf{w}\rm_1'}{\lVert\bf{w}\rm_1'\rVert^2}\bf{w}\rm_1'
\\
&= (1,0) - \frac{2\times0\times1+0\times0+1\times1+3\times1\times0}{2\times0\times0+0\times1+0\times1+3\times1\times1}(0,1)
\\
&= (1,0) - \frac{1}{3}(0,1)
\\
&= (1,-\frac{1}{3})

\end{aligned}

}

\\
\Darr
\\

\overgroup{
\undergroup{

\begin{aligned}

\bf{w}\rm_1
&= \frac{\bf{w}\rm_1'}{\lVert\bf{w}\rm_1'\rVert}
\\
&= \frac{1}{\sqrt{2\times0\times0+0\times1+0\times1+3\times1}}(0,1)
\\
&= \frac{1}{\sqrt{3}}(0,1)

\\

\bf{w}\rm_2
&= \frac{\bf{w}\rm_2'}{\lVert\bf{w}\rm_2'\rVert}
\\
&= \frac{1}{\sqrt{2\times1\times1+1\times(-\frac{1}{3})+(-\frac{1}{3})\times1+3\times(-\frac{1}{3})\times(-\frac{1}{3})}}(1,-\frac{1}{3})
\\
&= \frac{1}{\sqrt{\frac{5}{3}}}(1,-\frac{1}{3}) = \frac{\sqrt{15}}{5}(1,-\frac{1}{3})

\end{aligned}

}}

\\
\Darr
\\

\{\frac{1}{\sqrt{3}}(0,1),\frac{\sqrt{15}}{5}(1,-\frac{1}{3})\}
$$

---