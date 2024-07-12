<template>
  <h3>Child Component</h3>
  <p>{{ title }}</p>
</template>
    
<script setup>
import {ref,inject} from 'vue'

const title = inject("title")
</script>