## 自组件/Props & Emits/插槽

[返回目录](./vue教程.md)

1. [自组件/Props](#table11)
2. [Emits/插槽](#table2)

### <a id= "table1">自组件/Props</a>

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

### <a id= "table2">Emits/插槽</a>

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