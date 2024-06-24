<template>
    <h3>Component A</h3>
    <p>{{ msg }}</p>
    <button @click="updata">更新数据</button>
</template>
    
<script>
export default{
    data(){
        return{
            msg:"老数据"
        }
    },
    beforeUnmount(){
        console.log("组件卸载之前")
    },
    unmounted(){
        console.log("组件卸载之后")
    },
    methods:{
        updata(){
            this.msg = "新数据"
        }
    }
}
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