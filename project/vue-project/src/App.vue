<template>
  <h3>祖宗component</h3>
  <eventA />
</template>
  
<script setup>
  import {ref,provide} from 'vue'
  import eventA from './components/eventA.vue'

  const msg = ref("hello 来自parent") 
  provide("title",msg )
</script>
  
<style>
  #msgId{
    color: red;
  }
</style>
  
  
  
  
  
  
  
  
  
  
  
  

