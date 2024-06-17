# Vue教程

### 响应式调用

Vue是将从属于同一个组件的 HTML、CSS 和 JavaScript 封装在使用 .vue 后缀的文件中。  
Vue 的核心功能是声明式渲染：通过扩展于标准 HTML 的模板语法，我们可以根据 JavaScript 的状态来描述 HTML 应该是什么样子的。  
当状态改变时，HTML 会自动更新。  

能在改变时触发更新的状态被称作是响应式的。我们可以使用 Vue 的 reactive() API 来声明响应式状态。  
由 reactive() 创建的对象都是 JavaScript Proxy，其行为与普通对象一样：  

```js
import { reactive } from 'vue'

const counter = reactive({
  count: 0
})

console.log(counter.count) // 0
counter.count++
```
`reactive() `只适用于对象 (包括数组和内置类型，如` Map `和 `Set`)。它不能持有如 `string`、`number` 或 `boolean` 这样的原始类型。
而另一个 API `ref()` 则可以接受任何值类型。ref 会返回一个包裹对象，并在 .`value` 属性下暴露内部值。

```js
import { ref } from 'vue'

const message = ref('Hello World!')

console.log(message.value) // "Hello World!"
message.value = 'Changed'
```

`reactive()` 和` ref() `的细节在指南 - 响应式基础一节中有进一步讨论。

在组件的 `<script setup> `块中声明的响应式状态，可以直接在模板中使用。   
下面展示了我们如何使用双花括号语法，根据 `counter `对象和 `message ref `的值渲染动态文本：

```js
<h1>{{ message }}</h1>
<p>Count is: {{ counter.count }}</p>
```
注意我们在模板中访问的 `message ref` 时不需要使用 `.value`：它会被自动解包，让使用更简单。

在双花括号中的内容并不只限于标识符或路径——我们可以使用任何有效的 JavaScript 表达式。

```js
<h1>{{ message.split('').reverse().join('') }}</h1>
```

split('') 是将每个字符用空格分开，reverse()是把字符全都倒转，join（）是把他们再组合起来   
有一个关键，join时会把string内原本的空格跳过，仍然封装回去。

**这种双花括号的用法教 mustache语法**

`<script setup>` block 让代码变得简单了，只需要在这个块中定义响应内容。


### attribute绑定
为了给 attribute 绑定一个动态值，需要使用 v-bind 指令：

```js
<div v-bind:id="dynamicId"></div>
```
冒号后面的部分 (:id) 是指令的“参数”。此处，元素的 id attribute 将与组件状态里的 dynamicId 属性保持同步。  
由于 v-bind 使用地非常频繁，它有一个专门的简写语法：
`<div :id="dynamicId"></div>`

```js
<script setup>
import { ref } from 'vue'

const titleClass = ref('title')
</script>

<template>
  <h1 :class="titleClass">Make me red</h1> <!-- 此处添加一个动态 class 绑定 -->
</template>

<style>
.title {
  color: red;
}
</style>
```
一开始的titleClass定义了titleClass的对象。style块中title赋值为red，然后在h1块中通过语法将内容绑定为titleClass

### 事件监听

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
    
    <button @click="incre">
    {{count}}
    </button>
    </template>
```
**`<button>`的用法注意一下**

### 表单绑定

我们可以同时使用 `v-bind` 和 `v-on` 来在表单的输入元素上创建双向绑定：  
```js
<input :value="text" @input="onInput"> // :value 对应value，@input对应动态dom

function onInput(e) {
  // v-on 处理函数会接收原生 DOM 事件
  // 作为其参数。
  text.value = e.target.value // 获取方式。
}
```

为了简化双向绑定，Vue 提供了一个 `v-model` 指令，它实际上是上述操作的语法糖：  
```<input v-model="text">```

### 条件渲染

```js
<h1 v-if="awesome">Vue is awesome!</h1>
```  
这个 `<h1>` 标签只会在 awesome 的值为真值 (Truthy) 时渲染。若 awesome 更改为假值 (Falsy)，它将被从 DOM 中移除。

我们也可以使用 `v-else` 和 `v-else-if` 来表示其他的条件分支：
```js
<script setup>
import { ref } from 'vue'

const awesome = ref(true)

function toggle() {
  awesome.value = !awesome.value // 每次点击都逆反结果
}
</script>

<template>
  <button @click="toggle">Toggle</button>
  <h1 v-if="awesome">Vue is awesome!</h1>
  <h1 v-else>Oh no 😢</h1> //else不需要对应awesome
</template>
```

### 列表渲染

我们可以使用 v-for 指令来渲染一个基于源数组的列表：
```js
<ul>
  <li v-for="todo in todos" :key="todo.id">
    {{ todo.text }}
  </li>
</ul>
```
这里的 todo 是一个局部变量，表示当前正在迭代的数组元素。它只能在 v-for 所绑定的元素上或是其内部访问，就像函数的作用域一样。

注意，我们还给每个 todo 对象设置了唯一的 id，并且将它作为特殊的 key attribute 绑定到每个 `<li>`。   
key 使得 Vue 能够精确的移动每个 `<li>`，以匹配对应的对象在数组中的位置。

更新列表有两种方式：
```js
//在源数组上调用变更方法
todos.value.push(newTodo)

// 使用新的数组替代原数组
todos.value = todos.value.filter(/* ... */)
```

```js
<script setup>
import { ref } from 'vue'

let id = 0  // 给每个 todo 对象一个唯一的 id

const newTodo = ref('') //初始化newTodo内容

//之前定义了id，每个id对应一个text内容
const todos = ref([
  { id: id++, text: 'Learn HTML' },
  { id: id++, text: 'Learn JavaScript' },
  { id: id++, text: 'Learn Vue' }
])

function addTodo() {
  // ...
  todos.value.push({id: id++, text: newTodo.value}) //在todos内新增value的情况需要吧id也一起考虑进去
  newTodo.value = '' // 添加完后需要把newTodo清空
}

function removeTodo(todo) {
  // ...
  todos.value = todos.value.filter((t)=> t!==todo) //洗面有详细这段代码的解释
}
</script>

<template>
    //整个块应该是将输入框和button打包在一个块内，submi.prevent 应该是和@click一样获取addTodo function的  
  <form @submit.prevent="addTodo"> 
    // v-model将捕获input作为newTodo的值，required placeholder是常驻显示在输入框上的内容
    <input v-model="newTodo" required placeholder="new todo"> 
    <button>Add Todo</button>
  </form>
  <ul>
    //v-for，想for循环一样，循环现实todo，内部内容为todo in todos，然后以id为key，现实todo.text
    <li v-for="todo in todos" :key="todo.id">
      {{ todo.text }}
      <button @click="removeTodo(todo)">X</button> // 实现removeTodo funciton
    </li>
  </ul>
</template>
```