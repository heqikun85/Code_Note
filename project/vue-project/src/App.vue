<template>
  <event />
  <!--
  <h3 :id="msgId">Vue模块语言学习</h3>
  <p :id="msgId">{{msg}}</p>
  <p>{{number + 1}}</p>
  <button @click="rev">{{ok ? msg : number++}}</button>
  <p v-if="number%2!=1">{{msg}}</p>
  <p v-else-if="number%3==0">ok is false</p>
  <p>{{number%3}}</p>
  
  <biv v-for="(i, index) of item " :key="index">
    <p>{{i.name}}</p>
    <p>{{i.age}}</p>
    <p>{{i.where}}</p>r
    <p>{{index}}</p>
  </biv> 
  -->
  </template>
  
  <script setup>
  import event from "./components/event.vue"
  import {ref} from "vue"
  /*
  const msg = 'this is a example'
  const msgId = ref('msgId')
  let number = 10
  let ok = ref(true)
  function rev(){ok.value = !ok.value}
  const item = ref([
    {
      name: 'kevin',
      age: 38,
      where: 'shanghai'
    },
    { name: 'angela',
      age: 38,
      where: 'san francisco'
    },
    {
      name: `cathy`,
      age:40,
      where: `pine creek`
    }
  ])
    */
  </script>
  
  <style>
  #msgId{
    color: red;
  }
  </style>
  
  
  
  
  
  
  
  
  
  
  
  

