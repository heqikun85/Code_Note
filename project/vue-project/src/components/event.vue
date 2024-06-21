<template>
    <h3>模版引用</h3>
    <p ref="pElementRef">{{ content }}</p>

    <button @click="onMounted">获取元素</button>
</template>
    
<script setup>
import {onMounted,ref} from 'vue'

const content = ref("内容")
const pElementRef = ref(null)

onMounted(()=>{
    console.log(pElementRef.value)

})

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