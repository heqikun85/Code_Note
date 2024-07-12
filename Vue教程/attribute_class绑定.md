## attribute绑定 / 事件监听/ 表单绑定 class 绑定
[返回目录](./vue教程.md)  
1. [attribute绑定](#table1)
2. [事件监听](#table2)
2. [表单绑定](#table3)
3. [class绑定](#table4)

### <a id= "table1">attribute绑定</a>
为了给 attribute 绑定一个动态值，需要使用 v-bind 指令：

`<div v-bind:id="dynamicId"></div>`
冒号后面的部分 (:id) 是指令的“参数”。此处，元素的 id attribute 将与组件状态里的 dynamicId 属性保持同步。 专门的简写语法：
```js
<div :id="dynamicId"></div>
```

```js
<script setup>
import { ref } from 'vue'

const titleClass = ref('title')
</script>

<template>
  <h1 :class="titleClass"> 
    Make me red
  </h1> 
</template>

<style>
.title {
  color: red;
}
</style>
```
一开始的titleClass定义了titleClass的对象。style块中title赋值为red，然后在h1块中通过语法将内容绑定为titleClass


### <a id= "table2">事件监听</a>

我们可以使用 `v-on` 指令监听 DOM 事件：  
```js
<button v-on:click="increment">{{ count }}</button>

<button @click="increment">{{ count }}</button> //简写模式
```

```js
    <script setup>
    import { ref } from 'vue'
    const count = ref(0)
    function incre(){count.value++}
    </script>

    <template>
    <h1>Make me red</h1> <!-- 此处添加一个动态 class 绑定 -->
    
    <button @click="incre">{{count}}</button>
    </template>
```
**`<button>`的用法注意一下**

**作为事件监控的传参**
我们可以通过vue对内容的监控，传输相关的参数，其中也包括相关传输信息。
```js
    function getParameter(i,e){
        console.log(i.name,e);
    }    
```
上面这个function作为获取参数内容的function，传递了两个参数，一个是获取obj的value，一个是获取传输过程中的event。

```js
 <p @click="getParameter(i,$event)" v-for="(i,index) of obj"
    :key="i.id">{{i.id}} - {{i.value}} - {{i.name}}</p>
```
上面这段代码，通过@click调用getparameter这个function，调用两个参数，一个是obj，一个是$event

### <a id= "table3">表单绑定</a>

我们可以用同时使用`v-bind` 和 `v-on` 来在表单的输入元素上创建双向绑定：  
```js
<input :value="text" @input="onInput"> // :value 对应value，@input对应动态dom

function onInput(e) {
  // v-on 处理函数会接收原生 DOM 事件
  // 作为其参数。
  text.value = e.target.value // 获取方式。
}
```

为了简化双向绑定，Vue 提供了一个 `v-model` 指令，它实际上是上述操作的语法糖：  
`<input v-model="text">`

```js
<template>
    <h3>表单绑定</h3>
    <input v-model="message"> <!--同时做到属性绑定及输入事件监听-->
    <p>{{message}}</p>
    <input type="checkbox" id="checkbox" v-model="checked">
    <!--label中的for是将label的状态反馈到checkbox中，这个算是和checkbox连用的-->
    <label for="checkbox">{{ checked }}</label>
</template>
    
<script setup>
import {ref} from 'vue'
let message = ref("")
let checked = ref(false)
</script>
```

`v-model`提供了修饰符：`.lazy`,`.number`,`.trim`
`.lazy`: 默认情况下，`v-model`会在每次`input`时间后更新数据。但我们可以添加lazy修饰符来改为在每次change事件后更新数据。
`v-model.lazy`用这样的方式，上面的代码就$\color{red}{默认在输入完后按回车}$才显示更新内容

`v-model.number`: 将用户输入的字符串类型数据自动转换为数字类型数据，并将转换后的数字赋值给相应的data属性。
并且，可以叠加使用
```js
<input v-model.lazy.number="message"> 
<p>{{message + 1}}</p>
```

`v-model.trim`: 用于自动去除首尾空格的处理。这对于输入框等表单元素非常有用,可以确保用户输入的值不包含不必要的空格。

### <a id= "table4">class绑定</a>
以下代码阐述了大部分class绑定的方式，具体class的应用，还是要参考css的编写。css是最烦的
逻辑上style也能用这样的方式，但是我没理解为何要这么干，这会导致部分代码块非常复杂。
```js
<template>
    <h3 :class="'active'">单个class在双引号“”中也必须再加一个单引号引用</h3>
    <h3 :class="{'active':yesIs, 'where':yesIs}">多个可以用花括号，并且可以用bool判断来动态规划</h3>
    <h3 :class="myClass">也可以把样式写成object</h3> 
    <h3 :class="['big','where']">也可以是数组形式</h3>
    <h3 :class="yesIs ? 'active' : 'where'">也可以是二元判断法</h3>
    <h3 :class="['big',{'active':yesIs, 'where':noIs}]">数组和对象结合使用时，必须是数组嵌套对象</h3>
</template>
    
<script setup>
import {ref} from 'vue'
const yesIs = ref(true)
const noIs = ref(false)
const myClass = ref(
    {'active':true, 'big':true}
)
</script>

<style>
.active{
    color: red;
}
.big{
    font-size: 30px;
}
.where{
    display: flex;
    justify-content: center; /* 水平居中 */
    align-items: center; /* 垂直居中 */
}
</style>
```

