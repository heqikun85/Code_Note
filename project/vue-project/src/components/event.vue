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