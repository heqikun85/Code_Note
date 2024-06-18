# Vue教程

1. [响应式调用](#table1)
2. [attribute绑定](#table2)
3. [事件监听](#table3)
4. [表单绑定](#table4)
5. [条件渲染](#table5)
6. [列表渲染](#table6)
7. [计算属性](#table7)
8. [生命周期和模板引用](#table8)
9. [侦听器（有异步function的写法）](#table9)
10. [自组件/Props](#table10)
11. [Emits/插槽](#table11)
12. [开发过程中的实例](#table12)
13. [](#table13)
14. [](#table14)
15. [](#table15)
16. [](#table16)
17. [](#table17)
18. [](#table18)
19. [](#table19)
20. [](#table20)

### 创建Vue项目
在teminal中运行：`npm create vue@latest`
```js
✔ Project name: … <your-project-name>
✔ Add TypeScript? … No / Yes
✔ Add JSX Support? … No / Yes
✔ Add Vue Router for Single Page Application development? … No / Yes
✔ Add Pinia for state management? … No / Yes
✔ Add Vitest for Unit testing? … No / Yes
✔ Add an End-to-End Testing Solution? … No / Cypress / Nightwatch / Playwright
✔ Add ESLint for code quality? … No / Yes
✔ Add Prettier for code formatting? … No / Yes
✔ Add Vue DevTools 7 extension for debugging? (experimental) … No / Yes

Scaffolding project in ./<your-project-name>...
Done.
```
如果不确定是否要开启某个功能，你可以直接按下回车键选择 No。在项目被创建后，通过以下步骤安装依赖并启动开发服务器：
```js 
cd <your-project-name>
cnpm install
npm run dev
```
完成创建后项目内文件夹目录：
- node_modules: Vue项目运行的依赖文件夹
- public：资源文件夹（浏览器图标）
- src：源码文件夹（和java一样）
- jsconfi.json
- package-lock.json
- package.json：项目名/项目版本/运行模式/vue版本依赖


### <a id= "table1">响应式调用</a>

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


### <a id= "table2">attribute绑定</a>
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

### <a id= "table3">事件监听</a>

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

### <a id= "table4">表单绑定</a>

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

### <a id= "table5">条件渲染</a>

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

### <a id= "table6">列表渲染</a>

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

### <a id= "table7">计算属性</a>

通过给每一个 todo 对象添加 done 属性来实现的，并且使用了 v-model 将其绑定到复选框上：  
通过对done的true/false判断来完成html内容的更新。  

API：computed()。它可以让我们创建一个计算属性 ref，这个 ref 会动态地根据其他响应式数据源来计算其 .value：

```js
<script setup>
import { ref, computed } from 'vue' // 加入computed API

let id = 0

const newTodo = ref('')
const hideCompleted = ref(false)
const todos = ref([
  { id: id++, text: 'Learn HTML', done: true },
  { id: id++, text: 'Learn JavaScript', done: true },
  { id: id++, text: 'Learn Vue', done: false }
])

// 二元判断法，return hideCompleted的value，而hideCompleted的value在html上由click控制每次都逆向。
// ？之后 当hideCompleted为true，则筛选出相关内容。：之后则为false后内容。

const filteredTodos = computed(() => {
  return hideCompleted.value
    ? todos.value.filter((t) => !t.done)
    : todos.value
})

function addTodo() {
  todos.value.push({ id: id++, text: newTodo.value, done: false })
  newTodo.value = ''
}

function removeTodo(todo) {
  todos.value = todos.value.filter((t) => t !== todo)
}
</script>

<template>
  <form @submit.prevent="addTodo">
    <input v-model="newTodo" required placeholder="new todo">
    <button>Add Todo</button>
  </form>
  <ul>
    <li v-for="todo in filteredTodos" :key="todo.id">
      <input type="checkbox" v-model="todo.done">
      <span :class="{ done: todo.done }">{{ todo.text }}</span>
      <button @click="removeTodo(todo)">X</button>
    </li>
  </ul>
  <button @click="hideCompleted = !hideCompleted">
    {{ hideCompleted ? 'Show all' : 'Hide completed' }} //这里也用二元法分别现实内容
  </button>
</template>

<style>
.done {
  text-decoration: line-through;
}
</style>
```

### <a id= "table8">生命周期和模板引用</a>

Vue的响应式和声明式在大部分情况下可以自动更新DOM，但也需要手动更新，这时我们需要使用模板引用——也就是指向模板中一个 DOM 元素的 ref。  
我们需要通过这个特殊的 ref attribute 来实现模板引用： `<p ref="pElementRef">hello</p>`

要访问该引用，我们需要声明一个同名的 ref：`const pElementRef = ref(null)`  
注意这个 ref 使用 null 值来初始化。这是因为当 `<script setup>` 执行时，DOM 元素还不存在。模板引用 ref 只能在组件挂载后访问。  
要在挂载之后执行代码，我们可以使用 onMounted() 函数：  
```js
import { onMounted } from 'vue'

onMounted(() => {
  // 此时组件已经挂载。
})
```

这被称为生命周期钩子——它允许我们注册一个在组件的特定生命周期调用的回调函数。  
还有一些其他的钩子如 onUpdated 和 onUnmounted。

```js
<script setup>
import { ref , onMounted} from 'vue'

// 通过onMounted组件，来更改p的内容，在 `<p>` 内使用了`ref = “pElementRef”`，这样能通过更改pElementRef来更改相应内容
onMounted(()=>{
  pElementRef.value.textContent = "mounted"
})
const pElementRef = ref(null)
</script>

<template>
  <p ref="pElementRef">Hello</p>
</template>
```

### <a id= "table9">侦听器（有异步function的写法）</a>

`import { ref, watch } from 'vue'`这是监听器的pack

```js
watch(count, (newCount) => {
  // 没错，console.log() 是一个副作用
  console.log(`new count is: ${newCount}`)
})
```
基本语法为，watch（监控对象，function）


```js
<script setup>
import { ref, watch } from 'vue'

const todoId = ref(1)
const todoData = ref(null)

//这是一个异步抓取信息的 function， 注意异步的写法，以后可以用到
async function fetchData() {
  todoData.value = null
  const res = await fetch(
    `https://jsonplaceholder.typicode.com/todos/${todoId.value}`
  )
  todoData.value = await res.json()
}

fetchData()
  
watch(todoId, fetchData)
</script>

<template>
  <p>Todo id: {{ todoId }}</p>
  <button @click="todoId++" :disabled="!todoData">Fetch next todo</button>
  <p v-if="!todoData">Loading...</p>
  <pre v-else>{{ todoData }}</pre>
</template>
```

### <a id= "table10">自组件/Props</a>

父组件可以在模板中渲染另一个组件作为子组件。要使用子组件，我们需要先导入它：
`import ChildComp from './ChildComp.vue'`

然后我们就可以在模板中使用组件，就像这样：`<ChildComp />`

子组件可以通过 props 从父组件接受动态数据。首先，需要声明它所接受的 props：
```js
<!-- ChildComp.vue -->
<script setup>
const props = defineProps({
  msg: String
})
</script>
```
这一段不需要编写，是默认在ChildComp组件内的。

父组件可以像声明 HTML attributes 一样传递 props。若要传递动态值，也可以使用 v-bind 语法：
```js
<script setup>
import { ref } from 'vue'
import ChildComp from './ChildComp.vue'

const greeting = ref('Hello from parent')
</script>

<template>
  <ChildComp :msg="greeting" />
</template>
```

### <a id= "table11">Emits/插槽</a>

子组件还可以向父组件触发事件：
```js
<script setup>
// 声明触发的事件
const emit = defineEmits(['response'])

// 带参数触发
emit('response', 'hello from child')
</script>
```
emit() 的第一个参数是事件的名称。其他所有参数都将传递给事件监听器。

父组件可以使用 v-on 监听子组件触发的事件——这里的处理函数接收了子组件触发事件时的额外参数并将它赋值给了本地状态：
```js
<script setup>
import { ref } from 'vue'
import ChildComp from './ChildComp.vue'

const childMsg = ref('No child msg yet')
</script>

<template>
  <ChildComp @response = "(msg)=> childMsg = msg"/>
  <p>{{ childMsg }}</p>
</template>
```

父组件还可以通过插槽 (slots) 将模板片段传递给子组件：
```js 
<ChildComp>
  This is some slot content!
</ChildComp>
```
在子组件中，可以使用 <slot> 元素作为插槽出口 (slot outlet) 渲染父组件中的插槽内容 (slot content)

```js
<script setup>
import { ref } from 'vue'
import ChildComp from './ChildComp.vue'

const msg = ref('from parent')
</script>

<template>
  <ChildComp>Message: {{ msg }}</ChildComp>
</template>
```
ChildComp 中没有内容时则显示`<slot>Fallback content</slot>`中的内容

### <a id= "table12">开发过程中的实例</a>
每个绑定仅支持单一表达式。也就是仅一段能放在return后面的代码。


