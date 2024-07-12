//import './assets/main.css'

import { createApp } from 'vue'
import App from './App.vue'
//import HelloWorld from './components/HelloWorld.vue'

createApp(App).mount('#app') //没有全局注册组件时使用该段

/* const app = createApp(App)
//如果需要全局注册组件，则我们将 createAPP(app)赋值给一个常量。在调用mount()前注册组件
app.component("Hello",HelloWorld)
//调用组件时只需要用第一个参数名即可 <Hello />

app.mount('#app') */
