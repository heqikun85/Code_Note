Vector：
和array类似，但属于动态数组，不需要提前定义好数组大小。使用时需要在头文件位置加<vector>

定义vector时，我们需要定义vector的类型： vector<type> vectorName(vectorSize)

Vector<type> vectorName (other vector) 可以用来复制vector。所以两个vector可以用“=”来对比。

Const vector<type> &newName
For(type vectorName : newname)
	cout << vectorName << “ ”;
这个方式可以output 整个vector。

cin 一个vector ： Const vector<type> &newName
for(type &vectorName : newname)
cin << vectorName;

v[i]或v.at(i)  //返回v[i]的值
v.size();     //返回v数组元素总个数
v.front();    //返回v数组第一个元素的值
v.back();    //返回v数组最后一个元素的值
v.clear();    //清空v数组
v.begin();   //返回v数组第一个数的地址
v.end();    //返回v数组最后一个数之后的地址
v.empty();  //判断v数组是否为空，是空则返回1(true)，非空（有元素）则返回0(false)
v.swap(v1);  //v1是另一个动态数组，将v和v1元素互换
swap(v,v1);  //同上

vector的添加：
vectorName.push_back（element）用来在vector末尾增加新的项目。
v.insert(v.begin()+k,a);//在下标k的前面插入数a，k之后的数依次后退一位
v.insert(v.begin()+k,p,a);//在下标k前面插入p个a

vector的删除：
v.pop_back()//删除最后一个元素
v.erase(v.begin()+k);//删除下标为k的数，返回下一个位置的下标
v.erase(v.begin()+l,v.end()-r);//删除下标[l,v.end()-r)的元素


Stack: 堆栈 (先进后出)
Stack 也需要头文件 <stack>
设定stack ： stack<type> stackName；
Stack operations： 
stackName.push(Num)  // 在堆栈顶端加入数据 （push）
stackName.top ( ) ；   // get the top value 获得顶部数据。
stackName.pop ( );     // kill the top value 在堆栈顶端移除数据（POP）。
stackName.empty();    // if empty return 1(true), if not empty return 0(false)  检查stack是否是空的.
stackName.size();      // return the size of the stack. 显示stack的大小
				
Queue 队列（先进先出）
Queue更接近linked list. 同样需要头文件<queue>
queue<int> q;  // 定义一个queue
q.push(x);        // 将x接到队列的末端。
q.pop();          // 删除队列的第一个元素
q.front();         // 访问队首元素，即最早被压入队列的元素
q.back();         // 访问队尾元素，即最后被压入队列的元素
q.empty();       // 判断队列空，当队列空时，返回true
q.size();          // 访问队列中的元素个数

