## 插槽Slot
[返回目录](./vue教程.md)

1. [插槽Slot](#table1)
2. [具名插槽](#table2)
3. [Slot的数据传递](#table3)
   


### <a id= "table1">slot 插槽</a>

父组件还可以通过插槽 (slots) 将模板片段传递给子组件：
```js 
// in child.vue
<slot>
  This is some slot content! {/*这里显示父组件传递过来的slot*/}
</slot>
```
在子组件中，可以使用 <slot> 元素作为插槽出口 (slot outlet) 渲染父组件中的插槽内容 (slot content)

```js
// in parent.vue
<script setup>
import { ref } from 'vue'
import ChildComp from './ChildComp.vue'

const msg = ref('from parent')
</script>

<template>
  <ChildComp>
    Message: {{ msg }} {/*也可以加入不同的块*/}
  </ChildComp>
</template>
```
ChildComp 中没有内容时则显示`<slot>Fallback content</slot>`中的内容


### <a id= "table2">具名插槽</a>
当我们需要传递多个不同的结构到子组件时，我们需要将不同的插槽出口命名。

```js
// in parent.vue
<template>
    <child>
        {/* <template v-slot:header> */}
        <template #header> {/*上面是完整写法，这个是简写方式*/}
            <h3>插槽内容</h3>
        </template>
        <template v-slot:body>
            <p>Message: "{{ msg }}"</p>
        </template>
    </child>
</template>

//in child.vue
<template>
    <slot name="header">
  This is some slot content!
    </slot>
    <hr>
    <slot name="body">
        defualt
    </slot>
</template>
```
在parent中用template包裹一个slot并为其命名。
在child中标注出口名字。

### <a id= "table3">slot的数据传递</a>
同时使用parent和child内的两种元素。我们可以通过props的方式将子组件的元素传参给slot


```js
// child component
<template>
    <slot>
      This is some slot content!
    </slot>
    <hr>
    <slot :msg="text">
      defualt
    </slot>
</template>
    
<script setup>
import {ref} from 'vue'
const text = ref("this is from child")
</script>

{/* parent component */}
<template>
    <child v-slot="slotProps">

            <h3>插槽内容</h3>
            <p>Message: "{{ msg }} - {{ slotProps.msg }}"</p>

    </child>
</template>
    
<script setup>
import child from './child.vue'
import {ref} from 'vue'
const msg = ref('this is from parent')
</script>
```
```java
插槽内容
Message: "this is from parent - "

插槽内容
Message: "this is from parent - this is from child"
```

从显示结果可知：
1. 只有调用child参数的slot可使用传参。
2. 如果要和具名同时使用，则在具名后加入传参

```js
// parent component
<template>
    <child>
        <template #header>
            <h3>插槽内容</h3>
        </template>
        <template #body="slotProps">
            <p>Message: "{{ msg }} - {{ slotProps.msg }}"</p>
        </template>
    </child>
</template>

// child component
<template>
    <slot name="header">
      This is some slot content!
    </slot>
    <hr>
    <slot name="body" :msg="text">
      defualt
    </slot>
</template>
```
   