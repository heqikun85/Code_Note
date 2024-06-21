<template>
    <h3>表单绑定</h3>
    <input v-model.lazy.number="message"> <!--同时做到属性绑定及输入事件监听-->
    <p>{{message + 1}}</p>
    <input type="checkbox" id="checkbox" v-model="checked">
    <!--label中的for是将label的状态反馈到checkbox中，这个算是和checkbox连用的-->
    <label for="checkbox">{{ checked }}</label>
</template>
    
<script setup>
import {ref} from 'vue'
let message = ref("")
let checked = ref(false)
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