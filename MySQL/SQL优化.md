[返回目录](./1.MySQL进阶.md)

# SQL优化

### 插入优化

1. insert 优化：批量插入
`insert into tb_text values (1,'tom'),(2,'cat'),...`

2. 手动提交事务：在多个命令完成后，执行commit
3. 主键顺序插入
4. 大量数据插入可以用load指令插入
```sql
# 客户端连接服务端时，加上参数 --local-infile
mysql --local-infile -u root -p
-- 然后设置全局local-infile为0
set global local_infile = 1;
# 执行load指令将准备好的数据，加载到表结构中。
load data local infile '/root/sql1.log' into table 'tb_test' fields terminated by ',' lines terminated by '\n';
```
### 插入数据
insert:批量插入、手动控制事务、主键顺序插入
大批量插入:load data local infile

### 主键优化
主键长度尽量短、顺序插入，AUTO INCREMENT

### order by优化
using index:直接通过索引返回数据，性能高
using filesort:需要将返回的结果在排序缓冲区排序

### group by优化
索引，多字段分组满足最左前缀法则

### limit优化
覆盖索引+子查询

### count优化
性能: count(字段) < count(主键 id) < count(1)≈ count(*)

### update优化
尽量根据主键/索引字段进行数据更新

