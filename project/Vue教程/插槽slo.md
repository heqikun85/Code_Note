## 插槽Slot

1. [插槽Slot](#table1)
   


### <a id= "table1">slot 插槽</a>

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