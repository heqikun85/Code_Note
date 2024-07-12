<template>
    <h3>Parent component</h3>
    <eventB />
</template>
    
<script setup>
import {ref,defineProps} from 'vue'
import eventB from './eventB.vue'

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