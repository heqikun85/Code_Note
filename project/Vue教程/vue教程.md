# Vue教程

1. [创建Vue项目](#table1)
2. [HTML&CSS基础](./HTML&CSS基础.md)
3. [响应式调用](./响应式调用.md)
4. [attribute & 事件监听 & 表单绑定 & class绑定](./attribute_class绑定.md)
5. [条件/列表渲染](./条件_列表渲染.md)
6.  [计算属性](./计算属性.md)
7.  [生命周期和模板引用 & 侦听器（有异步function的写法）](./模版引用_侦听器.md) 
8.  [Vue组件应用](./vue组件.md)
9.  [自组件/Props & Emits/插槽](./自组建_Emits插.md)
10. [ArrayList更新](#table2)
11. [开发过程中的实例](#table14)
12. 
13. [](#table16)
14. [](#table17)
15. [](#table18)
16. [](#table19)


### <a id="table1">创建Vue项目</a>
在teminal中运行：`npm create vue@latest` or `npm init vue@latest`
```js
✔ Project name: … <your-project-name>
✔ Add TypeScript? … No / Yes
✔ Add JSX Support? … No / Yes
✔ Add Vue Router for Single Page Application development? … No / Yes
✔ Add Pinia for state management? … No / Yes
✔ Add Vitest for Unit testing? … No / Yes
✔ Add an End-to-End Testing Solution? … No / Cypress / Nightwatch / Playwright
✔ Add ESLint for code quality? … No / Yes
✔ Add Prettier for code formatting? … No / Yes
✔ Add Vue DevTools 7 extension for debugging? (experimental) … No / Yes

Scaffolding project in ./<your-project-name>...
Done.
```
如果不确定是否要开启某个功能，你可以直接按下回车键选择 No。在项目被创建后，通过以下步骤安装依赖并启动开发服务器：
```js 
cd <your-project-name>
cnpm install
npm run dev
```
完成创建后项目内文件夹目录：
- node_modules: Vue项目运行的依赖文件夹
- public：资源文件夹（浏览器图标）
- src：源码文件夹（和java一样）
- jsconfi.json
- package-lock.json
- package.json：项目名/项目版本/运行模式/vue版本依赖
- components：Vue和java一样能内联不同的.vue文件当作组件，并调用方法。

`import fileName from‘./components/fileName.vue’` 在head引用该文件即可使用该文件的方法。
              

### <a id= "table2">ArrayList 更新</a>

ArrayList的更新，在Vue应用中分为两种模式：
1. 变更方法：在更新ArrayList过程中，UI同时变更。
   * push(): 添加数组
   * pop(): 删除数组中最后一项
   * shift(): 删除第一项
   * unshift(elem): 将参数添加到数组第一项，element不限数量
   * splice(): 这个可以删除多个数组内容，有多种用法，用前查阅
   * sort(): 排序
   * reverse(): 反转  

    以上方法都会更新UI，实时显示在网页上。

2. 替换一个数组
   *  filter(): 筛选数组
   *  concat(): 合并两个数组
   *  slice(): 
  
    以上三个方法不会更新UI。如果需要使用这三个方法并更新UI，需要将这三个方法更新后的新数组赋值个原数组。





### <a id= "table14">开发过程中的实例</a>
每个绑定仅支持单一表达式。也就是仅一段能放在return后面的代码。


