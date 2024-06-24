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