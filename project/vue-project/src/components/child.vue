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