## 子组件 - Props & Emits

[返回目录](./vue教程.md)

1. [组件传递数据/Props](#table1)
2. [组件传递数据类型](#table3)
3. [Emits](#table2)
4. [v-model组件事件](#table4)

**因为props没有类型限制，所以可以通过function的方式把参数传回父组件。**
但是我觉得这个东西太复杂了，没什么特别大的用处。代码逻辑一定是尽量简单为好。
**vue教程视频第29集** 如果需要的话，跑过去再看好了。第30集好像也没什么用

### <a id= "table1">子组件/Props</a>

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
// const props = defineProps(["msg"]) 两种都行
</script>
```

父组件可以像声明 HTML attributes 一样传递 props。若要传递动态值，也可以使用 v-bind 语法：
```js
<!-- ParentComp.vue -->
<script setup>
import { ref } from 'vue'
import ChildComp from './ChildComp.vue'

const greeting = ref('Hello from parent')
</script>

<template>
  <ChildComp :msg="greeting" />
</template>
```

### <a id= "table3">组件传递数据类型</a>
props能接受任何数据类型，包括arrayList和object

```html
<!-- child component -->
<template>
    <h3>child</h3>
    <p>{{ msg }} - {{ age }}</p>
</template>
    
<script setup>
const props = defineProps(["msg","age"])

</script>

<!-- parent component -->
<template>
    <h3>parent</h3>
    <child :msg="greeting" :age="age"/>
</template>
    
<script setup>
import {ref} from 'vue'
import child from './child.vue'
const greeting = ref('hello world') 
let age = ref(12)
</script>
```

### <a id= "table2">Emits/插槽</a>

子组件还可以向父组件触发事件：
```js
  //  child component
<template>
    <h3>child</h3>
    <button @click="buttonClick">子组件传递数据</button>
</template>

<script setup>
const emit = defineEmits(['response'])
function buttonClick() {
//emit() 的第一个参数是事件的名称。其他所有参数都将传递给事件监听器。
    emit('response', 'hello from child')
}
</script>
```
因为`$emit`方法不能在`<script setup>`内使用，所以要用function的方法调用

父组件可以使用 v-on 监听子组件触发的事件——这里的处理函数接收了子组件触发事件时的额外参数并将它赋值给了本地状态：
```js
// parent component
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

### <a id= "table4">v-model组件事件</a>

```js
// child component
<template>
    搜索：<input type="text" v-model.lazy="search">
</template>
    
<script setup>
import {ref, watch} from 'vue'
const search = ref("")
const emit = defineEmits(['get'])

watch(search,(newValue)=>{
    emit('get',newValue)
})
</script>

{/* parent component */}
<template>
    <h3>parent</h3>
    <p>搜索内容为：{{ num }}</p>
    <child @get="(msg)=>num = msg"/>
    
</template>
    
<script setup>
import {ref} from 'vue'
import child from './child.vue'
const num = ref("")
</script>
```



